#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_bluetoothgui.h"
#include "BLED112.h"
#include <qserialport.h>				/* used for serial connection */
#include <qserialportinfo.h>			/* used for listing available serial ports */
#include <QVector>

class BluetoothGUI : public QMainWindow
{
	Q_OBJECT

public:
	BluetoothGUI(QWidget *parent = 0);
	~BluetoothGUI();
	
	public slots:
		void button_connectClicked();						/* Handles when "Connect" is clicked */
		void button_disconnectClicked();					/* Handles when "Disconnect is clicked */
		void dropbox_serial_portList(int a);				/* Handles when the dropdown is clicked */
	
		
	bool openCOM(const QSerialPortInfo &info);				// opens comport of selected device
	bool checkList(const QSerialPortInfo& elem);			// returns true if item is in the serialList vector

private:
	Ui::BluetoothGUIClass ui;
	HANDLE bled112;				/* This is used to connect to the BLED112 usb device */
	QSerialPort *serial_bled112;	/* Used to connect to BLED112 usb device */
	BLE112 *bled;				/* Object that holds the information about the BLED112 device */
	QVector<QSerialPortInfo> serialList;		// holds all the available serial ports
};

#endif // BLUETOOTHGUI_H
