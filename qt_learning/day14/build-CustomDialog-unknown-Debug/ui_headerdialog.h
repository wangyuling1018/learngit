/********************************************************************************
** Form generated from reading UI file 'headerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADERDIALOG_H
#define UI_HEADERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HeaderDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QListView *listView;
    QVBoxLayout *verticalLayout;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *HeaderDialog)
    {
        if (HeaderDialog->objectName().isEmpty())
            HeaderDialog->setObjectName("HeaderDialog");
        HeaderDialog->resize(290, 302);
        horizontalLayout = new QHBoxLayout(HeaderDialog);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(HeaderDialog);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        listView = new QListView(groupBox);
        listView->setObjectName("listView");

        gridLayout->addWidget(listView, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btnOk = new QPushButton(HeaderDialog);
        btnOk->setObjectName("btnOk");

        verticalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(HeaderDialog);
        btnCancel->setObjectName("btnCancel");

        verticalLayout->addWidget(btnCancel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(HeaderDialog);
        QObject::connect(btnOk, &QPushButton::clicked, HeaderDialog, qOverload<>(&QDialog::accept));
        QObject::connect(btnCancel, &QPushButton::clicked, HeaderDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HeaderDialog);
    } // setupUi

    void retranslateUi(QDialog *HeaderDialog)
    {
        HeaderDialog->setWindowTitle(QCoreApplication::translate("HeaderDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("HeaderDialog", "\350\241\250\345\244\264\346\240\207\351\242\230", nullptr));
        btnOk->setText(QCoreApplication::translate("HeaderDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("HeaderDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeaderDialog: public Ui_HeaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADERDIALOG_H
