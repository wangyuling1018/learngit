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
    QAction *actOpenDb;
    QAction *actInsert;
    QAction *actUpdate;
    QAction *actDelete;
    QAction *actExit;
    QWidget *centralwidget;
    QTableView *tableView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(646, 381);
        actOpenDb = new QAction(MainWindow);
        actOpenDb->setObjectName("actOpenDb");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpenDb->setIcon(icon);
        actInsert = new QAction(MainWindow);
        actInsert->setObjectName("actInsert");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/insert.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actInsert->setIcon(icon1);
        actUpdate = new QAction(MainWindow);
        actUpdate->setObjectName("actUpdate");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/edit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actUpdate->setIcon(icon2);
        actDelete = new QAction(MainWindow);
        actDelete->setObjectName("actDelete");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/delete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon3);
        actExit = new QAction(MainWindow);
        actExit->setObjectName("actExit");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 621, 311));
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actOpenDb);
        toolBar->addSeparator();
        toolBar->addAction(actInsert);
        toolBar->addAction(actUpdate);
        toolBar->addAction(actDelete);
        toolBar->addSeparator();
        toolBar->addAction(actExit);

        retranslateUi(MainWindow);
        QObject::connect(actExit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actOpenDb->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\225\260\346\215\256\345\272\223", nullptr));
        actInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\256\260\345\275\225", nullptr));
        actUpdate->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
        actDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        actExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
