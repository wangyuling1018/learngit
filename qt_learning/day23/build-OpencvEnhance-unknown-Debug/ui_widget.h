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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelView;
    QSlider *verticalSliderContrast;
    QSlider *verticalSliderBrightness;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(955, 506);
        labelView = new QLabel(Widget);
        labelView->setObjectName("labelView");
        labelView->setGeometry(QRect(10, 10, 811, 471));
        verticalSliderContrast = new QSlider(Widget);
        verticalSliderContrast->setObjectName("verticalSliderContrast");
        verticalSliderContrast->setGeometry(QRect(840, 10, 27, 461));
        verticalSliderContrast->setMaximum(100);
        verticalSliderContrast->setValue(33);
        verticalSliderContrast->setOrientation(Qt::Vertical);
        verticalSliderContrast->setTickPosition(QSlider::TicksBelow);
        verticalSliderContrast->setTickInterval(5);
        verticalSliderBrightness = new QSlider(Widget);
        verticalSliderBrightness->setObjectName("verticalSliderBrightness");
        verticalSliderBrightness->setGeometry(QRect(900, 10, 27, 461));
        verticalSliderBrightness->setMaximum(100);
        verticalSliderBrightness->setOrientation(Qt::Vertical);
        verticalSliderBrightness->setTickPosition(QSlider::TicksBelow);
        verticalSliderBrightness->setTickInterval(5);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(830, 480, 40, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(900, 480, 27, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labelView->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "\345\257\271\346\257\224\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\272\256\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
