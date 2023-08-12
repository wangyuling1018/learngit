/********************************************************************************
** Form generated from reading UI file 'clockwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKWIDGET_H
#define UI_CLOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClockWidget
{
public:
    QGridLayout *gridLayout;
    QLCDNumber *lcdHour;
    QLabel *label;
    QLCDNumber *lcdMinute;
    QLabel *label_2;
    QLCDNumber *lcdSecond;

    void setupUi(QWidget *ClockWidget)
    {
        if (ClockWidget->objectName().isEmpty())
            ClockWidget->setObjectName("ClockWidget");
        ClockWidget->resize(325, 82);
        gridLayout = new QGridLayout(ClockWidget);
        gridLayout->setObjectName("gridLayout");
        lcdHour = new QLCDNumber(ClockWidget);
        lcdHour->setObjectName("lcdHour");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdHour->sizePolicy().hasHeightForWidth());
        lcdHour->setSizePolicy(sizePolicy);
        lcdHour->setDigitCount(2);

        gridLayout->addWidget(lcdHour, 0, 0, 1, 1);

        label = new QLabel(ClockWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        lcdMinute = new QLCDNumber(ClockWidget);
        lcdMinute->setObjectName("lcdMinute");
        sizePolicy.setHeightForWidth(lcdMinute->sizePolicy().hasHeightForWidth());
        lcdMinute->setSizePolicy(sizePolicy);
        lcdMinute->setDigitCount(2);

        gridLayout->addWidget(lcdMinute, 0, 2, 1, 1);

        label_2 = new QLabel(ClockWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        lcdSecond = new QLCDNumber(ClockWidget);
        lcdSecond->setObjectName("lcdSecond");
        sizePolicy.setHeightForWidth(lcdSecond->sizePolicy().hasHeightForWidth());
        lcdSecond->setSizePolicy(sizePolicy);
        lcdSecond->setDigitCount(2);

        gridLayout->addWidget(lcdSecond, 0, 4, 1, 1);


        retranslateUi(ClockWidget);

        QMetaObject::connectSlotsByName(ClockWidget);
    } // setupUi

    void retranslateUi(QWidget *ClockWidget)
    {
        ClockWidget->setWindowTitle(QCoreApplication::translate("ClockWidget", "\346\227\266\351\222\237\346\230\276\347\244\272\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("ClockWidget", " :", nullptr));
        label_2->setText(QCoreApplication::translate("ClockWidget", " :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClockWidget: public Ui_ClockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKWIDGET_H
