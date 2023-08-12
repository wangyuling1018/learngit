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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actSetSize;
    QAction *actSetHeader;
    QAction *actLocate;
    QAction *actExit;
    QWidget *centralwidget;
    QTableView *tableView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(594, 394);
        actSetSize = new QAction(MainWindow);
        actSetSize->setObjectName("actSetSize");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/row.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSetSize->setIcon(icon);
        actSetHeader = new QAction(MainWindow);
        actSetHeader->setObjectName("actSetHeader");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/header.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSetHeader->setIcon(icon1);
        actLocate = new QAction(MainWindow);
        actLocate->setObjectName("actLocate");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/locate.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actLocate->setIcon(icon2);
        actExit = new QAction(MainWindow);
        actExit->setObjectName("actExit");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 571, 311));
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actSetSize);
        toolBar->addAction(actSetHeader);
        toolBar->addAction(actLocate);
        toolBar->addSeparator();
        toolBar->addAction(actExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actSetSize->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\241\214\346\225\260\345\210\227\346\225\260", nullptr));
#if QT_CONFIG(tooltip)
        actSetSize->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\241\214\346\225\260\345\210\227\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        actSetHeader->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\241\250\345\244\264\346\240\207\351\242\230", nullptr));
        actLocate->setText(QCoreApplication::translate("MainWindow", "\345\256\232\344\275\215\345\215\225\345\205\203\346\240\274", nullptr));
#if QT_CONFIG(tooltip)
        actLocate->setToolTip(QCoreApplication::translate("MainWindow", "\345\256\232\344\275\215\345\215\225\345\205\203\346\240\274", nullptr));
#endif // QT_CONFIG(tooltip)
        actExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actExit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
