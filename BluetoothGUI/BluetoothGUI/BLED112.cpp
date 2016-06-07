#include "stdafx.h"
#include "BLED112.h"
#include <QApplication>

volatile HANDLE bled112;

BLED112::BLED112()
{
	bgapiRXBuffer = (unsigned char *)malloc(bgapiRXBufferSize = 32);	// initalize packet puffers 
	bgapiRXBufferPos = 0;
	packetMode = 1;

	// these are function pointers initalize to 0
	/*
	ble_rsp_system_reset = 0;
	ble_rsp_system_hello = 0;
	ble_rsp_system_address_get = 0;
	ble_rsp_system_reg_write = 0;
	ble_rsp_system_reg_read = 0;
	ble_rsp_system_get_counters = 0;
	ble_rsp_system_get_connections = 0;
	ble_rsp_system_read_memory = 0;
	ble_rsp_system_get_info = 0;
	ble_rsp_system_endpoint_tx = 0;
	ble_rsp_system_whitelist_append = 0;
	ble_rsp_system_whitelist_remove = 0;
	ble_rsp_system_whitelist_clear = 0;
	ble_rsp_system_endpoint_rx = 0;
	ble_rsp_system_endpoint_set_watermarks = 0;
	ble_rsp_flash_ps_defrag = 0;
	ble_rsp_flash_ps_dump = 0;
	ble_rsp_flash_ps_erase_all = 0;
	ble_rsp_flash_ps_save = 0;
	ble_rsp_flash_ps_load = 0;
	ble_rsp_flash_ps_erase = 0;
	ble_rsp_flash_erase_page = 0;
	ble_rsp_flash_write_data = 0;
	ble_rsp_flash_read_data = 0;
	ble_rsp_attributes_write = 0;
	ble_rsp_attributes_read = 0;
	ble_rsp_attributes_read_type = 0;
	ble_rsp_attributes_user_read_response = 0;
	ble_rsp_attributes_user_write_response = 0;
	ble_rsp_connection_disconnect = 0;
	ble_rsp_connection_get_rssi = 0;
	ble_rsp_connection_update = 0;
	ble_rsp_connection_version_update = 0;
	ble_rsp_connection_channel_map_get = 0;
	ble_rsp_connection_channel_map_set = 0;
	ble_rsp_connection_features_get = 0;
	ble_rsp_connection_get_status = 0;
	ble_rsp_connection_raw_tx = 0;
	ble_rsp_attclient_find_by_type_value = 0;
	ble_rsp_attclient_read_by_group_type = 0;
	ble_rsp_attclient_read_by_type = 0;
	ble_rsp_attclient_find_information = 0;
	ble_rsp_attclient_read_by_handle = 0;
	ble_rsp_attclient_attribute_write = 0;
	ble_rsp_attclient_write_command = 0;
	ble_rsp_attclient_indicate_confirm = 0;
	ble_rsp_attclient_read_long = 0;
	ble_rsp_attclient_prepare_write = 0;
	ble_rsp_attclient_execute_write = 0;
	ble_rsp_attclient_read_multiple = 0;
	ble_rsp_sm_encrypt_start = 0;
	ble_rsp_sm_set_bondable_mode = 0;
	ble_rsp_sm_delete_bonding = 0;
	ble_rsp_sm_set_parameters = 0;
	ble_rsp_sm_passkey_entry = 0;
	ble_rsp_sm_get_bonds = 0;
	ble_rsp_sm_set_oob_data = 0;
	ble_rsp_gap_set_privacy_flags = 0;
	ble_rsp_gap_set_mode = 0;
	ble_rsp_gap_discover = 0;
	ble_rsp_gap_connect_direct = 0;
	ble_rsp_gap_end_procedure = 0;
	ble_rsp_gap_connect_selective = 0;
	ble_rsp_gap_set_filtering = 0;
	ble_rsp_gap_set_scan_parameters = 0;
	ble_rsp_gap_set_adv_parameters = 0;
	ble_rsp_gap_set_adv_data = 0;
	ble_rsp_gap_set_directed_connectable_mode = 0;
	ble_rsp_hardware_io_port_config_irq = 0;
	ble_rsp_hardware_set_soft_timer = 0;
	ble_rsp_hardware_adc_read = 0;
	ble_rsp_hardware_io_port_config_direction = 0;
	ble_rsp_hardware_io_port_config_function = 0;
	ble_rsp_hardware_io_port_config_pull = 0;
	ble_rsp_hardware_io_port_write = 0;
	ble_rsp_hardware_io_port_read = 0;
	ble_rsp_hardware_spi_config = 0;
	ble_rsp_hardware_spi_transfer = 0;
	ble_rsp_hardware_i2c_read = 0;
	ble_rsp_hardware_i2c_write = 0;
	ble_rsp_hardware_set_txpower = 0;
	ble_rsp_hardware_timer_comparator = 0;
	ble_rsp_hardware_io_port_irq_enable = 0;
	ble_rsp_hardware_io_port_irq_direction = 0;
	ble_rsp_test_phy_tx = 0;
	ble_rsp_test_phy_rx = 0;
	ble_rsp_test_phy_end = 0;
	ble_rsp_test_phy_reset = 0;
	ble_rsp_test_get_channel_map = 0;
	ble_rsp_test_debug = 0;
	ble_rsp_test_channel_mode = 0;
	ble_rsp_dfu_reset = 0;
	ble_rsp_dfu_flash_set_address = 0;
	ble_rsp_dfu_flash_upload = 0;
	ble_rsp_dfu_flash_upload_finish = 0;
	ble_evt_system_boot = 0;
	ble_evt_system_debug = 0;
	ble_evt_system_endpoint_watermark_rx = 0;
	ble_evt_system_endpoint_watermark_tx = 0;
	ble_evt_system_script_failure = 0;
	ble_evt_system_no_license_key = 0;
	ble_evt_system_protocol_error = 0;
	ble_evt_flash_ps_key = 0;
	ble_evt_attributes_value = 0;
	ble_evt_attributes_user_read_request = 0;
	ble_evt_attributes_status = 0;
	ble_evt_connection_status = 0;
	ble_evt_connection_version_ind = 0;
	ble_evt_connection_feature_ind = 0;
	ble_evt_connection_raw_rx = 0;
	ble_evt_connection_disconnected = 0;
	ble_evt_attclient_indicated = 0;
	ble_evt_attclient_procedure_completed = 0;
	ble_evt_attclient_group_found = 0;
	ble_evt_attclient_attribute_found = 0;
	ble_evt_attclient_find_information_found = 0;
	ble_evt_attclient_attribute_value = 0;
	ble_evt_attclient_read_multiple_response = 0;
	ble_evt_sm_smp_data = 0;
	ble_evt_sm_bonding_fail = 0;
	ble_evt_sm_passkey_display = 0;
	ble_evt_sm_passkey_request = 0;
	ble_evt_sm_bond_status = 0;
	ble_evt_gap_scan_response = my_ble_evt_gap_scan_response;
	ble_evt_gap_mode_changed = 0;
	ble_evt_hardware_io_port_status = 0;
	ble_evt_hardware_soft_timer = 0;
	ble_evt_hardware_adc_result = 0;
	ble_evt_dfu_boot = 0;
	*/
	
}
BLED112::~BLED112()
{
	qDebug() << "Inside BLED112 delete";
}
void output(uint8 len1, uint8* data1, uint16 len2, uint8* data2)
{
	DWORD written;

	if (!WriteFile(bled112,
		data1,
		len1,
		&written,
		NULL
	))
	{
		qDebug() << "ERROR: Writing data: " << QString::number((int)GetLastError());
	}

	if (!WriteFile(bled112,
		data2,
		len2,
		&written,
		NULL
	))
	{
		qDebug() << "ERROR: Writing data: " << QString::number((int)GetLastError());
	}
} // end of output 

