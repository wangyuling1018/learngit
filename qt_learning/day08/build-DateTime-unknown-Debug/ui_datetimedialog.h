/********************************************************************************
** Form generated from reading UI file 'datetimedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIMEDIALOG_H
#define UI_DATETIMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_DateTimeDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QTimeEdit *timeEdit;
    QLineEdit *lineEditTime;
    QPushButton *btnSetTime;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLineEdit *lineEditDate;
    QPushButton *btnSetDate;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEditDateTime;
    QPushButton *btnSetDateTim;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditSelDate;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *DateTimeDialog)
    {
        if (DateTimeDialog->objectName().isEmpty())
            DateTimeDialog->setObjectName("DateTimeDialog");
        DateTimeDialog->resize(575, 538);
        gridLayout_3 = new QGridLayout(DateTimeDialog);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBox = new QGroupBox(DateTimeDialog);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        timeEdit = new QTimeEdit(groupBox);
        timeEdit->setObjectName("timeEdit");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(timeEdit->sizePolicy().hasHeightForWidth());
        timeEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(timeEdit, 1, 1, 1, 1);

        lineEditTime = new QLineEdit(groupBox);
        lineEditTime->setObjectName("lineEditTime");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditTime->sizePolicy().hasHeightForWidth());
        lineEditTime->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEditTime, 1, 2, 1, 1);

        btnSetTime = new QPushButton(groupBox);
        btnSetTime->setObjectName("btnSetTime");

        gridLayout->addWidget(btnSetTime, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);

        lineEditDate = new QLineEdit(groupBox);
        lineEditDate->setObjectName("lineEditDate");

        gridLayout->addWidget(lineEditDate, 2, 2, 1, 1);

        btnSetDate = new QPushButton(groupBox);
        btnSetDate->setObjectName("btnSetDate");

        gridLayout->addWidget(btnSetDate, 2, 3, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName("dateTimeEdit");

        gridLayout->addWidget(dateTimeEdit, 3, 1, 1, 1);

        lineEditDateTime = new QLineEdit(groupBox);
        lineEditDateTime->setObjectName("lineEditDateTime");

        gridLayout->addWidget(lineEditDateTime, 3, 2, 1, 1);

        btnSetDateTim = new QPushButton(groupBox);
        btnSetDateTim->setObjectName("btnSetDateTim");

        gridLayout->addWidget(btnSetDateTim, 3, 3, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(DateTimeDialog);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEditSelDate = new QLineEdit(groupBox_2);
        lineEditSelDate->setObjectName("lineEditSelDate");

        gridLayout_2->addWidget(lineEditSelDate, 0, 1, 1, 1);

        calendarWidget = new QCalendarWidget(groupBox_2);
        calendarWidget->setObjectName("calendarWidget");

        gridLayout_2->addWidget(calendarWidget, 1, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);


        retranslateUi(DateTimeDialog);

        QMetaObject::connectSlotsByName(DateTimeDialog);
    } // setupUi

    void retranslateUi(QDialog *DateTimeDialog)
    {
        DateTimeDialog->setWindowTitle(QCoreApplication::translate("DateTimeDialog", "DateTimeDialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DateTimeDialog", "\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        pushButton->setText(QCoreApplication::translate("DateTimeDialog", "\350\257\273\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("DateTimeDialog", "\345\255\227\347\254\246\344\270\262\346\230\276\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("DateTimeDialog", "\346\227\266      \351\227\264", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("DateTimeDialog", "HH:mm:ss", nullptr));
        btnSetTime->setText(QCoreApplication::translate("DateTimeDialog", "\350\256\276\347\275\256\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("DateTimeDialog", "\346\227\245      \346\234\237", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("DateTimeDialog", "yyyy-MM-dd", nullptr));
        btnSetDate->setText(QCoreApplication::translate("DateTimeDialog", "\350\256\276\347\275\256\346\227\245\346\234\237", nullptr));
        label_4->setText(QCoreApplication::translate("DateTimeDialog", "\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("DateTimeDialog", "yyyy-MM-dd HH:mm:ss", nullptr));
        btnSetDateTim->setText(QCoreApplication::translate("DateTimeDialog", "\350\256\276\347\275\256\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DateTimeDialog", "\346\227\245\345\216\206\351\200\211\346\213\251", nullptr));
        label_5->setText(QCoreApplication::translate("DateTimeDialog", "\351\200\211\346\213\251\346\227\245\346\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateTimeDialog: public Ui_DateTimeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIMEDIALOG_H
