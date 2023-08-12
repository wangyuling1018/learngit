#include "CalculatorDialog.h"

//构造函数
CalculatorDialog::CalculatorDialog(void){
    //界面初始化
    setupUi(this);

    //设置数字验证器，只能输入数字
    m_editx->setValidator(new QDoubleValidator(this));
    m_edity->setValidator(new QDoubleValidator(this));

    //信号和槽函数的连接
    // QLineEdit内容发生变化时，发射信号textChanged(const QString &text)
    connect(m_editx,SIGNAL(textChanged(QString)),this,SLOT(buttonEnabled()));
    connect(m_edity,SIGNAL(textChanged(QString)),this,SLOT(buttonEnabled()));
    connect(m_button,SIGNAL(clicked()),this,SLOT(calcRes()));
}

//使能等号按钮
void CalculatorDialog::buttonEnabled(void){
    bool bXok,bYok;
    // text():获取编辑框中的文本
    // QString::toDouble(bool*): QString->double 返回值是转换的结果，参数代表是否转换成功
    m_editx->text().toDouble(&bXok);
    m_edity->text().toDouble(&bYok);
    // 当左右操作数都输入了合法的数字时，按钮可用，否则禁用
    m_button->setEnabled(bXok && bYok);
}

//计算结果并显示
void CalculatorDialog::calcRes(void){
    double res = m_editx->text().toDouble() + m_edity->text().toDouble();
    QString str = QString::number(res); // double -> QString
    m_editz->setText(str); //显示字符串结果
}
