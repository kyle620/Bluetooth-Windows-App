#ifndef BLED112_H
#define BLED112_H
#include "stdafx.h"
#include "cmd_def.h"
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
   // HANDLE	bled112;
	bool bled112_connected;						// TRUE when bled112 is connected, FALSE otherwise
	int readMessage();							// Reads data from BLED112, returns 0 for success
	
};
Q_DECLARE_METATYPE(BLED112*)
#endif // BLED112_H
