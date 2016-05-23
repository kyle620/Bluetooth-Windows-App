//
// Bluegiga’s Bluetooth Smart Demo Application
// Contact: support@bluegiga.com.
//
// This is free software distributed under the terms of the MIT license reproduced below.
//
// Copyright (c) 2012, Bluegiga Technologies
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include "cmd_def.h"


using std::cin;
using std::cout;
using std::vector;

#define FIRST_HANDLE 0x0001
#define LAST_HANDLE 0xffff

/* Keep track of all found devices */
#define MAX_DEVICES 64
int found_devices_count = 0;
bd_addr found_devices[MAX_DEVICES];
bd_addr connect_addr;
vector<uint16> uuidVector;


uint8 primary_service_uuid[] = { 0x00, 0x28 };


enum actions {
	action_none,
	action_scan,
	action_connect,
	action_info,
};
enum actions action = action_none;

typedef enum {
	state_disconnected,
	state_connecting,
	state_connected,
	state_finding_services,
	state_finding_attributes,
	state_listening_measurements,
	state_finish,
	state_last
} states;
states state = state_disconnected;

void change_state(states new_state)
{
#ifdef DEBUG
	printf("DEBUG: State changed: %s --> %s\n", state_names[state], state_names[new_state]);
#endif
	state = new_state;
}

/* This method will be called anytime a successful connection to a remote device has been made */
void ble_evt_connection_status(const struct ble_msg_connection_status_evt_t *msg)
{
	// New connection
	if (msg->flags & connection_connected) {
		change_state(state_connected);
		printf("Connected\n");
		// Find primary services
		change_state(state_finding_services);
		ble_cmd_attclient_read_by_group_type(msg->connection, FIRST_HANDLE, LAST_HANDLE, 2, primary_service_uuid);
		
	}

	else {
		printf("Not connected,\t scanning:\n");
	}
}
/* This event is produced when an attribe group (service) is found */
void ble_evt_attclient_group_found(const struct ble_msg_attclient_group_found_evt_t *msg)
{
	if (msg->uuid.len == 0) return;
	uint16 uuid = (msg->uuid.data[1] << 8) | msg->uuid.data[0];
	printf("Found: %02x\n", uuid);
	uuidVector.push_back(uuid);

}

/* This method is called after the GROUP FOUND event has finished*/
void ble_evt_attclient_procedure_completed(const struct ble_msg_attclient_procedure_completed_evt_t *msg)
{

	// check if we have an error
	if (msg->result != 0) {
		printf("Error occured: Operation was not succesful\n");
	}
	if (state == state_finding_services) {
		change_state(state_finding_attributes);

		printf("Operation Succesful!\n");
		for (vector<uint16>::iterator it = uuidVector.begin(); it != uuidVector.end(); it++) {
			printf("%02x ,", *it);
		}
		printf("\n");

		ble_cmd_attclient_find_information(msg->connection, FIRST_HANDLE, LAST_HANDLE);
	}
	else if (state == state_finding_attributes) {
		change_state(state_listening_measurements);
	}
	else {

	}	
}

void ble_evt_attclient_find_information_found(const struct ble_msg_attclient_find_information_found_evt_t *msg)
{
	if (msg->uuid.len == 2) {
		uint16 uuid = (msg->uuid.data[1] << 8) | msg->uuid.data[0];
		printf("Inside information_found: %02x\n", uuid);
	}

	change_state(state_finish);
}


/* print method to print out the address */
void print_bdaddr(bd_addr bdaddr)
{
	printf("%02x:%02x:%02x:%02x:%02x:%02x",
		bdaddr.addr[5],
		bdaddr.addr[4],
		bdaddr.addr[3],
		bdaddr.addr[2],
		bdaddr.addr[1],
		bdaddr.addr[0]);
}
/**
* Compare Bluetooth addresses
*
* @param first First address
* @param second Second address
* @return Zero if addresses are equal
*/
int cmp_bdaddr(bd_addr first, bd_addr second)
{
	int i;
	for (i = 0; i < sizeof(bd_addr); i++) {
		if (first.addr[i] != second.addr[i]) return 1;
		//print_bdaddr(second);
	}
	return 0;
}


volatile HANDLE serial_handle;

