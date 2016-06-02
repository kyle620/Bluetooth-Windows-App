#include "stdafx.h"
#include "bluetoothgui.h"
#include <QtCore>
#include <QString>
#include <QtGui>
using std::find;
using namespace Qt;


BluetoothGUI::BluetoothGUI(QWidget *parent)
	: QMainWindow(parent),bled_connectionSatus(false)
{
	ui.setupUi(this);
}

BluetoothGUI::~BluetoothGUI()
{
	
}

/* This method gets called any time the user presses the connect button */
void BluetoothGUI::button_connectClicked()
{

	QString input = ui.serial_portList->currentText();
	ui.LOG->setText("Current text is: " + input);
	if (input == "Select a device"){
		ui.LOG->append("User selsected 'Select a device'");  // do nothing, user did not select device Might add a  message to the user if this happens
	}
	else {
		// check if we alreay are connected
		if (!bled_connectionSatus) {
			// not conbected, need to open COM port user selected
			for (QVector<QSerialPortInfo>::iterator it = serialList.begin(); it != serialList.end(); it++) {

				// format of the string should be "PortName: Description
				// i.e. COM12: Bluegigia
				if (input == (*it).portName() + ": " + (*it).description()) {
					bled112 = new BLED112();
					bledThread = new QThread();

					setupConnections();					// this method will setup the signals and slots used to connect the threads 

					bled112->doSetup(bledThread, *it);		// setup the values inside bled112 object
					bled112->moveToThread(bledThread);		// move object to run in the thread
					bledThread->start();						// begin thread

					break;
				}
			} // end of for loop
		}
		else {
			ui.LOG->append("Already connected!");
		}
		
		
	} // end of else

} // end of button_connectClicked()

/* 
	This method is invoked when the user clicks the disconect button
	it will disconnect the BLED112 from the serial port
*/
void BluetoothGUI::button_disconnectClicked()
{
	// check make sure we have a connection to close
	if (bled_connectionSatus) {
		// connected to a device need to close
		ui.button_connect->setText("Attach");
		ui.button_connect->setStyleSheet("QPushButton#button_connect{background-color: light grey}");

		// update background thread
		emit disconnect();
		bled_connectionSatus = false;
		
		while (!bledThread->isFinished()) {
			qDebug() << "Thread still running";
		}
		// delete pointers
		delete bled112;
		delete bledThread;

	}
	else ui.LOG->append("Not connected to a device");
	
}

void BluetoothGUI::button_scanClicked() {
	// first make sure that we are connected to a BLED112 device
	if (!bled_connectionSatus)
		ui.LOG->append("Unavailable to scan, please connect to a device first");
	else {
		ui.LOG->append("Unavailable to scan, please connect to a device first");
		emit scanBLE();
	}
	
}

	
/* This method is used to accept the signal from the BLED112 running in background
	when the LOG UI element needs updated this function handles it */
void BluetoothGUI::onUpdateLOG(QString msg)
{
	ui.LOG->append("BLED112 Thread: " + msg);
}

/* This is the slot used to accept the signal from the BLED112 running in background
it gets called when emit(signal, onConnect(arg)) is called from the
background thread */
void BluetoothGUI::onConnect(bool status)
{
	if (status) {
		// true 
		bled_connectionSatus = true;
		 
		// tell the user by setting the background color to green, and change text to say attatched
		ui.button_connect->setStyleSheet("QPushButton#button_connect{background-color: green}");
		ui.button_connect->setText("Attatched!");
	}
	else {
		// could not connect to device tell user
		ui.button_connect->setStyleSheet("QPushButton#button_connect{background-color: red}");
		ui.button_connect->setText("Retry!");

		while (!bledThread->isFinished()) {
			qDebug() << "Thread still running";
		}
		// delete pointers
		delete bled112;
		delete bledThread;
	}
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


/* This method will setup the signals and slots between the main UI thread and background thread */
void BluetoothGUI::setupConnections()
{
	ui.LOG->append("Inside setupConnections");
	// setup the signals to listen for from BLE112 object
	connect(bled112, SIGNAL(connectBLED(bool)), this, SLOT(onConnect(bool)));								// signal emitted when opening serial port, response handled by BluetoothGUI in onConnect
	connect(this, SIGNAL(disconnect()), bled112, SLOT(onDisconnect()));					// signnal emitted when usere presses disonnect, response handled by BLED112 in onDisconcet
	connect(bled112, SIGNAL(updateLOG(QString)), this, SLOT(onUpdateLOG(QString)));
	connect(this, SIGNAL(scanBLE()), bled112, SLOT(onScan()));
}


