/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *labelSize;
    QCheckBox *ckbIsDir;
    QLabel *labelFileName;
    QLabel *labelFilePath;
    QLabel *labelType;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *treeView;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QListView *listView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1003, 528);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName("gridLayout");
        labelSize = new QLabel(groupBox_4);
        labelSize->setObjectName("labelSize");

        gridLayout->addWidget(labelSize, 0, 1, 1, 1);

        ckbIsDir = new QCheckBox(groupBox_4);
        ckbIsDir->setObjectName("ckbIsDir");

        gridLayout->addWidget(ckbIsDir, 0, 3, 1, 1);

        labelFileName = new QLabel(groupBox_4);
        labelFileName->setObjectName("labelFileName");

        gridLayout->addWidget(labelFileName, 0, 0, 1, 1);

        labelFilePath = new QLabel(groupBox_4);
        labelFilePath->setObjectName("labelFilePath");

        gridLayout->addWidget(labelFilePath, 1, 0, 1, 1);

        labelType = new QLabel(groupBox_4);
        labelType->setObjectName("labelType");

        gridLayout->addWidget(labelType, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 1, 0, 1, 1);

        splitter_2 = new QSplitter(Widget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        treeView = new QTreeView(groupBox_2);
        treeView->setObjectName("treeView");

        horizontalLayout_2->addWidget(treeView);

        splitter->addWidget(groupBox_2);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName("tableView");

        horizontalLayout->addWidget(tableView);

        splitter->addWidget(groupBox_3);
        splitter_2->addWidget(splitter);
        groupBox = new QGroupBox(splitter_2);
        groupBox->setObjectName("groupBox");
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        listView = new QListView(groupBox);
        listView->setObjectName("listView");

        horizontalLayout_3->addWidget(listView);

        splitter_2->addWidget(groupBox);

        gridLayout_2->addWidget(splitter_2, 0, 0, 1, 1);


        retranslateUi(Widget);
        QObject::connect(treeView, &QTreeView::clicked, listView, &QListView::setRootIndex);
        QObject::connect(treeView, &QTreeView::clicked, tableView, &QTableView::setRootIndex);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox_4->setTitle(QString());
        labelSize->setText(QString());
        ckbIsDir->setText(QCoreApplication::translate("Widget", "\350\212\202\347\202\271\346\230\257\347\233\256\345\275\225", nullptr));
        labelFileName->setText(QString());
        labelFilePath->setText(QString());
        labelType->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "QTreeView", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "QTableView", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "QListView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