/* Connect signals and slots to the thread */
void BLED112::doSetup(QThread* cThread, const QSerialPortInfo& serial_port)
{
	// assign com port to open
	bled_port = serial_port;
	// once the Thread is started it will call backgroundTask()
	connect(cThread, SIGNAL(started()), this, SLOT(backgroundTask()));
}

void BLED112::backgroundTask()
{
	emit updateLOG("Inside background task");		// debug statment
	// first we need to open the com port bled112 is on
	if (!openCOM())
		stopThread();
	
} // end of backgroundTask

/* this method opens the com port and updates the UI thread
	the port is sent from the button_onClick() method inside bluetoothgui.cpp
	it was passed as an argument when the thread was constructed 
	returns true if succesful, false otherwise
	*/
bool BLED112::openCOM()
{
	if (bled_port.isBusy()) {
		emit updateLOG("Serial port is busy");		// debug statment
	}
	char str[80];
	snprintf(str, sizeof(str) - 1, "\\\\.\\%s",bled_port.portName().toStdString().c_str());
	bled112 = CreateFileA(str,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	if (bled112 == INVALID_HANDLE_VALUE)
		bled112_connected = false;
	else {
		bled112_connected = true;
		bglib_output = output;
	}
		
	
	//bled112.setPort(bled_port);
	//bled112.setBaudRate(QSerialPort::Baud9600);
	//bled112.setDataBits(QSerialPort::Data8);
	//bled112.setParity(QSerialPort::NoParity);
	//bled112.setStopBits(QSerialPort::OneStop);
	//bled112.setFlowControl(QSerialPort::NoFlowControl);

	//if (bled112.open(QIODevice::ReadWrite)) 
	//	bled112_connected = true;

	//else 
		//bled112_connected = false;

	// Update the UI thread
	emit connectBLED(bled112_connected);

	return bled112_connected;
} // end of openCOM

void BLED112::onDisconnect()
{
	bled112_connected = false;
	stopThread();
}
	/* SLOT that recieves scanBLE signal */
void BLED112::onScan() {
	ble_cmd_gap_discover(gap_discover_observation);	emit updateLOG("Listening for messages");
	while (bled112_connected) {
		qApp->processEvents();
		readMessage();
	}
		

}

int BLED112::readMessage() {
	
	DWORD rread;
	const struct ble_msg *apimsg;
	struct ble_header apihdr;
	unsigned char data[256];//enough for BLE

	if (!ReadFile(bled112,
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
		if (!ReadFile(bled112,
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
		qDebug() << "ERROR: Message not found: " << QString::number((int)apihdr.cls) << " " << QString::number((int)apihdr.command);
		return -1;
	}
	
	//apimsg->handler(data);
	handleResponse(apimsg, data);

	return 0;
}

void BLED112::closeSerial() {
	
		qDebug() << "Closing serial";
		CloseHandle(bled112);
}

void BLED112::stopThread() {
	// close the serial port
	closeSerial();

	// stop thread we are finished
	this->thread()->quit();
}


void BLED112::ble_evt_gap_scan_response(const struct ble_msg_gap_scan_response_evt_t *msg)
{
	QString address = "";
	QString length = QString::number(msg->data.len);
	int i;
	qDebug() << "Size of data is: " << length;
	for (i = 0; i < 6; i++) {
		address += QString::number(msg->sender.addr[5 - i], 16);
		if (i < 5)
			address += ":";
		qDebug() << QString::number(msg->sender.addr[5 - i]), i<5 ? ":" : "";
	}
	updateLOG(address);
	//qDebug() << "RSSI: " << QString::number(msg->rssi);
	for (i = 0; i < msg->data.len; i++) {

		//qDebug() << "Data: " << QString::number(msg->data.data[i]);
	}
		
		
} 

void BLED112::handleResponse(const struct ble_msg* msg, unsigned char* data) {
	switch (msg->msgType) {
	case 210:
		break;
	case 211:
		break;
	case 212:
		break;
	case 213:
		break;
	case 214:
		break;
	case 215:
		break;
	case 216:
		break;
	case 217: 
		break;
	case 218:
		break;
	case 219:
		break;
	case 220:
		break;
	case 221:
		break;
	case 222:
		break;
	case 223:
		break;
	case 224:
		break;
	case 225:
		break;
	case 226:
		break;
	case 227:
		break;
	case 228:
		break;
	case 229:
		break;
	case 230:
		break;
	case 231:
		break;
	case 232:
		break;
	case 233:
		break;
	case 234:
		break;
	case 235:
		break;
	case 236:
		break;
	case 237:
		break;
	case 238:
		// scan response
		ble_evt_gap_scan_response((const struct ble_msg_gap_scan_response_evt_t *)data);
		break;
	case 239:
		break;
	case 240:
		break;
	case 241:
		break;
	case 242:
		break;
	case 243:
		break;
	case 244:
		break;
	default:
		break;

	} // end of switch
} // end of handleResponse

int BLED112::parsePacket(unsigned char ch)
{
	if (bgapiRXBufferPos == bgapiRXBufferSize) {
		// expand RX buffer to prevent overflow
		bgapiRXBuffer = (unsigned char *)realloc(bgapiRXBuffer, bgapiRXBufferSize += 16);
	}

	/*
	BGAPI packet structure (as of 2012-11-07):
	Byte 0:
	[7] - 1 bit, Message Type (MT)         0 = Command/Response, 1 = Event
	[6:3] - 4 bits, Technology Type (TT)     0000 = Bluetooth 4.0 single mode, 0001 = Wi-Fi
	[2:0] - 3 bits, Length High (LH)         Payload length (high bits)
	Byte 1:     8 bits, Length Low (LL)          Payload length (low bits)
	Byte 2:     8 bits, Class ID (CID)           Command class ID
	Byte 3:     8 bits, Command ID (CMD)         Command ID
	Bytes 4-n:  0 - 2048 Bytes, Payload (PL)     Up to 2048 bytes of payload
	*/

	// check packet position 
	/*
	if (bgapiRXBufferPos == 0) {
		// beginning of packet, check for correct framing/expected byte(s)
		// BGAPI packet for Bluetooth Smart Single Mode must be either Command/Response (0x00) or Event (0x80)
		if ((ch & 0x78) == 0x00) {
			// store new character in RX buffer
			bgapiRXBuffer[bgapiRXBufferPos++] = ch;
		}
		else {
			return 1; // packet format error
		}
	}
	else {
		// middle of packet, assume we're okay
		bgapiRXBuffer[bgapiRXBufferPos++] = ch;
		if (bgapiRXBufferPos == 2) {
			// just received "Length Low" byte, so store expected packet length
			bgapiRXDataLen = ch + ((bgapiRXBuffer[0] & 0x03) << 8);
		}
		else if (bgapiRXBufferPos == bgapiRXDataLen + 4) {


			// reset RX packet buffer position to be ready for new packet
			bgapiRXBufferPos = 0;

			// check packet type
			if ((bgapiRXBuffer[0] & 0x80) == 0) {
				// 0x00 = Response packet

				// capture last response class/command bytes
				lastResponse[0] = bgapiRXBuffer[2];
				lastResponse[1] = bgapiRXBuffer[3];

				if (bgapiRXBuffer[2] == 0) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_system_hello((const struct ble_msg_system_hello_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_system_hello((const struct ble_msg_system_hello_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_system_address_get((const struct ble_msg_system_address_get_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_system_reg_write((const struct ble_msg_system_reg_write_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_system_reg_read((const struct ble_msg_system_reg_read_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 5) { ble_rsp_system_get_counters((const struct ble_msg_system_get_counters_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 6) { ble_rsp_system_get_connections((const struct ble_msg_system_get_connections_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 7) { ble_rsp_system_read_memory((const struct ble_msg_system_read_memory_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 8) { ble_rsp_system_get_info((const struct ble_msg_system_get_info_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 9) { ble_rsp_system_endpoint_tx((const struct ble_msg_system_endpoint_tx_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 10) { ble_rsp_system_whitelist_append((const struct ble_msg_system_whitelist_append_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 11) { ble_rsp_system_whitelist_remove((const struct ble_msg_system_whitelist_remove_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 12) { ble_rsp_system_whitelist_clear((const struct ble_msg_system_whitelist_clear_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 13) { ble_rsp_system_endpoint_rx((const struct ble_msg_system_endpoint_rx_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 14) { ble_rsp_system_endpoint_set_watermarks((const struct ble_msg_system_endpoint_set_watermarks_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 1) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_flash_ps_defrag((const struct ble_msg_flash_ps_defrag_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_flash_ps_dump((const struct ble_msg_flash_ps_dump_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_flash_ps_erase_all((const struct ble_msg_flash_ps_erase_all_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_flash_ps_save((const struct ble_msg_flash_ps_save_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_flash_ps_load((const struct ble_msg_flash_ps_load_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 5) { ble_rsp_flash_ps_erase((const struct ble_msg_flash_ps_erase_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 6) { ble_rsp_flash_erase_page((const struct ble_msg_flash_erase_page_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 7) { ble_rsp_flash_write_data((const struct ble_msg_flash_write_data_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 8) { ble_rsp_flash_read_data((const struct ble_msg_flash_read_data_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 2) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_attributes_write((const struct ble_msg_attributes_write_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_attributes_read((const struct ble_msg_attributes_read_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_attributes_read_type((const struct ble_msg_attributes_read_type_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_attributes_user_read_response((const struct ble_msg_attributes_user_read_response_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_attributes_user_write_response((const struct ble_msg_attributes_user_write_response_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 3) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_connection_disconnect((const struct ble_msg_connection_disconnect_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_connection_get_rssi((const struct ble_msg_connection_get_rssi_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_connection_update((const struct ble_msg_connection_update_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_connection_version_update((const struct ble_msg_connection_version_update_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_connection_channel_map_get((const struct ble_msg_connection_channel_map_get_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 5) { ble_rsp_connection_channel_map_set((const struct ble_msg_connection_channel_map_set_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 6) { ble_rsp_connection_features_get((const struct ble_msg_connection_features_get_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 7) { ble_rsp_connection_get_status((const struct ble_msg_connection_get_status_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 8) { ble_rsp_connection_raw_tx((const struct ble_msg_connection_raw_tx_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 4) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_attclient_find_by_type_value((const struct ble_msg_attclient_find_by_type_value_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_attclient_read_by_group_type((const struct ble_msg_attclient_read_by_group_type_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_attclient_read_by_type((const struct ble_msg_attclient_read_by_type_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_attclient_find_information((const struct ble_msg_attclient_find_information_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_attclient_read_by_handle((const struct ble_msg_attclient_read_by_handle_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 5) { ble_rsp_attclient_attribute_write((const struct ble_msg_attclient_attribute_write_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 6) { ble_rsp_attclient_write_command((const struct ble_msg_attclient_write_command_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 7) { ble_rsp_attclient_indicate_confirm((const struct ble_msg_attclient_indicate_confirm_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 8) { ble_rsp_attclient_read_long((const struct ble_msg_attclient_read_long_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 9) { ble_rsp_attclient_prepare_write((const struct ble_msg_attclient_prepare_write_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 10) { ble_rsp_attclient_execute_write((const struct ble_msg_attclient_execute_write_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 11) { ble_rsp_attclient_read_multiple((const struct ble_msg_attclient_read_multiple_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 5) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_sm_encrypt_start((const struct ble_msg_sm_encrypt_start_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_sm_set_bondable_mode((const struct ble_msg_sm_set_bondable_mode_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_sm_delete_bonding((const struct ble_msg_sm_delete_bonding_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_sm_set_parameters((const struct ble_msg_sm_set_parameters_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_sm_passkey_entry((const struct ble_msg_sm_passkey_entry_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 5) { ble_rsp_sm_get_bonds((const struct ble_msg_sm_get_bonds_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 6) { ble_rsp_sm_set_oob_data((const struct ble_msg_sm_set_oob_data_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 6) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_gap_set_privacy_flags((const struct ble_msg_gap_set_privacy_flags_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_gap_set_mode((const struct ble_msg_gap_set_mode_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_gap_discover((const struct ble_msg_gap_discover_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_gap_connect_direct((const struct ble_msg_gap_connect_direct_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_gap_end_procedure((const struct ble_msg_gap_end_procedure_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 5) { ble_rsp_gap_connect_selective((const struct ble_msg_gap_connect_selective_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 6) { ble_rsp_gap_set_filtering((const struct ble_msg_gap_set_filtering_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 7) { ble_rsp_gap_set_scan_parameters((const struct ble_msg_gap_set_scan_parameters_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 8) { ble_rsp_gap_set_adv_parameters((const struct ble_msg_gap_set_adv_parameters_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 9) { ble_rsp_gap_set_adv_data((const struct ble_msg_gap_set_adv_data_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 10) { ble_rsp_gap_set_directed_connectable_mode((const struct ble_msg_gap_set_directed_connectable_mode_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 7) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_hardware_io_port_config_irq((const struct ble_msg_hardware_io_port_config_irq_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_hardware_set_soft_timer((const struct ble_msg_hardware_set_soft_timer_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_hardware_adc_read((const struct ble_msg_hardware_adc_read_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_hardware_io_port_config_direction((const struct ble_msg_hardware_io_port_config_direction_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4) { ble_rsp_hardware_io_port_config_function((const struct ble_msg_hardware_io_port_config_function_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 5) { ble_rsp_hardware_io_port_config_pull((const struct ble_msg_hardware_io_port_config_pull_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 6) { ble_rsp_hardware_io_port_write((const struct ble_msg_hardware_io_port_write_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 7) { ble_rsp_hardware_io_port_read((const struct ble_msg_hardware_io_port_read_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 8) { ble_rsp_hardware_spi_config((const struct ble_msg_hardware_spi_config_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 9) { ble_rsp_hardware_spi_transfer((const struct ble_msg_hardware_spi_transfer_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 10) { ble_rsp_hardware_i2c_read((const struct ble_msg_hardware_i2c_read_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 11) { ble_rsp_hardware_i2c_write((const struct ble_msg_hardware_i2c_write_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 12) { ble_rsp_hardware_set_txpower((const struct ble_msg_hardware_set_txpower_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 13) { ble_rsp_hardware_timer_comparator((const struct ble_msg_hardware_timer_comparator_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 14) { ble_rsp_hardware_io_port_irq_enable((const struct ble_msg_hardware_io_port_irq_enable_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 15) { ble_rsp_hardware_io_port_irq_direction((const struct ble_msg_hardware_io_port_irq_direction_rsp_t *)(bgapiRXBuffer + 4)); }

				}
				else if (bgapiRXBuffer[2] == 8) {
					if (false) {}

					else if (bgapiRXBuffer[3] == 0) { ble_rsp_test_phy_tx((const struct ble_msg_test_phy_tx_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 1) { ble_rsp_test_phy_rx((const struct ble_msg_test_phy_rx_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 2) { ble_rsp_test_phy_end((const struct ble_msg_test_phy_end_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 3) { ble_rsp_test_phy_reset((const struct ble_msg_test_phy_reset_rsp_t *)(bgapiRXBuffer + 4)); }

					else if (bgapiRXBuffer[3] == 4)  ble_rsp_test_get_channel_map((const struct ble_msg_test_get_channel_map_rsp_t *)(bgapiRXBuffer + 4));
				}

				else if (bgapiRXBuffer[3] == 5) { ble_rsp_test_debug((const struct ble_msg_test_debug_rsp_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 6) { ble_rsp_test_channel_mode((const struct ble_msg_test_channel_mode_rsp_t *)(bgapiRXBuffer + 4)); }

			}
			else if (bgapiRXBuffer[2] == 9) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_rsp_dfu_reset((const struct ble_msg_dfu_reset_rsp_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_rsp_dfu_flash_set_address((const struct ble_msg_dfu_flash_set_address_rsp_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 2) { ble_rsp_dfu_flash_upload((const struct ble_msg_dfu_flash_upload_rsp_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 3) { ble_rsp_dfu_flash_upload_finish((const struct ble_msg_dfu_flash_upload_finish_rsp_t *)(bgapiRXBuffer + 4)); }
			}
		}
		else {
			// 0x80 = Event packet

			// capture last event class/command bytes
			lastEvent[0] = bgapiRXBuffer[2];
			lastEvent[1] = bgapiRXBuffer[3];

			if (bgapiRXBuffer[2] == 0) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_system_boot((const struct ble_msg_system_boot_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_evt_system_debug((const struct ble_msg_system_debug_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 2) { ble_evt_system_endpoint_watermark_rx((const struct ble_msg_system_endpoint_watermark_rx_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 3) { ble_evt_system_endpoint_watermark_tx((const struct ble_msg_system_endpoint_watermark_tx_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 4) { ble_evt_system_script_failure((const struct ble_msg_system_script_failure_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 5) { ble_evt_system_no_license_key((const struct ble_msg_system_no_license_key_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 6) { ble_evt_system_protocol_error((const struct ble_msg_system_protocol_error_evt_t *)(bgapiRXBuffer + 4)); }
			}
			else if (bgapiRXBuffer[2] == 1) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_flash_ps_key((const struct ble_msg_flash_ps_key_evt_t *)(bgapiRXBuffer + 4)); }
			}
			else if (bgapiRXBuffer[2] == 2) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_attributes_value((const struct ble_msg_attributes_value_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_evt_attributes_user_read_request((const struct ble_msg_attributes_user_read_request_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 2) { ble_evt_attributes_status((const struct ble_msg_attributes_status_evt_t *)(bgapiRXBuffer + 4)); }

			}
			else if (bgapiRXBuffer[2] == 3) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_connection_status((const struct ble_msg_connection_status_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_evt_connection_version_ind((const struct ble_msg_connection_version_ind_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 2) { ble_evt_connection_feature_ind((const struct ble_msg_connection_feature_ind_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 3) { ble_evt_connection_raw_rx((const struct ble_msg_connection_raw_rx_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 4) { ble_evt_connection_disconnected((const struct ble_msg_connection_disconnected_evt_t *)(bgapiRXBuffer + 4)); }

			}
			else if (bgapiRXBuffer[2] == 4) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_attclient_indicated((const struct ble_msg_attclient_indicated_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_evt_attclient_procedure_completed((const struct ble_msg_attclient_procedure_completed_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 2) { ble_evt_attclient_group_found((const struct ble_msg_attclient_group_found_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 3) { ble_evt_attclient_attribute_found((const struct ble_msg_attclient_attribute_found_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 4) { ble_evt_attclient_find_information_found((const struct ble_msg_attclient_find_information_found_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 5) { ble_evt_attclient_attribute_value((const struct ble_msg_attclient_attribute_value_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 6) { ble_evt_attclient_read_multiple_response((const struct ble_msg_attclient_read_multiple_response_evt_t *)(bgapiRXBuffer + 4)); }

			}
			else if (bgapiRXBuffer[2] == 5) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_sm_smp_data((const struct ble_msg_sm_smp_data_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_evt_sm_bonding_fail((const struct ble_msg_sm_bonding_fail_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 2) { ble_evt_sm_passkey_display((const struct ble_msg_sm_passkey_display_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 3) { ble_evt_sm_passkey_request((const struct ble_msg_sm_passkey_request_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 4) { ble_evt_sm_bond_status((const struct ble_msg_sm_bond_status_evt_t *)(bgapiRXBuffer + 4)); }

			}
			else if (bgapiRXBuffer[2] == 6) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_gap_scan_response((const struct ble_msg_gap_scan_response_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_evt_gap_mode_changed((const struct ble_msg_gap_mode_changed_evt_t *)(bgapiRXBuffer + 4)); }
			}
			else if (bgapiRXBuffer[2] == 7) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_hardware_io_port_status((const struct ble_msg_hardware_io_port_status_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 1) { ble_evt_hardware_soft_timer((const struct ble_msg_hardware_soft_timer_evt_t *)(bgapiRXBuffer + 4)); }

				else if (bgapiRXBuffer[3] == 2) { ble_evt_hardware_adc_result((const struct ble_msg_hardware_adc_result_evt_t *)(bgapiRXBuffer + 4)); }
			}
			else if (bgapiRXBuffer[2] == 8) {
				if (false) {}
			}
			else if (bgapiRXBuffer[2] == 9) {
				if (false) {}

				else if (bgapiRXBuffer[3] == 0) { ble_evt_dfu_boot((const struct ble_msg_dfu_boot_evt_t *)(bgapiRXBuffer + 4)); }
			}
		}
	
	} */
		
		return 0; // parsed successfully
		
	}
	
//	return 0; // parsed successfully
//} 


void BLED112::ble_rsp_system_reset(const void * nul)
{
}

void BLED112::ble_rsp_system_hello(const void * nul)
{
}

void BLED112::ble_rsp_system_address_get(const ble_msg_system_address_get_rsp_t * msg)
{
}

void BLED112::ble_rsp_system_reg_write(const ble_msg_system_reg_write_rsp_t * msg)
{
}

void BLED112::ble_rsp_system_reg_read(const ble_msg_system_reg_read_rsp_t * msg)
{
}

void BLED112::ble_rsp_system_get_counters(const ble_msg_system_get_counters_rsp_t * msg)
{
}

void BLED112::ble_rsp_system_get_connections(const ble_msg_system_get_connections_rsp_t * msg)
{
}
