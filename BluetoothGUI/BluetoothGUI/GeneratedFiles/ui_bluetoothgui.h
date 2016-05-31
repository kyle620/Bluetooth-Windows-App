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
#include <QtWidgets/QComboBox>
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
    QLabel *label_scan;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *input_comPort;
    QComboBox *serial_portList;
    QPushButton *button_connect;
    QPushButton *button_disconnet;
    QPushButton *button_scan;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *log_label;
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
        BluetoothGUIClass->resize(778, 517);
        actionExit = new QAction(BluetoothGUIClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setCheckable(false);
        actionExit->setEnabled(true);
        centralWidget = new QWidget(BluetoothGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_scan = new QLabel(centralWidget);
        label_scan->setObjectName(QStringLiteral("label_scan"));
        label_scan->setGeometry(QRect(10, 50, 51, 20));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(570, 0, 201, 31));
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

        serial_portList = new QComboBox(centralWidget);
        serial_portList->setObjectName(QStringLiteral("serial_portList"));
        serial_portList->setGeometry(QRect(0, 0, 341, 22));
        button_connect = new QPushButton(centralWidget);
        button_connect->setObjectName(QStringLiteral("button_connect"));
        button_connect->setGeometry(QRect(350, 0, 109, 23));
        button_disconnet = new QPushButton(centralWidget);
        button_disconnet->setObjectName(QStringLiteral("button_disconnet"));
        button_disconnet->setGeometry(QRect(460, 0, 109, 23));
        button_disconnet->setStyleSheet(QStringLiteral(""));
        button_scan = new QPushButton(centralWidget);
        button_scan->setObjectName(QStringLiteral("button_scan"));
        button_scan->setGeometry(QRect(0, 80, 109, 23));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(210, 30, 541, 301));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 340, 761, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        log_label = new QLabel(layoutWidget);
        log_label->setObjectName(QStringLiteral("log_label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        log_label->setFont(font);
        log_label->setStyleSheet(QStringLiteral("background-color: rgb(129, 129, 129);"));

        verticalLayout_2->addWidget(log_label);

        LOG = new QTextBrowser(layoutWidget);
        LOG->setObjectName(QStringLiteral("LOG"));

        verticalLayout_2->addWidget(LOG);

        BluetoothGUIClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        label_scan->raise();
        horizontalLayoutWidget->raise();
        serial_portList->raise();
        button_connect->raise();
        button_disconnet->raise();
        button_scan->raise();
        textBrowser->raise();
        menuBar = new QMenuBar(BluetoothGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 778, 21));
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
        QObject::connect(serial_portList, SIGNAL(highlighted(int)), BluetoothGUIClass, SLOT(dropbox_serial_portList(int)));
        QObject::connect(button_scan, SIGNAL(clicked()), BluetoothGUIClass, SLOT(button_scanClicked()));

        QMetaObject::connectSlotsByName(BluetoothGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *BluetoothGUIClass)
    {
        BluetoothGUIClass->setWindowTitle(QApplication::translate("BluetoothGUIClass", "BluetoothGUI", 0));
        actionExit->setText(QApplication::translate("BluetoothGUIClass", "Exit", 0));
        label_scan->setText(QApplication::translate("BluetoothGUIClass", "Scan", 0));
        label_2->setText(QApplication::translate("BluetoothGUIClass", "Enter BLED112 COMPORT:", 0));
        serial_portList->clear();
        serial_portList->insertItems(0, QStringList()
         << QApplication::translate("BluetoothGUIClass", "Select a device", 0)
        );
        button_connect->setText(QApplication::translate("BluetoothGUIClass", "Attach", 0));
        button_disconnet->setText(QApplication::translate("BluetoothGUIClass", "Detatch", 0));
        button_scan->setText(QApplication::translate("BluetoothGUIClass", "Scan", 0));
        log_label->setText(QApplication::translate("BluetoothGUIClass", "Log", 0));
        menuFile->setTitle(QApplication::translate("BluetoothGUIClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("BluetoothGUIClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class BluetoothGUIClass: public Ui_BluetoothGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHGUI_H
