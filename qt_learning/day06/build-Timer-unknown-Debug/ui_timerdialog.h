/********************************************************************************
** Form generated from reading UI file 'timerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERDIALOG_H
#define UI_TIMERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimerDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_button;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *TimerDialog)
    {
        if (TimerDialog->objectName().isEmpty())
            TimerDialog->setObjectName("TimerDialog");
        TimerDialog->resize(424, 479);
        gridLayout = new QGridLayout(TimerDialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(TimerDialog);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_button = new QPushButton(TimerDialog);
        m_button->setObjectName("m_button");

        horizontalLayout->addWidget(m_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(TimerDialog);

        QMetaObject::connectSlotsByName(TimerDialog);
    } // setupUi

    void retranslateUi(QDialog *TimerDialog)
    {
        TimerDialog->setWindowTitle(QCoreApplication::translate("TimerDialog", "TimerDialog", nullptr));
        m_button->setText(QCoreApplication::translate("TimerDialog", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerDialog: public Ui_TimerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERDIALOG_H
