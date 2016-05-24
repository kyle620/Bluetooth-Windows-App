/********************************************************************************
** Form generated from reading UI file 'bluetoothgui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTHGUI_H
#define UI_BLUETOOTHGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BluetoothGUIClass
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *input_comPort;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *button_connect;
    QPushButton *button_disconnet;
    QPushButton *button_scan;
    QTextBrowser *LOG;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BluetoothGUIClass)
    {
        if (BluetoothGUIClass->objectName().isEmpty())
            BluetoothGUIClass->setObjectName(QStringLiteral("BluetoothGUIClass"));
        BluetoothGUIClass->resize(776, 517);
        actionExit = new QAction(BluetoothGUIClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setCheckable(false);
        actionExit->setEnabled(true);
        centralWidget = new QWidget(BluetoothGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(16, 23, 51, 20));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 60, 201, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        input_comPort = new QLineEdit(horizontalLayoutWidget);
        input_comPort->setObjectName(QStringLiteral("input_comPort"));

        horizontalLayout->addWidget(input_comPort);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 140, 111, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        button_connect = new QPushButton(verticalLayoutWidget);
        button_connect->setObjectName(QStringLiteral("button_connect"));

        verticalLayout->addWidget(button_connect);

        button_disconnet = new QPushButton(verticalLayoutWidget);
        button_disconnet->setObjectName(QStringLiteral("button_disconnet"));

        verticalLayout->addWidget(button_disconnet);

        button_scan = new QPushButton(verticalLayoutWidget);
        button_scan->setObjectName(QStringLiteral("button_scan"));

        verticalLayout->addWidget(button_scan);

        LOG = new QTextBrowser(centralWidget);
        LOG->setObjectName(QStringLiteral("LOG"));
        LOG->setGeometry(QRect(0, 371, 781, 141));
        BluetoothGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BluetoothGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 776, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        BluetoothGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BluetoothGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BluetoothGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BluetoothGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BluetoothGUIClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(BluetoothGUIClass);
        QObject::connect(actionExit, SIGNAL(triggered()), BluetoothGUIClass, SLOT(close()));
        QObject::connect(button_connect, SIGNAL(clicked()), BluetoothGUIClass, SLOT(button_connectClicked()));
        QObject::connect(button_disconnet, SIGNAL(clicked()), BluetoothGUIClass, SLOT(button_disconnectClicked()));

        QMetaObject::connectSlotsByName(BluetoothGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *BluetoothGUIClass)
    {
        BluetoothGUIClass->setWindowTitle(QApplication::translate("BluetoothGUIClass", "BluetoothGUI", 0));
        actionExit->setText(QApplication::translate("BluetoothGUIClass", "Exit", 0));
        label->setText(QApplication::translate("BluetoothGUIClass", "Scan", 0));
        label_2->setText(QApplication::translate("BluetoothGUIClass", "Enter BLED112 COMPORT:", 0));
        button_connect->setText(QApplication::translate("BluetoothGUIClass", "Connect", 0));
        button_disconnet->setText(QApplication::translate("BluetoothGUIClass", "Disconnect", 0));
        button_scan->setText(QApplication::translate("BluetoothGUIClass", "Scan", 0));
        menuFile->setTitle(QApplication::translate("BluetoothGUIClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("BluetoothGUIClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class BluetoothGUIClass: public Ui_BluetoothGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHGUI_H
