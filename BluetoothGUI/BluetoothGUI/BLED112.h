#ifndef BLE112_H
#define BLE112_H
#pragma once

#include "stdafx.h"
#include "cmd_def.h"

	/*! 
	
	This class will create an object that handles the bluetooth communication
	between the BLED112 and any remote device	
	
	*/

class BLE112
{

public:
	BLE112(int port = 12) :comPort(port) { qDebug() << "BLE112 constructor called"; };
	~BLE112();

private:
	int comPort;

};

#endif // !BLE112_H

