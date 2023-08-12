/********************************************************************************
** Form generated from reading UI file 'showimagesdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWIMAGESDIALOG_H
#define UI_SHOWIMAGESDIALOG_H

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

class Ui_ShowImagesDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrev;
    QPushButton *btnNext;

    void setupUi(QDialog *ShowImagesDialog)
    {
        if (ShowImagesDialog->objectName().isEmpty())
            ShowImagesDialog->setObjectName("ShowImagesDialog");
        ShowImagesDialog->resize(408, 491);
        gridLayout = new QGridLayout(ShowImagesDialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(ShowImagesDialog);
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

        btnPrev = new QPushButton(ShowImagesDialog);
        btnPrev->setObjectName("btnPrev");

        horizontalLayout->addWidget(btnPrev);

        btnNext = new QPushButton(ShowImagesDialog);
        btnNext->setObjectName("btnNext");

        horizontalLayout->addWidget(btnNext);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ShowImagesDialog);

        QMetaObject::connectSlotsByName(ShowImagesDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowImagesDialog)
    {
        ShowImagesDialog->setWindowTitle(QCoreApplication::translate("ShowImagesDialog", "ShowImagesDialog", nullptr));
        btnPrev->setText(QCoreApplication::translate("ShowImagesDialog", "\344\270\212\344\270\200\351\241\265", nullptr));
        btnNext->setText(QCoreApplication::translate("ShowImagesDialog", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowImagesDialog: public Ui_ShowImagesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWIMAGESDIALOG_H
