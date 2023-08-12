#include "calculatordialog.h"
#include "ui_calculatordialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalculatorDialog)
{
    ui->setupUi(this);
    connect(ui->m_editx,SIGNAL(textChanged(QString)),this,SLOT(on_m_editOperator_textChanged(QString)));
    connect(ui->m_edity,SIGNAL(textChanged(QString)),this,SLOT(on_m_editOperator_textChanged(QString)));
}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}

//点击按钮后，计算并显示结果
void CalculatorDialog::on_m_button_clicked()//通过ui中的右键创建的槽函数，不需要手动写connect
{
    double res = ui->m_editx->text().toDouble() + ui->m_edity->text().toDouble();
    ui->m_editz->setText(QString::number(res));

}

//使能等号按钮
void CalculatorDialog::on_m_editOperator_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);//告诉编译器，arg1是不使用的，不然有个黄色的提示
    bool bXOK,bYOK;
    ui->m_editx->text().toDouble(&bXOK);
    ui->m_edity->text().toDouble(&bYOK);
    ui->m_button->setEnabled(bXOK && bYOK);
}

