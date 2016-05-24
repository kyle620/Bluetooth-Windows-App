#include "stdafx.h"
#include "bluetoothgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BluetoothGUI w;
	w.show();
	return a.exec();
}
