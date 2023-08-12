/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnOpenFile;
    QPushButton *btnOpenFiles;
    QPushButton *btnExitDir;
    QPushButton *btnSaveFile;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *btnInformation;
    QPushButton *btnQuestion;
    QPushButton *btnWarning;
    QPushButton *btnCritical;
    QPushButton *btnAbout;
    QPushButton *btnAboutQt;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QPushButton *btnGetColor;
    QPushButton *btnGetFont;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QPushButton *btnGetText;
    QPushButton *btnGetInt;
    QPushButton *btnTextClear;
    QPushButton *btnGetDouble;
    QPushButton *btnGetItem;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(579, 475);
        gridLayout_5 = new QGridLayout(Dialog);
        gridLayout_5->setObjectName("gridLayout_5");
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        btnOpenFile = new QPushButton(groupBox);
        btnOpenFile->setObjectName("btnOpenFile");

        gridLayout->addWidget(btnOpenFile, 0, 0, 1, 1);

        btnOpenFiles = new QPushButton(groupBox);
        btnOpenFiles->setObjectName("btnOpenFiles");

        gridLayout->addWidget(btnOpenFiles, 0, 1, 1, 1);

        btnExitDir = new QPushButton(groupBox);
        btnExitDir->setObjectName("btnExitDir");

        gridLayout->addWidget(btnExitDir, 1, 0, 1, 1);

        btnSaveFile = new QPushButton(groupBox);
        btnSaveFile->setObjectName("btnSaveFile");

        gridLayout->addWidget(btnSaveFile, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        btnInformation = new QPushButton(groupBox_2);
        btnInformation->setObjectName("btnInformation");

        gridLayout_3->addWidget(btnInformation, 0, 0, 1, 1);

        btnQuestion = new QPushButton(groupBox_2);
        btnQuestion->setObjectName("btnQuestion");

        gridLayout_3->addWidget(btnQuestion, 0, 1, 1, 1);

        btnWarning = new QPushButton(groupBox_2);
        btnWarning->setObjectName("btnWarning");

        gridLayout_3->addWidget(btnWarning, 1, 0, 1, 1);

        btnCritical = new QPushButton(groupBox_2);
        btnCritical->setObjectName("btnCritical");

        gridLayout_3->addWidget(btnCritical, 1, 1, 1, 1);

        btnAbout = new QPushButton(groupBox_2);
        btnAbout->setObjectName("btnAbout");

        gridLayout_3->addWidget(btnAbout, 2, 0, 1, 1);

        btnAboutQt = new QPushButton(groupBox_2);
        btnAboutQt->setObjectName("btnAboutQt");

        gridLayout_3->addWidget(btnAboutQt, 2, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 1, 2, 1);

        groupBox_4 = new QGroupBox(Dialog);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName("gridLayout_2");
        btnGetColor = new QPushButton(groupBox_4);
        btnGetColor->setObjectName("btnGetColor");

        gridLayout_2->addWidget(btnGetColor, 0, 0, 1, 1);

        btnGetFont = new QPushButton(groupBox_4);
        btnGetFont->setObjectName("btnGetFont");

        gridLayout_2->addWidget(btnGetFont, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName("gridLayout_4");
        btnGetText = new QPushButton(groupBox_3);
        btnGetText->setObjectName("btnGetText");

        gridLayout_4->addWidget(btnGetText, 0, 0, 1, 1);

        btnGetInt = new QPushButton(groupBox_3);
        btnGetInt->setObjectName("btnGetInt");

        gridLayout_4->addWidget(btnGetInt, 0, 1, 1, 1);

        btnTextClear = new QPushButton(groupBox_3);
        btnTextClear->setObjectName("btnTextClear");

        gridLayout_4->addWidget(btnTextClear, 0, 2, 1, 1);

        btnGetDouble = new QPushButton(groupBox_3);
        btnGetDouble->setObjectName("btnGetDouble");

        gridLayout_4->addWidget(btnGetDouble, 1, 0, 1, 1);

        btnGetItem = new QPushButton(groupBox_3);
        btnGetItem->setObjectName("btnGetItem");

        gridLayout_4->addWidget(btnGetItem, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 2, 0, 1, 2);

        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout_5->addWidget(plainTextEdit, 3, 0, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", nullptr));
        btnOpenFile->setText(QCoreApplication::translate("Dialog", "\346\211\223\345\274\200\344\270\200\344\270\252\346\226\207\344\273\266", nullptr));
        btnOpenFiles->setText(QCoreApplication::translate("Dialog", "\346\211\223\345\274\200\345\244\232\344\270\252\346\226\207\344\273\266", nullptr));
        btnExitDir->setText(QCoreApplication::translate("Dialog", "\351\200\211\346\213\251\345\267\262\346\234\211\347\233\256\345\275\225", nullptr));
        btnSaveFile->setText(QCoreApplication::translate("Dialog", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", nullptr));
        btnInformation->setText(QCoreApplication::translate("Dialog", "information", nullptr));
        btnQuestion->setText(QCoreApplication::translate("Dialog", "question", nullptr));
        btnWarning->setText(QCoreApplication::translate("Dialog", "warning", nullptr));
        btnCritical->setText(QCoreApplication::translate("Dialog", "critical", nullptr));
        btnAbout->setText(QCoreApplication::translate("Dialog", "about", nullptr));
        btnAboutQt->setText(QCoreApplication::translate("Dialog", "aboutQt", nullptr));
        groupBox_4->setTitle(QString());
        btnGetColor->setText(QCoreApplication::translate("Dialog", "\351\200\211\346\213\251\351\242\234\350\211\262", nullptr));
        btnGetFont->setText(QCoreApplication::translate("Dialog", "\351\200\211\346\213\251\345\255\227\344\275\223", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Dialog", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", nullptr));
        btnGetText->setText(QCoreApplication::translate("Dialog", "\350\276\223\345\205\245\345\255\227\347\254\246\344\270\262", nullptr));
        btnGetInt->setText(QCoreApplication::translate("Dialog", "\350\276\223\345\205\245\346\225\264\346\225\260", nullptr));
        btnTextClear->setText(QCoreApplication::translate("Dialog", "\346\270\205\347\251\272\346\226\207\346\234\254\345\206\205\345\256\271", nullptr));
        btnGetDouble->setText(QCoreApplication::translate("Dialog", "\350\276\223\345\205\245\346\265\256\347\202\271\346\225\260", nullptr));
        btnGetItem->setText(QCoreApplication::translate("Dialog", "\346\235\241\347\233\256\351\200\211\346\213\251\350\276\223\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
