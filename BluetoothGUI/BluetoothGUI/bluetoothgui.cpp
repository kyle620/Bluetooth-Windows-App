#include "stdafx.h"
#include "bluetoothgui.h"
#include <QtCore>
#include <QtGui>
#include <ostream>	/* used for ostringstream to convert DWORD to a string */
using std::ostringstream;

BluetoothGUI::BluetoothGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

BluetoothGUI::~BluetoothGUI()
{

}

/* This method gets called any time the user presses the connect button */
void BluetoothGUI::button_connectClicked()
{
	// Display to Log window for debugging purposes
	ui.LOG->setText("Inside button_connectClicked()");

	// Grab user input,  QString needs to be conveerted
	if (openCOM(ui.input_comPort->text().toInt())) {
		ui.LOG->append("Connected!");
	}
	else {
		ui.LOG->append("Error: Coulnd not connect");
	}

	bled = BLE112(ui.input_comPort->text().toInt());

}

/* 
	This method is invoked when the user clicks the disconect button
	it will disconnect the BLED112 from the serial port
*/
void BluetoothGUI::button_disconnectClicked()
{
	/* Check make sure that handle is valid, meaning it is open */
	if (bled112 != INVALID_HANDLE_VALUE) {
		// need to close the handle
		if (CloseHandle(bled112)) {
			ui.LOG->setText("Success!");
		}
		else {
			// log the error that occured *** Need to use QString::number() to convert the DWORD returned byt GetLastError()
			ui.LOG->setText(QString::number(GetLastError()));
		}
	}
}

/*
	This method will open up the serial port to talk to the BLED112
	it will return true if succesful otherwise false
*/
bool BluetoothGUI::openCOM(int portnumber)
{
	ui.LOG->append("openCOM");
	
	
	/* Hard coded the port in for now for testing, will need to change */
	char str[80];
	int port = 12;
	snprintf(str, sizeof(str) - 1, "\\\\.\\COM%d", port);
	bled112 = CreateFileA(str,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	/* Check if an error occured and return false */
	if (bled112 == INVALID_HANDLE_VALUE) {
		return false;
	}
	return true;
}


