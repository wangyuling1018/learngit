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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actFontBold;
    QAction *actFontItalic;
    QAction *actFontUnderline;
    QAction *actClose;
    QAction *actOpen;
    QAction *actClear;
    QAction *actToolbarLab;
    QAction *actNew;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuFormat;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(933, 577);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AppIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actCut = new QAction(MainWindow);
        actCut->setObjectName("actCut");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cut.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon1);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName("actCopy");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/copy.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon2);
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName("actPaste");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/paste.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon3);
        actFontBold = new QAction(MainWindow);
        actFontBold->setObjectName("actFontBold");
        actFontBold->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/bld.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFontBold->setIcon(icon4);
        actFontItalic = new QAction(MainWindow);
        actFontItalic->setObjectName("actFontItalic");
        actFontItalic->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/itl.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFontItalic->setIcon(icon5);
        actFontUnderline = new QAction(MainWindow);
        actFontUnderline->setObjectName("actFontUnderline");
        actFontUnderline->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/under.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFontUnderline->setIcon(icon6);
        actClose = new QAction(MainWindow);
        actClose->setObjectName("actClose");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon7);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName("actOpen");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon8);
        actClear = new QAction(MainWindow);
        actClear->setObjectName("actClear");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/clear.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon9);
        actToolbarLab = new QAction(MainWindow);
        actToolbarLab->setObjectName("actToolbarLab");
        actToolbarLab->setCheckable(true);
        actNew = new QAction(MainWindow);
        actNew->setObjectName("actNew");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/new.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actNew->setIcon(icon10);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 933, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName("menuFormat");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuFormat->menuAction());
        menuFile->addAction(actNew);
        menuFile->addAction(actOpen);
        menuFile->addSeparator();
        menuFile->addAction(actClose);
        menuEdit->addAction(actCut);
        menuEdit->addAction(actCopy);
        menuEdit->addAction(actPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actClear);
        menuFormat->addAction(actFontBold);
        menuFormat->addAction(actFontItalic);
        menuFormat->addAction(actFontUnderline);
        menuFormat->addSeparator();
        menuFormat->addAction(actToolbarLab);
        toolBar->addAction(actNew);
        toolBar->addAction(actOpen);
        toolBar->addAction(actClear);
        toolBar->addSeparator();
        toolBar->addAction(actCut);
        toolBar->addAction(actCopy);
        toolBar->addAction(actPaste);
        toolBar->addSeparator();
        toolBar->addAction(actFontBold);
        toolBar->addAction(actFontItalic);
        toolBar->addAction(actFontUnderline);

        retranslateUi(MainWindow);
        QObject::connect(actCut, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::cut));
        QObject::connect(actPaste, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::paste));
        QObject::connect(actCopy, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::copy));
        QObject::connect(actClear, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::clear));
        QObject::connect(actClose, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\267\267\345\220\210UI\350\256\276\350\256\241", nullptr));
        actCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        actCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        actCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        actPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actFontBold->setText(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
        actFontItalic->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
        actFontUnderline->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
        actClose->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
#if QT_CONFIG(tooltip)
        actClear->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actToolbarLab->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217\346\226\207\345\255\227\346\240\207\347\255\276", nullptr));
        actNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(shortcut)
        actNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menuFormat->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
