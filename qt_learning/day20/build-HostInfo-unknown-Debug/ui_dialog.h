/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnGetLocal;
    QPushButton *btnAllAddresses;
    QCheckBox *ckbIPv4Only;
    QPushButton *btnAllInterfaces;
    QPushButton *btnLookup;
    QLineEdit *editLookup;
    QPushButton *btnTextClear;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(541, 588);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        btnGetLocal = new QPushButton(Dialog);
        btnGetLocal->setObjectName("btnGetLocal");

        gridLayout->addWidget(btnGetLocal, 0, 0, 1, 1);

        btnAllAddresses = new QPushButton(Dialog);
        btnAllAddresses->setObjectName("btnAllAddresses");

        gridLayout->addWidget(btnAllAddresses, 0, 1, 1, 1);

        ckbIPv4Only = new QCheckBox(Dialog);
        ckbIPv4Only->setObjectName("ckbIPv4Only");

        gridLayout->addWidget(ckbIPv4Only, 1, 0, 1, 1);

        btnAllInterfaces = new QPushButton(Dialog);
        btnAllInterfaces->setObjectName("btnAllInterfaces");

        gridLayout->addWidget(btnAllInterfaces, 1, 1, 1, 1);

        btnLookup = new QPushButton(Dialog);
        btnLookup->setObjectName("btnLookup");

        gridLayout->addWidget(btnLookup, 2, 0, 1, 1);

        editLookup = new QLineEdit(Dialog);
        editLookup->setObjectName("editLookup");

        gridLayout->addWidget(editLookup, 2, 1, 1, 1);

        btnTextClear = new QPushButton(Dialog);
        btnTextClear->setObjectName("btnTextClear");

        gridLayout->addWidget(btnTextClear, 3, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 4, 0, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        btnGetLocal->setText(QCoreApplication::translate("Dialog", "QHostInfo\350\216\267\345\217\226\346\234\254\346\234\272\344\270\273\346\234\272\345\220\215\345\222\214IP\345\234\260\345\235\200", nullptr));
        btnAllAddresses->setText(QCoreApplication::translate("Dialog", "QNetWorkInterface::Addresses", nullptr));
        ckbIPv4Only->setText(QCoreApplication::translate("Dialog", "\345\217\252\346\230\276\347\244\272IPV4\345\215\217\350\256\256\345\234\260\345\235\200", nullptr));
        btnAllInterfaces->setText(QCoreApplication::translate("Dialog", "QNextWorkInterface::allInterface", nullptr));
        btnLookup->setText(QCoreApplication::translate("Dialog", "QHostInfo\346\237\245\346\211\276\345\237\237\345\220\215\347\232\204IP\345\234\260\345\235\200", nullptr));
        btnTextClear->setText(QCoreApplication::translate("Dialog", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
