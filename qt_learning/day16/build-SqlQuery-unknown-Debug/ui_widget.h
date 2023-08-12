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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editEmpNo;
    QPushButton *btnInsert;
    QLabel *label_2;
    QLineEdit *editEmpName;
    QPushButton *btnUpdate;
    QLabel *label_3;
    QComboBox *cmbGender;
    QPushButton *btnDelete;
    QLabel *label_4;
    QComboBox *cmbDeptId;
    QPushButton *btnSelect;
    QLabel *label_5;
    QSpinBox *spinBoxSalary;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(468, 285);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editEmpNo = new QLineEdit(Widget);
        editEmpNo->setObjectName("editEmpNo");

        gridLayout->addWidget(editEmpNo, 0, 1, 1, 1);

        btnInsert = new QPushButton(Widget);
        btnInsert->setObjectName("btnInsert");

        gridLayout->addWidget(btnInsert, 0, 2, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        editEmpName = new QLineEdit(Widget);
        editEmpName->setObjectName("editEmpName");

        gridLayout->addWidget(editEmpName, 1, 1, 1, 1);

        btnUpdate = new QPushButton(Widget);
        btnUpdate->setObjectName("btnUpdate");

        gridLayout->addWidget(btnUpdate, 1, 2, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cmbGender = new QComboBox(Widget);
        cmbGender->addItem(QString());
        cmbGender->addItem(QString());
        cmbGender->setObjectName("cmbGender");

        gridLayout->addWidget(cmbGender, 2, 1, 1, 1);

        btnDelete = new QPushButton(Widget);
        btnDelete->setObjectName("btnDelete");

        gridLayout->addWidget(btnDelete, 2, 2, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        cmbDeptId = new QComboBox(Widget);
        cmbDeptId->setObjectName("cmbDeptId");

        gridLayout->addWidget(cmbDeptId, 3, 1, 1, 1);

        btnSelect = new QPushButton(Widget);
        btnSelect->setObjectName("btnSelect");

        gridLayout->addWidget(btnSelect, 3, 2, 1, 1);

        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        spinBoxSalary = new QSpinBox(Widget);
        spinBoxSalary->setObjectName("spinBoxSalary");
        spinBoxSalary->setMinimum(3000);
        spinBoxSalary->setMaximum(99999);
        spinBoxSalary->setSingleStep(1);
        spinBoxSalary->setValue(5000);

        gridLayout->addWidget(spinBoxSalary, 4, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "SqlQuery", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\267\245   \345\217\267\357\274\232", nullptr));
        btnInsert->setText(QCoreApplication::translate("Widget", "\346\217\222\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\247\223    \345\220\215\357\274\232", nullptr));
        btnUpdate->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\200\247     \345\210\253\357\274\232", nullptr));
        cmbGender->setItemText(0, QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        cmbGender->setItemText(1, QCoreApplication::translate("Widget", "\345\245\263", nullptr));

        btnDelete->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", " \351\203\250    \351\227\250\357\274\232", nullptr));
        btnSelect->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\267\245     \350\265\204\357\274\232", nullptr));
        spinBoxSalary->setSuffix(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
