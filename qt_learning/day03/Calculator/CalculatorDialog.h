#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit> //单行文本编辑器
#include <QDoubleValidator> //数字验证器
#include <QHBoxLayout> //水平布局器

class CalculatorDialog:public QDialog{
    Q_OBJECT //Macros
public:
    CalculatorDialog(void);
public slots:
    // 自定义槽函数
    //使能等号按钮
    void buttonEnabled(void);
    //计算并显示结果
    void calcRes(void);
private:
    QLineEdit* m_editx; //左操作数
    QLineEdit* m_edity; //右操作数
    QLineEdit* m_editz; //显示结果
    QLabel* m_label;    //“+”
    QPushButton* m_button; //“=”

};



#endif // CALCULATORDIALOG_H
