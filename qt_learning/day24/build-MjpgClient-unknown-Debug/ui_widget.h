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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *labelMjpg;
    QLabel *labelJpeg;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnMjpg;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnJpeg;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(625, 423);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        labelMjpg = new QLabel(Widget);
        labelMjpg->setObjectName("labelMjpg");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(labelMjpg->sizePolicy().hasHeightForWidth());
        labelMjpg->setSizePolicy(sizePolicy);
        labelMjpg->setFrameShape(QFrame::Box);
        labelMjpg->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelMjpg, 0, 0, 1, 1);

        labelJpeg = new QLabel(Widget);
        labelJpeg->setObjectName("labelJpeg");
        labelJpeg->setFrameShape(QFrame::Box);
        labelJpeg->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(labelJpeg, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnMjpg = new QPushButton(Widget);
        btnMjpg->setObjectName("btnMjpg");

        horizontalLayout->addWidget(btnMjpg);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnJpeg = new QPushButton(Widget);
        btnJpeg->setObjectName("btnJpeg");

        horizontalLayout_2->addWidget(btnJpeg);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\277\234\347\250\213\350\247\206\351\242\221\347\233\221\346\216\247\347\263\273\347\273\237", nullptr));
        labelMjpg->setText(QString());
        labelJpeg->setText(QString());
        btnMjpg->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\350\247\206\351\242\221", nullptr));
        btnJpeg->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\345\277\253\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
