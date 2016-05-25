#ifndef BLE112_H
#define BLE112_H
#pragma once

#include "stdafx.h"
#include "cmd_def.h"
#include <qserialport.h>				/* used for serial connection */
#include <qserialportinfo.h>			/* used for listing available serial ports */

	/*! 
	
	This class will create an object that handles the bluetooth communication
	between the BLED112 and any remote device	
	
	*/

class BLE112
{

public:
	BLE112(QSerialPort * serial) :bled112(serial) { qDebug() << "BLE112 constructor called"; };
	~BLE112();

private:
	int comPort;
	QSerialPort *bled112;

};

#endif // !BLE112_H

