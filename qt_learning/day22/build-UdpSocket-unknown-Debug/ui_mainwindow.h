/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actStart;
    QAction *actStop;
    QAction *actTextClear;
    QAction *actExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBindPort;
    QLabel *label_2;
    QComboBox *cmbTargetIP;
    QLabel *label_3;
    QSpinBox *spinTargetPort;
    QLineEdit *editMessage;
    QPushButton *btnSend;
    QPushButton *btnBroadcast;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(710, 471);
        actStart = new QAction(MainWindow);
        actStart->setObjectName("actStart");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/start.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon);
        actStop = new QAction(MainWindow);
        actStop->setObjectName("actStop");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/stop.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon1);
        actTextClear = new QAction(MainWindow);
        actTextClear->setObjectName("actTextClear");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/clear.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTextClear->setIcon(icon2);
        actExit = new QAction(MainWindow);
        actExit->setObjectName("actExit");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBindPort = new QSpinBox(centralwidget);
        spinBindPort->setObjectName("spinBindPort");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBindPort->sizePolicy().hasHeightForWidth());
        spinBindPort->setSizePolicy(sizePolicy);
        spinBindPort->setMinimum(3000);
        spinBindPort->setMaximum(9999);

        gridLayout->addWidget(spinBindPort, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        cmbTargetIP = new QComboBox(centralwidget);
        cmbTargetIP->setObjectName("cmbTargetIP");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbTargetIP->sizePolicy().hasHeightForWidth());
        cmbTargetIP->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cmbTargetIP, 0, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        spinTargetPort = new QSpinBox(centralwidget);
        spinTargetPort->setObjectName("spinTargetPort");
        sizePolicy.setHeightForWidth(spinTargetPort->sizePolicy().hasHeightForWidth());
        spinTargetPort->setSizePolicy(sizePolicy);
        spinTargetPort->setMinimum(3000);
        spinTargetPort->setMaximum(9999);

        gridLayout->addWidget(spinTargetPort, 0, 5, 1, 1);

        editMessage = new QLineEdit(centralwidget);
        editMessage->setObjectName("editMessage");

        gridLayout->addWidget(editMessage, 1, 0, 1, 4);

        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName("btnSend");

        gridLayout->addWidget(btnSend, 1, 4, 1, 1);

        btnBroadcast = new QPushButton(centralwidget);
        btnBroadcast->setObjectName("btnBroadcast");

        gridLayout->addWidget(btnBroadcast, 1, 5, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 2, 0, 1, 6);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actStart);
        toolBar->addAction(actStop);
        toolBar->addAction(actTextClear);
        toolBar->addSeparator();
        toolBar->addAction(actExit);

        retranslateUi(MainWindow);
        QObject::connect(actExit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actStart->setText(QCoreApplication::translate("MainWindow", "\347\273\221\345\256\232\347\253\257\345\217\243", nullptr));
        actStop->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\231\244\347\273\221\345\256\232", nullptr));
        actTextClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
        actExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\273\221\345\256\232\347\253\257\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        btnBroadcast->setText(QCoreApplication::translate("MainWindow", "\345\271\277\346\222\255\346\266\210\346\201\257", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
