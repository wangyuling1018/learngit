/********************************************************************************
** Form generated from reading UI file 'locatedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATEDIALOG_H
#define UI_LOCATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_LocateDialog
{
public:
    QPushButton *btnSetText;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinRow;
    QLabel *label_2;
    QSpinBox *spinColumn;
    QLabel *label_3;
    QLineEdit *lineEditSetText;

    void setupUi(QDialog *LocateDialog)
    {
        if (LocateDialog->objectName().isEmpty())
            LocateDialog->setObjectName("LocateDialog");
        LocateDialog->resize(367, 137);
        btnSetText = new QPushButton(LocateDialog);
        btnSetText->setObjectName("btnSetText");
        btnSetText->setGeometry(QRect(250, 10, 100, 32));
        btnCancel = new QPushButton(LocateDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(250, 40, 100, 32));
        groupBox = new QGroupBox(LocateDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 231, 121));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinRow = new QSpinBox(groupBox);
        spinRow->setObjectName("spinRow");

        formLayout->setWidget(0, QFormLayout::FieldRole, spinRow);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinColumn = new QSpinBox(groupBox);
        spinColumn->setObjectName("spinColumn");

        formLayout->setWidget(1, QFormLayout::FieldRole, spinColumn);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditSetText = new QLineEdit(groupBox);
        lineEditSetText->setObjectName("lineEditSetText");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditSetText);


        retranslateUi(LocateDialog);

        QMetaObject::connectSlotsByName(LocateDialog);
    } // setupUi

    void retranslateUi(QDialog *LocateDialog)
    {
        LocateDialog->setWindowTitle(QCoreApplication::translate("LocateDialog", "Dialog", nullptr));
        btnSetText->setText(QCoreApplication::translate("LocateDialog", "\350\256\276\345\256\232\346\226\207\345\255\227", nullptr));
        btnCancel->setText(QCoreApplication::translate("LocateDialog", "\345\217\226\346\266\210", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("LocateDialog", "\350\241\214      \345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("LocateDialog", "\345\210\227      \345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("LocateDialog", "\350\256\276\345\256\232\346\226\207\345\255\227\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LocateDialog: public Ui_LocateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATEDIALOG_H
