/********************************************************************************
** Form generated from reading UI file 'comboboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBOBOXWIDGET_H
#define UI_COMBOBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComboBoxWidget
{
public:
    QAction *actUndo;
    QAction *actRedo;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actDelete;
    QAction *actSelectAll;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnListInit;
    QPushButton *btnListClear;
    QCheckBox *ckbEditable;
    QComboBox *cmbSimple;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnCityZon;
    QComboBox *cmbWithUserData;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnTocmb;
    QPushButton *btnTextClear;
    QCheckBox *ckbReadOnly;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *ComboBoxWidget)
    {
        if (ComboBoxWidget->objectName().isEmpty())
            ComboBoxWidget->setObjectName("ComboBoxWidget");
        ComboBoxWidget->resize(573, 485);
        actUndo = new QAction(ComboBoxWidget);
        actUndo->setObjectName("actUndo");
        actRedo = new QAction(ComboBoxWidget);
        actRedo->setObjectName("actRedo");
        actCut = new QAction(ComboBoxWidget);
        actCut->setObjectName("actCut");
        actCopy = new QAction(ComboBoxWidget);
        actCopy->setObjectName("actCopy");
        actPaste = new QAction(ComboBoxWidget);
        actPaste->setObjectName("actPaste");
        actDelete = new QAction(ComboBoxWidget);
        actDelete->setObjectName("actDelete");
        actSelectAll = new QAction(ComboBoxWidget);
        actSelectAll->setObjectName("actSelectAll");
        gridLayout_4 = new QGridLayout(ComboBoxWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        groupBox = new QGroupBox(ComboBoxWidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        btnListInit = new QPushButton(groupBox);
        btnListInit->setObjectName("btnListInit");

        gridLayout->addWidget(btnListInit, 0, 0, 1, 1);

        btnListClear = new QPushButton(groupBox);
        btnListClear->setObjectName("btnListClear");

        gridLayout->addWidget(btnListClear, 0, 1, 1, 1);

        ckbEditable = new QCheckBox(groupBox);
        ckbEditable->setObjectName("ckbEditable");

        gridLayout->addWidget(ckbEditable, 0, 2, 1, 1);

        cmbSimple = new QComboBox(groupBox);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/unit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        cmbSimple->addItem(icon, QString());
        cmbSimple->addItem(icon, QString());
        cmbSimple->addItem(icon, QString());
        cmbSimple->addItem(icon, QString());
        cmbSimple->setObjectName("cmbSimple");
        cmbSimple->setMaxVisibleItems(10);

        gridLayout->addWidget(cmbSimple, 1, 0, 1, 3);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ComboBoxWidget);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        btnCityZon = new QPushButton(groupBox_2);
        btnCityZon->setObjectName("btnCityZon");

        gridLayout_2->addWidget(btnCityZon, 0, 0, 1, 1);

        cmbWithUserData = new QComboBox(groupBox_2);
        cmbWithUserData->setObjectName("cmbWithUserData");

        gridLayout_2->addWidget(cmbWithUserData, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(ComboBoxWidget);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName("gridLayout_3");
        btnTocmb = new QPushButton(groupBox_3);
        btnTocmb->setObjectName("btnTocmb");

        gridLayout_3->addWidget(btnTocmb, 0, 0, 1, 1);

        btnTextClear = new QPushButton(groupBox_3);
        btnTextClear->setObjectName("btnTextClear");

        gridLayout_3->addWidget(btnTextClear, 0, 1, 1, 1);

        ckbReadOnly = new QCheckBox(groupBox_3);
        ckbReadOnly->setObjectName("ckbReadOnly");

        gridLayout_3->addWidget(ckbReadOnly, 0, 2, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox_3);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout_3->addWidget(plainTextEdit, 1, 0, 1, 3);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 2);


        retranslateUi(ComboBoxWidget);
        QObject::connect(actUndo, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::undo));
        QObject::connect(actRedo, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::redo));
        QObject::connect(actPaste, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::paste));
        QObject::connect(actCopy, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::copy));
        QObject::connect(actCut, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::cut));
        QObject::connect(actDelete, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::clear));
        QObject::connect(actSelectAll, &QAction::triggered, plainTextEdit, qOverload<>(&QPlainTextEdit::selectAll));

        QMetaObject::connectSlotsByName(ComboBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *ComboBoxWidget)
    {
        ComboBoxWidget->setWindowTitle(QCoreApplication::translate("ComboBoxWidget", "ComboBox and QPlainTextEdit", nullptr));
        actUndo->setText(QCoreApplication::translate("ComboBoxWidget", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        actUndo->setShortcut(QCoreApplication::translate("ComboBoxWidget", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actRedo->setText(QCoreApplication::translate("ComboBoxWidget", "\351\207\215\345\201\232", nullptr));
#if QT_CONFIG(shortcut)
        actRedo->setShortcut(QCoreApplication::translate("ComboBoxWidget", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actCut->setText(QCoreApplication::translate("ComboBoxWidget", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        actCut->setShortcut(QCoreApplication::translate("ComboBoxWidget", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actCopy->setText(QCoreApplication::translate("ComboBoxWidget", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        actCopy->setShortcut(QCoreApplication::translate("ComboBoxWidget", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actPaste->setText(QCoreApplication::translate("ComboBoxWidget", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        actPaste->setShortcut(QCoreApplication::translate("ComboBoxWidget", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actDelete->setText(QCoreApplication::translate("ComboBoxWidget", "\345\210\240\351\231\244", nullptr));
        actSelectAll->setText(QCoreApplication::translate("ComboBoxWidget", "\345\205\250\351\200\211", nullptr));
#if QT_CONFIG(shortcut)
        actSelectAll->setShortcut(QCoreApplication::translate("ComboBoxWidget", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QCoreApplication::translate("ComboBoxWidget", "\347\256\200\345\215\225\347\232\204ComboBox", nullptr));
        btnListInit->setText(QCoreApplication::translate("ComboBoxWidget", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
        btnListClear->setText(QCoreApplication::translate("ComboBoxWidget", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        ckbEditable->setText(QCoreApplication::translate("ComboBoxWidget", "\345\217\257\347\274\226\350\276\221", nullptr));
        cmbSimple->setItemText(0, QCoreApplication::translate("ComboBoxWidget", "\345\214\227\344\272\254\345\270\202", nullptr));
        cmbSimple->setItemText(1, QCoreApplication::translate("ComboBoxWidget", "\351\207\215\345\272\206\345\270\202", nullptr));
        cmbSimple->setItemText(2, QCoreApplication::translate("ComboBoxWidget", "\344\270\212\346\265\267\345\270\202", nullptr));
        cmbSimple->setItemText(3, QCoreApplication::translate("ComboBoxWidget", "\345\244\251\346\264\245\345\270\202", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("ComboBoxWidget", "\346\234\211\347\224\250\346\210\267\346\225\260\346\215\256\347\232\204ComboBox", nullptr));
        btnCityZon->setText(QCoreApplication::translate("ComboBoxWidget", "\345\210\235\345\247\213\345\214\226\345\237\216\345\270\202+\345\214\272\345\217\267", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ComboBoxWidget", "QPlainTextEdit\357\274\210\345\205\267\346\234\211\346\240\207\345\207\206\345\277\253\346\215\267\350\217\234\345\215\225\357\274\211", nullptr));
        btnTocmb->setText(QCoreApplication::translate("ComboBoxWidget", "\346\226\207\346\234\254\346\241\206\345\206\205\345\256\271\346\267\273\345\212\240\345\210\260ComboBox", nullptr));
        btnTextClear->setText(QCoreApplication::translate("ComboBoxWidget", "\346\270\205\351\231\244\346\226\207\346\234\254\345\206\205\345\255\230", nullptr));
        ckbReadOnly->setText(QCoreApplication::translate("ComboBoxWidget", "Read Only", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComboBoxWidget: public Ui_ComboBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBOBOXWIDGET_H
