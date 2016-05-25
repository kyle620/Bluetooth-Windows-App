#include "stdafx.h"
#include "bluetoothgui.h"
#include <QtCore>
#include <QString>
#include <QtGui>
using namespace std;


BluetoothGUI::BluetoothGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

BluetoothGUI::~BluetoothGUI()
{
	delete bled;
}

/* This method gets called any time the user presses the connect button */
void BluetoothGUI::button_connectClicked()
{

	QString input = ui.serial_portList->currentText();
	ui.LOG->setText("Current text is: " + input);
	if (input == "Select a device"){
		ui.LOG->append("User selsected 'Select a device'"); } // do nothing  Might add a  message to the user if this happens
	else {
		// now we need to open the COM port they selected
		for (QVector<QSerialPortInfo>::iterator it = serialList.begin(); it != serialList.end(); it++) {

			// format of the string should be "PortName: Description
			// i.e. COM12: Bluegigia
			if (input == (*it).portName() + ": " + (*it).description()) {
				if (openCOM(*it)) {
					ui.LOG->append("Success! opened: " + (*it).portName() + ": " + (*it).description());

					// need to create the BLED112 object and pass the serial port
					//bled = new BLE112(serial_bled112);
				}
				else {
					ui.LOG->append("Error: Could not open: " + (*it).portName() + ": " + (*it).description());
				}
				break;
			}
			
		}

	}
	/* OLD METHOD 
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
	*/
}

/* 
	This method is invoked when the user clicks the disconect button
	it will disconnect the BLED112 from the serial port
*/
void BluetoothGUI::button_disconnectClicked()
{
	try {
		serial_bled112->close();
		ui.LOG->append("Closed Serial port");
		ui.button_connect->setText("Attach");
		ui.button_connect->setStyleSheet("QPushButton#button_connect{background-color: light grey}");

	}catch(...){
		ui.LOG->append("Error in button_disconnectClicked(): Cannot close serial port");
	}
	/* OLD METHOD 
	// Check make sure that handle is valid, meaning it is open
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
	*/
}

/*
	This method will open up the serial port to talk to the BLED112
	it will return true if succesful otherwise false
*/
bool BluetoothGUI::openCOM(const QSerialPortInfo &info)
{
	ui.LOG->append("openCOM");

	serial_bled112->setPort(info);
	if ((*serial_bled112).open(QIODevice::ReadWrite)) {
		// if it is succesful tell the user by changing the button green
		ui.button_connect->setStyleSheet("QPushButton#button_connect{background-color: green}");
		ui.button_connect->setText("Attatched!");
		return true;
	}
	else {
		ui.button_connect->setStyleSheet("QPushButton#button_connect{background-color: red}");
		return false;
	}
	
	/* OLD METHOD 
	// Hard coded the port in for now for testing, will need to change 
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

	//  Check if an error occured and return false 
	if (bled112 == INVALID_HANDLE_VALUE) {
		return false;
	}
	return true;
	*/
}

void BluetoothGUI::dropbox_serial_portList(int a)
{
	// first allocate room in the vector, this will help efficiency becasue push_back is costly
	serialList.reserve(10);

	QVector<QSerialPortInfo>::iterator it;

	// Example use QSerialPortInfo
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
		if (!checkList(info)) {
			serialList.push_back(info);
			ui.serial_portList->addItem(info.portName() + ": " + info.description());
			qDebug() << "Name : " << info.portName();
			qDebug() << "Description : " << info.description();
			qDebug() << "Manufacturer: " << info.manufacturer();
		}
	}
}

	/* This method will check if a port is already in the list, it returns true if found */
bool BluetoothGUI::checkList(const QSerialPortInfo& elem)
{
	QVector<QSerialPortInfo>::iterator begin_ = serialList.begin();
	QVector<QSerialPortInfo>::iterator end_ = serialList.end();
	for (; begin_ != end_; begin_++) {
		if ((*begin_).portName() == elem.portName())
			return true;
	}

	return false;
}


