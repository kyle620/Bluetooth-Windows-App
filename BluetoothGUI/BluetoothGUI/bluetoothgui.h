#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_bluetoothgui.h"
#include "BLED112.h"
#include <QSerialPort>				/* used for serial connection */
#include <QSerialPortInfo>			/* used for listing available serial ports */
#include <QThread>
#include <QVector>

class BluetoothGUI : public QMainWindow
{
	Q_OBJECT

public:
	BluetoothGUI(QWidget *parent = 0);
	~BluetoothGUI();

signals:
	void disconnect();										/* Emmitted when user clicks disconnect */
	void scanBLE();									// Emmited when user clicks scan

public slots:
	void button_connectClicked();						/* Handles when "Connect" is clicked */
	void button_disconnectClicked();					/* Handles when "Disconnect is clicked */
	void button_scanClicked();							// emits signal to BLE112 to start scanning for BLE devices
	void dropbox_serial_portList(int);				/* Handles when the dropdown is clicked */
	void onUpdateLOG(QString);				/* BLED112 sends signal to update log, this method receives the signal */
	void onConnect(bool);						/* BLED112 sends signal to update connetion, this method receives the signal */
	bool checkList(const QSerialPortInfo&);			// returns true if item is in the serialList vector

private:

	void setupConnections();

	Ui::BluetoothGUIClass ui;
	QVector<QSerialPortInfo> serialList;		// holds all the available serial ports
	BLED112* bled112;
	QThread* bledThread;
	bool bled_connectionSatus;					// True if connected, false otherwise
};

#endif // BLUETOOTHGUI_H
