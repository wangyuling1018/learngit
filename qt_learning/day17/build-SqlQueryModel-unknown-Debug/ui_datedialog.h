/********************************************************************************
** Form generated from reading UI file 'datedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATEDIALOG_H
#define UI_DATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DateDialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editEmpNo;
    QLabel *label_2;
    QLineEdit *editEmpName;
    QLabel *label_3;
    QComboBox *cmbGender;
    QLabel *label_4;
    QComboBox *cmbDept;
    QLabel *label_5;
    QSpinBox *spinBoxSalary;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *DateDialog)
    {
        if (DateDialog->objectName().isEmpty())
            DateDialog->setObjectName("DateDialog");
        DateDialog->resize(395, 288);
        groupBox = new QGroupBox(DateDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(12, 1, 261, 281));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editEmpNo = new QLineEdit(groupBox);
        editEmpNo->setObjectName("editEmpNo");

        gridLayout->addWidget(editEmpNo, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        editEmpName = new QLineEdit(groupBox);
        editEmpName->setObjectName("editEmpName");

        gridLayout->addWidget(editEmpName, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cmbGender = new QComboBox(groupBox);
        cmbGender->addItem(QString());
        cmbGender->addItem(QString());
        cmbGender->setObjectName("cmbGender");

        gridLayout->addWidget(cmbGender, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        cmbDept = new QComboBox(groupBox);
        cmbDept->setObjectName("cmbDept");

        gridLayout->addWidget(cmbDept, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        spinBoxSalary = new QSpinBox(groupBox);
        spinBoxSalary->setObjectName("spinBoxSalary");
        spinBoxSalary->setMinimum(3000);
        spinBoxSalary->setMaximum(99999999);
        spinBoxSalary->setValue(5000);

        gridLayout->addWidget(spinBoxSalary, 4, 1, 1, 1);

        btnOk = new QPushButton(DateDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(300, 10, 71, 32));
        btnCancel = new QPushButton(DateDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(300, 50, 71, 32));

        retranslateUi(DateDialog);
        QObject::connect(btnOk, &QPushButton::clicked, DateDialog, qOverload<>(&QDialog::accept));
        QObject::connect(btnCancel, &QPushButton::clicked, DateDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DateDialog);
    } // setupUi

    void retranslateUi(QDialog *DateDialog)
    {
        DateDialog->setWindowTitle(QCoreApplication::translate("DateDialog", "\346\233\264\346\226\260\350\256\260\345\275\225", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DateDialog", "\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("DateDialog", "\345\267\245  \345\217\267\357\274\233", nullptr));
        label_2->setText(QCoreApplication::translate("DateDialog", "\345\247\223   \345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("DateDialog", "\346\200\247    \345\210\253\357\274\232", nullptr));
        cmbGender->setItemText(0, QCoreApplication::translate("DateDialog", "\347\224\267", nullptr));
        cmbGender->setItemText(1, QCoreApplication::translate("DateDialog", "\345\245\263", nullptr));

        label_4->setText(QCoreApplication::translate("DateDialog", "\345\255\246    \351\231\242\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("DateDialog", "\345\267\245    \350\265\204\357\274\232", nullptr));
        btnOk->setText(QCoreApplication::translate("DateDialog", "\347\241\256    \345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("DateDialog", "\345\217\226    \346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateDialog: public Ui_DateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEDIALOG_H
