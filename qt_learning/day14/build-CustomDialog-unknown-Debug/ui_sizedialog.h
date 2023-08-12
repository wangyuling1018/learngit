/********************************************************************************
** Form generated from reading UI file 'sizedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZEDIALOG_H
#define UI_SIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SizeDialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *spinRow;
    QSpinBox *spinColumn;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *SizeDialog)
    {
        if (SizeDialog->objectName().isEmpty())
            SizeDialog->setObjectName("SizeDialog");
        SizeDialog->resize(379, 148);
        groupBox = new QGroupBox(SizeDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 241, 131));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinRow = new QSpinBox(groupBox);
        spinRow->setObjectName("spinRow");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinRow->sizePolicy().hasHeightForWidth());
        spinRow->setSizePolicy(sizePolicy);

        gridLayout->addWidget(spinRow, 0, 1, 1, 1);

        spinColumn = new QSpinBox(groupBox);
        spinColumn->setObjectName("spinColumn");

        gridLayout->addWidget(spinColumn, 1, 1, 1, 1);

        btnOk = new QPushButton(SizeDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(260, 30, 100, 32));
        btnCancel = new QPushButton(SizeDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(260, 90, 100, 32));

        retranslateUi(SizeDialog);
        QObject::connect(btnOk, &QPushButton::clicked, SizeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(btnCancel, &QPushButton::clicked, SizeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SizeDialog);
    } // setupUi

    void retranslateUi(QDialog *SizeDialog)
    {
        SizeDialog->setWindowTitle(QCoreApplication::translate("SizeDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SizeDialog", "\350\256\276\347\275\256\350\241\250\346\240\274\350\241\214\346\225\260\345\222\214\345\210\227\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("SizeDialog", "\345\210\227      \346\225\260\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SizeDialog", " \350\241\214     \346\225\260\357\274\232", nullptr));
        btnOk->setText(QCoreApplication::translate("SizeDialog", "\347\241\256     \345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("SizeDialog", "\345\217\226      \346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SizeDialog: public Ui_SizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZEDIALOG_H
