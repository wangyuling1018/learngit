#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include "ui_CalculatorDialog.h"
#include <QDoubleValidator> //数字验证器

//组合方式
class CalculatorDialog:public QDialog{
    Q_OBJECT //moc
public:
    CalculatorDialog(void);
    ~CalculatorDialog(void);
public slots:
    // 自定义槽函数
    //使能等号按钮
    void buttonEnabled(void);
    //计算并显示结果
    void calcRes(void);
private:
    Ui::CalculatorDialog* ui;//界面类成员，将来通过"ui->"访问界面类的公有成员

};



#endif // CALCULATORDIALOG_H
