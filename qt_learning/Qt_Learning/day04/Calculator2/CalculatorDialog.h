#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include "ui_CalculatorDialog.h"
#include <QDoubleValidator> //数字验证器

//继承方式
class CalculatorDialog:public QDialog,public Ui::CalculatorDialog{
    Q_OBJECT //moc
public:
    CalculatorDialog(void);
public slots:
    // 自定义槽函数
    //使能等号按钮
    void buttonEnabled(void);
    //计算并显示结果
    void calcRes(void);

};



#endif // CALCULATORDIALOG_H
