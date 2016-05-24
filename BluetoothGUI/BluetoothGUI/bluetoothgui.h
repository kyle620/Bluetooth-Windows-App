#ifndef BLUETOOTHGUI_H
#define BLUETOOTHGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_bluetoothgui.h"

class BluetoothGUI : public QMainWindow
{
	Q_OBJECT

public:
	BluetoothGUI(QWidget *parent = 0);
	~BluetoothGUI();

private:
	Ui::BluetoothGUIClass ui;
};

#endif // BLUETOOTHGUI_H
