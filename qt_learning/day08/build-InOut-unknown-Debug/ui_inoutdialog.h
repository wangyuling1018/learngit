/********************************************************************************
** Form generated from reading UI file 'inoutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INOUTDIALOG_H
#define UI_INOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InOutDialog
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinNum;
    QLabel *label_2;
    QDoubleSpinBox *dSpinPrice;
    QPushButton *btnCalc;
    QLabel *label_3;
    QLineEdit *editTotle;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QSpinBox *spinDec;
    QPushButton *btnDexTothe;
    QLabel *label_5;
    QSpinBox *spinBin;
    QPushButton *btnBinToOthe;
    QLabel *label_6;
    QSpinBox *spinHex;
    QPushButton *btnHexToOthe;

    void setupUi(QDialog *InOutDialog)
    {
        if (InOutDialog->objectName().isEmpty())
            InOutDialog->setObjectName("InOutDialog");
        InOutDialog->resize(442, 247);
        gridLayout_3 = new QGridLayout(InOutDialog);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(InOutDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinNum = new QSpinBox(InOutDialog);
        spinNum->setObjectName("spinNum");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(12);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinNum->sizePolicy().hasHeightForWidth());
        spinNum->setSizePolicy(sizePolicy);

        gridLayout->addWidget(spinNum, 0, 1, 1, 1);

        label_2 = new QLabel(InOutDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        dSpinPrice = new QDoubleSpinBox(InOutDialog);
        dSpinPrice->setObjectName("dSpinPrice");
        sizePolicy.setHeightForWidth(dSpinPrice->sizePolicy().hasHeightForWidth());
        dSpinPrice->setSizePolicy(sizePolicy);
        dSpinPrice->setMaximum(9999.989999999999782);
        dSpinPrice->setSingleStep(0.500000000000000);
        dSpinPrice->setValue(0.000000000000000);

        gridLayout->addWidget(dSpinPrice, 0, 3, 1, 1);

        btnCalc = new QPushButton(InOutDialog);
        btnCalc->setObjectName("btnCalc");

        gridLayout->addWidget(btnCalc, 1, 0, 1, 2);

        label_3 = new QLabel(InOutDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        editTotle = new QLineEdit(InOutDialog);
        editTotle->setObjectName("editTotle");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editTotle->sizePolicy().hasHeightForWidth());
        editTotle->setSizePolicy(sizePolicy1);
        editTotle->setReadOnly(true);

        gridLayout->addWidget(editTotle, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(InOutDialog);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        spinDec = new QSpinBox(InOutDialog);
        spinDec->setObjectName("spinDec");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinDec->sizePolicy().hasHeightForWidth());
        spinDec->setSizePolicy(sizePolicy2);
        spinDec->setMaximum(255);

        gridLayout_2->addWidget(spinDec, 0, 1, 1, 1);

        btnDexTothe = new QPushButton(InOutDialog);
        btnDexTothe->setObjectName("btnDexTothe");

        gridLayout_2->addWidget(btnDexTothe, 0, 2, 1, 1);

        label_5 = new QLabel(InOutDialog);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        spinBin = new QSpinBox(InOutDialog);
        spinBin->setObjectName("spinBin");
        sizePolicy2.setHeightForWidth(spinBin->sizePolicy().hasHeightForWidth());
        spinBin->setSizePolicy(sizePolicy2);
        spinBin->setMaximum(255);
        spinBin->setDisplayIntegerBase(2);

        gridLayout_2->addWidget(spinBin, 1, 1, 1, 1);

        btnBinToOthe = new QPushButton(InOutDialog);
        btnBinToOthe->setObjectName("btnBinToOthe");

        gridLayout_2->addWidget(btnBinToOthe, 1, 2, 1, 1);

        label_6 = new QLabel(InOutDialog);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        spinHex = new QSpinBox(InOutDialog);
        spinHex->setObjectName("spinHex");
        sizePolicy2.setHeightForWidth(spinHex->sizePolicy().hasHeightForWidth());
        spinHex->setSizePolicy(sizePolicy2);
        spinHex->setMaximum(255);
        spinHex->setDisplayIntegerBase(16);

        gridLayout_2->addWidget(spinHex, 2, 1, 1, 1);

        btnHexToOthe = new QPushButton(InOutDialog);
        btnHexToOthe->setObjectName("btnHexToOthe");

        gridLayout_2->addWidget(btnHexToOthe, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(InOutDialog);

        QMetaObject::connectSlotsByName(InOutDialog);
    } // setupUi

    void retranslateUi(QDialog *InOutDialog)
    {
        InOutDialog->setWindowTitle(QCoreApplication::translate("InOutDialog", "InOutDialog", nullptr));
        label->setText(QCoreApplication::translate("InOutDialog", "\346\225\260     \351\207\217", nullptr));
        spinNum->setSuffix(QCoreApplication::translate("InOutDialog", " kg", nullptr));
        label_2->setText(QCoreApplication::translate("InOutDialog", "\345\215\225   \344\273\267", nullptr));
        dSpinPrice->setPrefix(QCoreApplication::translate("InOutDialog", "\302\245", nullptr));
        btnCalc->setText(QCoreApplication::translate("InOutDialog", "\350\256\241\347\256\227", nullptr));
        label_3->setText(QCoreApplication::translate("InOutDialog", " \346\200\273   \344\273\267", nullptr));
        label_4->setText(QCoreApplication::translate("InOutDialog", "\345\215\201 \350\277\233 \345\210\266", nullptr));
        spinDec->setSuffix(QString());
        spinDec->setPrefix(QCoreApplication::translate("InOutDialog", "Dec ", nullptr));
        btnDexTothe->setText(QCoreApplication::translate("InOutDialog", "\350\275\254\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        label_5->setText(QCoreApplication::translate("InOutDialog", "\344\272\214 \350\277\233 \345\210\266", nullptr));
        spinBin->setPrefix(QCoreApplication::translate("InOutDialog", "Bin ", nullptr));
        btnBinToOthe->setText(QCoreApplication::translate("InOutDialog", "\350\275\254\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        label_6->setText(QCoreApplication::translate("InOutDialog", "\345\215\201\345\205\255\346\234\272\345\210\266", nullptr));
        spinHex->setPrefix(QCoreApplication::translate("InOutDialog", "Hex ", nullptr));
        btnHexToOthe->setText(QCoreApplication::translate("InOutDialog", "\350\275\254\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InOutDialog: public Ui_InOutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INOUTDIALOG_H
