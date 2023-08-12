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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editURL;
    QPushButton *btnDownload;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *editPath;
    QPushButton *btnDefaultPath;
    QLabel *label_3;
    QProgressBar *progressBar;
    QCheckBox *ckbIsOpen;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(681, 267);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editURL = new QLineEdit(groupBox);
        editURL->setObjectName("editURL");

        gridLayout->addWidget(editURL, 0, 1, 1, 1);

        btnDownload = new QPushButton(groupBox);
        btnDownload->setObjectName("btnDownload");

        gridLayout->addWidget(btnDownload, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        editPath = new QLineEdit(groupBox_2);
        editPath->setObjectName("editPath");

        gridLayout_2->addWidget(editPath, 0, 1, 1, 1);

        btnDefaultPath = new QPushButton(groupBox_2);
        btnDefaultPath->setObjectName("btnDefaultPath");

        gridLayout_2->addWidget(btnDefaultPath, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 1, 1, 1, 1);

        ckbIsOpen = new QCheckBox(groupBox_2);
        ckbIsOpen->setObjectName("ckbIsOpen");

        gridLayout_2->addWidget(ckbIsOpen, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Widget", "URL", nullptr));
        btnDownload->setText(QCoreApplication::translate("Widget", "\344\270\213\350\275\275", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("Widget", "\344\270\213\350\275\275\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        btnDefaultPath->setText(QCoreApplication::translate("Widget", "\347\274\272\347\234\201\350\267\257\345\276\204", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\344\270\213\350\275\275\350\277\233\345\272\246", nullptr));
        ckbIsOpen->setText(QCoreApplication::translate("Widget", "\345\256\214\346\210\220\345\220\216\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
