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
    QComboBox *cmbIP;
    QLabel *label_2;
    QSpinBox *spinPort;
    QPushButton *btnSend;
    QLineEdit *editMessage;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(527, 458);
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

        cmbIP = new QComboBox(centralwidget);
        cmbIP->setObjectName("cmbIP");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbIP->sizePolicy().hasHeightForWidth());
        cmbIP->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cmbIP, 0, 1, 2, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 2);

        spinPort = new QSpinBox(centralwidget);
        spinPort->setObjectName("spinPort");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinPort->sizePolicy().hasHeightForWidth());
        spinPort->setSizePolicy(sizePolicy1);
        spinPort->setMinimum(3000);
        spinPort->setMaximum(9999);

        gridLayout->addWidget(spinPort, 0, 4, 1, 1);

        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName("btnSend");

        gridLayout->addWidget(btnSend, 1, 3, 2, 2);

        editMessage = new QLineEdit(centralwidget);
        editMessage->setObjectName("editMessage");

        gridLayout->addWidget(editMessage, 2, 0, 1, 3);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 3, 0, 1, 5);

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
        actStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        actStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
        actTextClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
        actExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\233\221\345\220\254\345\234\260\345\235\200", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
