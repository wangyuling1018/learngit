#include "CalculatorDialog.h"

//构造函数
CalculatorDialog::CalculatorDialog(void){
    //界面初始化
    setWindowTitle("计算器"); //设置窗口标题
    //左操作数  this就是当前父窗口指针
    m_editx = new QLineEdit(this);
    //设置文本对齐方式：右对齐
    m_editx->setAlignment(Qt::AlignRight);
    //设置数字验证器，只能输入数字
    m_editx->setValidator(new QDoubleValidator(this));

    //右操作数
    m_edity = new QLineEdit(this);
    m_edity->setAlignment(Qt::AlignRight);
    m_edity->setValidator(new QDoubleValidator(this));

    //结果
    m_editz = new QLineEdit(this);
    m_editz->setAlignment(Qt::AlignRight);
    m_editz->setReadOnly(true); //设置只读

    //“+”
    m_label = new QLabel("+",this);

    //"="
    m_button = new QPushButton("=",this);
    m_button->setEnabled(false);//设置按钮初始为禁用

    //布局
    //创建布局器：自动调整控件的大小和位置
    QHBoxLayout* layout = new QHBoxLayout(this);
    //按照水平方向，自左而右依次放入控件
    layout->addWidget(m_editx);
    layout->addWidget(m_label);
    layout->addWidget(m_edity);
    layout->addWidget(m_button);
    layout->addWidget(m_editz);

    //设置布局
    setLayout(layout);

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