void output(uint8 len1, uint8* data1, uint16 len2, uint8* data2)
{
	DWORD written;

	if (!WriteFile(serial_handle,
		data1,
		len1,
		&written,
		NULL
	))
	{
		printf("ERROR: Writing data. %d\n", (int)GetLastError());
		exit(-1);
	}

	if (!WriteFile(serial_handle,
		data2,
		len2,
		&written,
		NULL
	))
	{
		printf("ERROR: Writing data. %d\n", (int)GetLastError());
		exit(-1);
	}
}
int read_message()
{
	DWORD rread;
	const struct ble_msg *apimsg;
	struct ble_header apihdr;
	unsigned char data[256];//enough for BLE
							//read header

	if (!ReadFile(serial_handle,
		(unsigned char*)&apihdr,
		4,
		&rread,
		NULL))
	{
		return GetLastError();
	}
	if (!rread)return 0;
	//read rest if needed
	if (apihdr.lolen)
	{
		if (!ReadFile(serial_handle,
			data,
			apihdr.lolen,
			&rread,
			NULL))
		{
			return GetLastError();
		}
	}
	apimsg = ble_get_msg_hdr(apihdr);
	if (!apimsg)
	{
		printf("ERROR: Message not found:%d:%d\n", (int)apihdr.cls, (int)apihdr.command);
		return -1;
	}
	apimsg->handler(data);

	return 0;
}

void print_help()
{
	printf("Demo application to scan devices\n");
	printf("\tscan_example\tCOM-port\n");
}
void ble_evt_gap_scan_response(const struct ble_msg_gap_scan_response_evt_t *msg)
{
	//if (found_devices_count >= MAX_DEVICES) change_state(state_finish);

	int i;
	char *name = NULL;

	// Check if this device already found
	for (i = 0; i < found_devices_count; i++) {
		if (!cmp_bdaddr(msg->sender, found_devices[i])) return;
	}
	found_devices_count++;
	memcpy(found_devices[i].addr, msg->sender.addr, sizeof(bd_addr));

	// Parse data
	for (i = 0; i < msg->data.len; ) {
		int8 len = msg->data.data[i++];
		if (!len) continue;
		if (i + len > msg->data.len) break; // not enough data
		uint8 type = msg->data.data[i++];
		switch (type) {
		case 0x09:
			name = static_cast<char*>(malloc(len));
			memcpy(name, msg->data.data + i, len - 1);
			name[len - 1] = '\0';
		}

		i += len - 1;
	}

	print_bdaddr(msg->sender);
	printf(" RSSI:%u", msg->rssi);

	printf(" Name:");
	if (name) printf("%s", name);
	else printf("Unknown");
	printf("\n");

	free(name);

	/* Print the advertisment data */
	if (msg->packet_type == 0x00) {
		for (int i = 0; i < msg->data.len; i++) printf("%d ,", msg->data.data[i]);
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	uuidVector.reserve(50);

	action = action_scan;

	/* this is the sending address of the remote device i want to connect to
		the order of the bytes matter 
		EXAMPLE: connect to: 00:07:80:33:d7:cf 
								
	*/
	connect_addr.addr[5] = 0x00;
	connect_addr.addr[4] = 0x07;	
	connect_addr.addr[3] = 0x80;
	connect_addr.addr[2] = 0x33;
	connect_addr.addr[1] = 0xd7;
	connect_addr.addr[0] = 0xcf;

	// used to hold user input
	int input;
	/* First we need to ask user to input the com port the BLED112 is connected to */
	printf("Please enter the COM Port number the BLED112 was assigned\n");
	printf("If you do not know the port number, look in the Device Manager window under COM ports\n");
	cin >> input;
	char str[80];
	int port = 12;	// hard coded, will have to edit and change to the com port bled112 is assgined

	/*if (argc<2)
	{
		print_help();
		exit(-1);
	}*/
	snprintf(str, sizeof(str) - 1, "\\\\.\\COM%d", port);
	serial_handle = CreateFileA(str,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);


	if (serial_handle == INVALID_HANDLE_VALUE)
	{
		printf("Error opening serialport %s. %d\n", argv[1], (int)GetLastError());
		return -1;
	}

	bglib_output = output;


	//stop previous operation
	ble_cmd_gap_end_procedure();
	//get connection status,current command will be handled in response
	ble_cmd_connection_get_status(0);


	while (1)
	{
		//if (action == action_scan) {
			if (read_message())
			{
				printf("Error reading message\n");
				break;
			}
	//	}
		
	// Execute action
	if (action == action_scan) {
		ble_cmd_gap_discover(gap_discover_observation);
	}
	else if (action == action_info) {
		ble_cmd_system_get_info();
	}
	else if (state != state_connected) {
		//printf("Trying to connect\n");
		change_state(state_connecting);
		ble_cmd_gap_connect_direct(&connect_addr, gap_address_type_public, 40, 60, 100, 0);
	}

	/* check if the device we want to connect to exists */
	if (action != action_connect) {
		for (int i = 0; i < found_devices_count; i++) {
			if (cmp_bdaddr(found_devices[i], connect_addr)) action = action_connect;
		}
	}
	 
}

	return 0;
}

