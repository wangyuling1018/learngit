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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpen;
    QAction *actSave;
    QAction *actAppend;
    QAction *actInsert;
    QAction *actDelete;
    QAction *actExit;
    QAction *actModelData;
    QAction *actAlignLeft;
    QAction *actAlignRight;
    QAction *actAlignCenter;
    QAction *actFontBold;
    QWidget *centralwidget;
    QSplitter *splitter;
    QTableView *tableView;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(604, 495);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName("actOpen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon);
        actSave = new QAction(MainWindow);
        actSave->setObjectName("actSave");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon1);
        actAppend = new QAction(MainWindow);
        actAppend->setObjectName("actAppend");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/append.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAppend->setIcon(icon2);
        actInsert = new QAction(MainWindow);
        actInsert->setObjectName("actInsert");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/insert.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actInsert->setIcon(icon3);
        actDelete = new QAction(MainWindow);
        actDelete->setObjectName("actDelete");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/delete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon4);
        actExit = new QAction(MainWindow);
        actExit->setObjectName("actExit");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon5);
        actModelData = new QAction(MainWindow);
        actModelData->setObjectName("actModelData");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/import.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actModelData->setIcon(icon6);
        actAlignLeft = new QAction(MainWindow);
        actAlignLeft->setObjectName("actAlignLeft");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/alignleft.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignLeft->setIcon(icon7);
        actAlignRight = new QAction(MainWindow);
        actAlignRight->setObjectName("actAlignRight");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/alignright.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignRight->setIcon(icon8);
        actAlignCenter = new QAction(MainWindow);
        actAlignCenter->setObjectName("actAlignCenter");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/aligncenter.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignCenter->setIcon(icon9);
        actFontBold = new QAction(MainWindow);
        actFontBold->setObjectName("actFontBold");
        actFontBold->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/bld.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFontBold->setIcon(icon10);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(20, 10, 571, 391));
        splitter->setOrientation(Qt::Horizontal);
        tableView = new QTableView(splitter);
        tableView->setObjectName("tableView");
        splitter->addWidget(tableView);
        plainTextEdit = new QPlainTextEdit(splitter);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        splitter->addWidget(plainTextEdit);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actOpen);
        toolBar->addAction(actSave);
        toolBar->addAction(actModelData);
        toolBar->addSeparator();
        toolBar->addAction(actAppend);
        toolBar->addAction(actInsert);
        toolBar->addAction(actDelete);
        toolBar->addSeparator();
        toolBar->addAction(actAlignLeft);
        toolBar->addAction(actAlignRight);
        toolBar->addAction(actAlignCenter);
        toolBar->addAction(actFontBold);
        toolBar->addSeparator();
        toolBar->addAction(actExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actSave->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actSave->setToolTip(QCoreApplication::translate("MainWindow", "\350\241\250\346\240\274\345\206\205\345\256\271\345\217\246\345\255\230\344\270\272\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actAppend->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        actAppend->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\200\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        actInsert->setToolTip(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\344\270\200\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        actDelete->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actModelData->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\236\213\346\225\260\346\215\256\351\242\204\350\247\210", nullptr));
#if QT_CONFIG(tooltip)
        actModelData->setToolTip(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\250\241\345\236\213\346\230\276\347\244\272\345\210\260\346\226\207\346\234\254\346\241\206\351\207\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actAlignLeft->setText(QCoreApplication::translate("MainWindow", "\345\261\205\345\267\246", nullptr));
#if QT_CONFIG(tooltip)
        actAlignLeft->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\345\267\246\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actAlignRight->setText(QCoreApplication::translate("MainWindow", "\345\261\205\345\217\263", nullptr));
#if QT_CONFIG(tooltip)
        actAlignRight->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\345\217\263\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actAlignCenter->setText(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255", nullptr));
#if QT_CONFIG(tooltip)
        actAlignCenter->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\345\211\247\344\270\255\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actFontBold->setText(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actFontBold->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223\345\255\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
