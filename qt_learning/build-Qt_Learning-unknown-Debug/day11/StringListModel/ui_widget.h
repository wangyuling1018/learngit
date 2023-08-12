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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *btnListInit;
    QPushButton *btnItemAppend;
    QPushButton *btnItemInsert;
    QPushButton *btnItemDelete;
    QPushButton *btnItemClear;
    QListView *listView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnTextClear;
    QPushButton *bntDisplay;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *labelCurlItem;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(651, 445);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        btnListInit = new QPushButton(groupBox);
        btnListInit->setObjectName("btnListInit");

        gridLayout_2->addWidget(btnListInit, 0, 0, 1, 1);

        btnItemAppend = new QPushButton(groupBox);
        btnItemAppend->setObjectName("btnItemAppend");

        gridLayout_2->addWidget(btnItemAppend, 1, 0, 1, 1);

        btnItemInsert = new QPushButton(groupBox);
        btnItemInsert->setObjectName("btnItemInsert");

        gridLayout_2->addWidget(btnItemInsert, 1, 1, 1, 1);

        btnItemDelete = new QPushButton(groupBox);
        btnItemDelete->setObjectName("btnItemDelete");

        gridLayout_2->addWidget(btnItemDelete, 2, 0, 1, 1);

        btnItemClear = new QPushButton(groupBox);
        btnItemClear->setObjectName("btnItemClear");

        gridLayout_2->addWidget(btnItemClear, 2, 1, 1, 1);

        listView = new QListView(groupBox);
        listView->setObjectName("listView");

        gridLayout_2->addWidget(listView, 3, 0, 1, 2);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName("verticalLayout");
        btnTextClear = new QPushButton(groupBox_2);
        btnTextClear->setObjectName("btnTextClear");

        verticalLayout->addWidget(btnTextClear);

        bntDisplay = new QPushButton(groupBox_2);
        bntDisplay->setObjectName("bntDisplay");

        verticalLayout->addWidget(bntDisplay);

        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName("gridLayout");
        labelCurlItem = new QLabel(groupBox_3);
        labelCurlItem->setObjectName("labelCurlItem");

        gridLayout->addWidget(labelCurlItem, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "QStringlistModel\345\222\214QListView", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "QListView", nullptr));
        btnListInit->setText(QCoreApplication::translate("Widget", "\346\201\242\345\244\215\345\210\227\350\241\250", nullptr));
        btnItemAppend->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\351\241\271", nullptr));
        btnItemInsert->setText(QCoreApplication::translate("Widget", "\346\217\222\345\205\245\351\241\271", nullptr));
        btnItemDelete->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
        btnItemClear->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "QPlaintTextEdit", nullptr));
        btnTextClear->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        bntDisplay->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\225\260\346\215\256\346\250\241\345\236\213StringList", nullptr));
        groupBox_3->setTitle(QString());
        labelCurlItem->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\235\241\347\233\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
