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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actListInit;
    QAction *actListClear;
    QAction *actItemInsert;
    QAction *actItemAppend;
    QAction *actItemDelete;
    QAction *actSelAll;
    QAction *actSelNone;
    QAction *actSellnvs;
    QAction *actExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QToolButton *tBtnListInit;
    QToolButton *tBtnListClear;
    QToolButton *tBtnListInsert;
    QToolButton *tBtnListAppend;
    QToolButton *tBtnListDelete;
    QWidget *page_2;
    QWidget *page_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editCurItem;
    QCheckBox *ckbEditable;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tBtnSelAll;
    QToolButton *tBtnSelNone;
    QToolButton *tBtnSelInvs;
    QListWidget *listWidget;
    QWidget *tab_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(616, 463);
        actListInit = new QAction(MainWindow);
        actListInit->setObjectName("actListInit");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/init.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListInit->setIcon(icon);
        actListClear = new QAction(MainWindow);
        actListClear->setObjectName("actListClear");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/clear.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListClear->setIcon(icon1);
        actItemInsert = new QAction(MainWindow);
        actItemInsert->setObjectName("actItemInsert");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/insert.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actItemInsert->setIcon(icon2);
        actItemAppend = new QAction(MainWindow);
        actItemAppend->setObjectName("actItemAppend");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/append.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actItemAppend->setIcon(icon3);
        actItemDelete = new QAction(MainWindow);
        actItemDelete->setObjectName("actItemDelete");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/delete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actItemDelete->setIcon(icon4);
        actSelAll = new QAction(MainWindow);
        actSelAll->setObjectName("actSelAll");
        actSelNone = new QAction(MainWindow);
        actSelNone->setObjectName("actSelNone");
        actSellnvs = new QAction(MainWindow);
        actSellnvs->setObjectName("actSellnvs");
        actExit = new QAction(MainWindow);
        actExit->setObjectName("actExit");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName("toolBox");
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 189, 277));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tBtnListInit = new QToolButton(page);
        tBtnListInit->setObjectName("tBtnListInit");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tBtnListInit->sizePolicy().hasHeightForWidth());
        tBtnListInit->setSizePolicy(sizePolicy);
        tBtnListInit->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_2->addWidget(tBtnListInit);

        tBtnListClear = new QToolButton(page);
        tBtnListClear->setObjectName("tBtnListClear");
        sizePolicy.setHeightForWidth(tBtnListClear->sizePolicy().hasHeightForWidth());
        tBtnListClear->setSizePolicy(sizePolicy);
        tBtnListClear->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_2->addWidget(tBtnListClear);

        tBtnListInsert = new QToolButton(page);
        tBtnListInsert->setObjectName("tBtnListInsert");
        sizePolicy.setHeightForWidth(tBtnListInsert->sizePolicy().hasHeightForWidth());
        tBtnListInsert->setSizePolicy(sizePolicy);
        tBtnListInsert->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_2->addWidget(tBtnListInsert);

        tBtnListAppend = new QToolButton(page);
        tBtnListAppend->setObjectName("tBtnListAppend");
        sizePolicy.setHeightForWidth(tBtnListAppend->sizePolicy().hasHeightForWidth());
        tBtnListAppend->setSizePolicy(sizePolicy);
        tBtnListAppend->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_2->addWidget(tBtnListAppend);

        tBtnListDelete = new QToolButton(page);
        tBtnListDelete->setObjectName("tBtnListDelete");
        sizePolicy.setHeightForWidth(tBtnListDelete->sizePolicy().hasHeightForWidth());
        tBtnListDelete->setSizePolicy(sizePolicy);
        tBtnListDelete->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_2->addWidget(tBtnListDelete);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/list.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page, icon6, QString::fromUtf8("QListWidget\346\223\215\344\275\234"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 189, 277));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/table.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_2, icon7, QString::fromUtf8("QTableWidget\346\223\215\344\275\234"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/tree.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_3, icon8, QString::fromUtf8("QTreeWidget\346\223\215\344\275\234"));
        splitter->addWidget(toolBox);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        editCurItem = new QLineEdit(groupBox);
        editCurItem->setObjectName("editCurItem");

        horizontalLayout->addWidget(editCurItem);

        ckbEditable = new QCheckBox(groupBox);
        ckbEditable->setObjectName("ckbEditable");

        horizontalLayout->addWidget(ckbEditable);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tBtnSelAll = new QToolButton(groupBox_2);
        tBtnSelAll->setObjectName("tBtnSelAll");
        sizePolicy.setHeightForWidth(tBtnSelAll->sizePolicy().hasHeightForWidth());
        tBtnSelAll->setSizePolicy(sizePolicy);
        tBtnSelAll->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_2->addWidget(tBtnSelAll);

        tBtnSelNone = new QToolButton(groupBox_2);
        tBtnSelNone->setObjectName("tBtnSelNone");
        sizePolicy.setHeightForWidth(tBtnSelNone->sizePolicy().hasHeightForWidth());
        tBtnSelNone->setSizePolicy(sizePolicy);
        tBtnSelNone->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_2->addWidget(tBtnSelNone);

        tBtnSelInvs = new QToolButton(groupBox_2);
        tBtnSelInvs->setObjectName("tBtnSelInvs");
        sizePolicy.setHeightForWidth(tBtnSelInvs->sizePolicy().hasHeightForWidth());
        tBtnSelInvs->setSizePolicy(sizePolicy);
        tBtnSelInvs->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_2->addWidget(tBtnSelInvs);


        verticalLayout_3->addWidget(groupBox_2);

        listWidget = new QListWidget(tab);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/check.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setCheckState(Qt::Checked);
        __qlistwidgetitem->setIcon(icon9);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setCheckState(Qt::Checked);
        __qlistwidgetitem1->setIcon(icon9);
        listWidget->setObjectName("listWidget");
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout_3->addWidget(listWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout = new QVBoxLayout(tab_3);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget->addTab(tab_3, QString());
        splitter->addWidget(tabWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actListInit);
        toolBar->addAction(actListClear);
        toolBar->addSeparator();
        toolBar->addAction(actItemInsert);
        toolBar->addAction(actItemAppend);
        toolBar->addAction(actItemDelete);
        toolBar->addSeparator();
        toolBar->addAction(actExit);

        retranslateUi(MainWindow);
        QObject::connect(actExit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ListWidget", nullptr));
        actListInit->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
#if QT_CONFIG(shortcut)
        actListInit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actListClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        actItemInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", nullptr));
#if QT_CONFIG(shortcut)
        actItemInsert->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actItemAppend->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", nullptr));
#if QT_CONFIG(shortcut)
        actItemAppend->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actItemDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
#if QT_CONFIG(shortcut)
        actItemDelete->setShortcut(QCoreApplication::translate("MainWindow", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        actSelAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        actSelNone->setText(QCoreApplication::translate("MainWindow", "\345\205\250\344\270\215\351\200\211", nullptr));
        actSellnvs->setText(QCoreApplication::translate("MainWindow", "\345\217\215\351\200\211", nullptr));
        actExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        tBtnListInit->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
        tBtnListClear->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\210\227\350\241\250", nullptr));
        tBtnListInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", nullptr));
        tBtnListAppend->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", nullptr));
        tBtnListDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "QListWidget\346\223\215\344\275\234", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "QTableWidget\346\223\215\344\275\234", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "QTreeWidget\346\223\215\344\275\234", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\241\271\345\217\230\345\214\226", nullptr));
        ckbEditable->setText(QCoreApplication::translate("MainWindow", "\345\217\257\347\274\226\350\276\221", nullptr));
        groupBox_2->setTitle(QString());
        tBtnSelAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        tBtnSelNone->setText(QCoreApplication::translate("MainWindow", "\345\205\250\344\270\215\351\200\211", nullptr));
        tBtnSelInvs->setText(QCoreApplication::translate("MainWindow", "\345\217\215\351\200\211", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "QListWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "QTableWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "QTreeWidget", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
