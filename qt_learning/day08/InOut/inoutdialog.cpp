#include "inoutdialog.h"
#include "ui_inoutdialog.h"

InOutDialog::InOutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InOutDialog)
{
    ui->setupUi(this);
}

InOutDialog::~InOutDialog()
{
    delete ui;
}

//计算
void InOutDialog::on_btnCalc_clicked()
{
    int num = ui->spinNum->value();//数量
    double price = ui->dSpinPrice->value();//单价
    double totle = num * price;//总价
    ui->editTotle->setText(QString::number(totle));
}

//十进制--》其他进制
void InOutDialog::on_btnDexTothe_clicked()
{
    int value = ui->spinDec->value();
    ui->spinBin->setValue(value);
    ui->spinHex->setValue(value);
}

//二进制--》其他进制
void InOutDialog::on_btnBinToOthe_clicked()
{
    int value = ui->spinBin->value();
    ui->spinDec->setValue(value);
    ui->spinHex->setValue(value);
}

//十六进制-》其他进制
void InOutDialog::on_btnHexToOthe_clicked()
{
    int value = ui->spinHex->value();
    ui->spinDec->setValue(value);
    ui->spinBin->setValue(value);
}

