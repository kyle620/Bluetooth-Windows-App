#ifndef BLED112_H
#define BLED112_H
#include "stdafx.h"
#include "cmd_def.h"				/* used for BLE communication */
#include <QSerialPort>				/* used for serial connection */
#include <QSerialPortInfo>			/* used for listing available serial ports */
#include <QObject>
#include <QtCore>
#include <QThread>

class BLED112 : public QObject
{
	Q_OBJECT

public:
	BLED112();
	~BLED112();
	void doSetup(QThread* cThread, const QSerialPortInfo& serial_port);
	bool openCOM();
	void closeSerial();
	void stopThread();
	void my_ble_evt_gap_scan_response(const struct ble_msg_gap_scan_response_evt_t *msg);

	/* These are the methods that can pass data back to UI thread */
signals:
	void connectBLED(bool);
	void updateLOG(QString);

public slots:
void backgroundTask();
void onDisconnect();				// handles when user presses the disconect button, siganl is emiitted from BluetoothGUI
void onScan();


private:
	QSerialPortInfo bled_port;
	bool bled112_connected;						// TRUE when bled112 is connected, FALSE otherwise
	int readMessage();							// Reads data from BLED112, returns 0 for success
	ble_class_handler_t* event;
	
};
Q_DECLARE_METATYPE(BLED112*)
#endif // BLED112_H
