/********************************************************************************
** Form generated from reading UI file 'calculatordialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORDIALOG_H
#define UI_CALCULATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalculatorDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_editx;
    QLabel *label;
    QLineEdit *m_edity;
    QPushButton *m_button;
    QLineEdit *m_editz;

    void setupUi(QDialog *CalculatorDialog)
    {
        if (CalculatorDialog->objectName().isEmpty())
            CalculatorDialog->setObjectName("CalculatorDialog");
        CalculatorDialog->resize(540, 148);
        gridLayout = new QGridLayout(CalculatorDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        m_editx = new QLineEdit(CalculatorDialog);
        m_editx->setObjectName("m_editx");
        m_editx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editx);

        label = new QLabel(CalculatorDialog);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        m_edity = new QLineEdit(CalculatorDialog);
        m_edity->setObjectName("m_edity");
        m_edity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_edity);

        m_button = new QPushButton(CalculatorDialog);
        m_button->setObjectName("m_button");
        m_button->setEnabled(false);

        horizontalLayout->addWidget(m_button);

        m_editz = new QLineEdit(CalculatorDialog);
        m_editz->setObjectName("m_editz");
        m_editz->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_editz->setReadOnly(true);

        horizontalLayout->addWidget(m_editz);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(CalculatorDialog);

        QMetaObject::connectSlotsByName(CalculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *CalculatorDialog)
    {
        CalculatorDialog->setWindowTitle(QCoreApplication::translate("CalculatorDialog", "\350\256\241\347\256\227\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("CalculatorDialog", "+", nullptr));
        m_button->setText(QCoreApplication::translate("CalculatorDialog", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorDialog: public Ui_CalculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORDIALOG_H
