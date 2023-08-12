#include "CalculatorDialog.h"

//构造函数
CalculatorDialog::CalculatorDialog(void):ui(new Ui::CalculatorDialog){
    //界面初始化
    ui->setupUi(this);

    //设置数字验证器，只能输入数字
    ui->m_editx->setValidator(new QDoubleValidator(this));
    ui->m_edity->setValidator(new QDoubleValidator(this));

    //信号和槽函数的连接
    // QLineEdit内容发生变化时，发射信号textChanged(const QString &text)
    connect(ui->m_editx,SIGNAL(textChanged(QString)),this,SLOT(buttonEnabled()));
    connect(ui->m_edity,SIGNAL(textChanged(QString)),this,SLOT(buttonEnabled()));
    connect(ui->m_button,SIGNAL(clicked()),this,SLOT(calcRes()));
}

//析构函数
CalculatorDialog::~CalculatorDialog(void){
    delete ui;
    ui = nullptr;
}

//使能等号按钮
void CalculatorDialog::buttonEnabled(void){
    bool bXok,bYok;
    // text():获取编辑框中的文本
    // QString::toDouble(bool*): QString->double 返回值是转换的结果，参数代表是否转换成功
    ui->m_editx->text().toDouble(&bXok);
    ui->m_edity->text().toDouble(&bYok);
    // 当左右操作数都输入了合法的数字时，按钮可用，否则禁用
    ui->m_button->setEnabled(bXok && bYok);
}

//计算结果并显示
void CalculatorDialog::calcRes(void){
    double res = ui->m_editx->text().toDouble() + ui->m_edity->text().toDouble();
    QString str = QString::number(res); // double -> QString
    ui->m_editz->setText(str); //显示字符串结果
}
