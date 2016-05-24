#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_bluetoothgui.h"
#include "BLED112.h"

class BluetoothGUI : public QMainWindow
{
	Q_OBJECT

public:
	BluetoothGUI(QWidget *parent = 0);
	~BluetoothGUI();
	
	public slots:
		void button_connectClicked();						/* Handles when "Connect" is clicked */
		void button_disconnectClicked();					/* Handles when "Disconnect is clicked */
	
	bool openCOM(int portnumber);

private:
	Ui::BluetoothGUIClass ui;
	HANDLE bled112;			/* This is used to connect to the BLED112 usb device */
	BLE112 bled;			/* Object that holds the information about the BLED112 device */
};

#endif // BLUETOOTHGUI_H
