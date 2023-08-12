#include "sizedialog.h"
#include "ui_sizedialog.h"
#include <QMessageBox>

SizeDialog::SizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeDialog)
{
    ui->setupUi(this);
}

SizeDialog::~SizeDialog()
{
    QMessageBox::information(this,"提示","设置行数和列数的对话框被销毁");
    delete ui;
}

//初始化对话框窗口上的两个QSpinBox
void SizeDialog::setRowColumn(int row,int column){
    ui->spinRow->setValue(row);
    ui->spinColumn->setValue(column);
}
//返回对话框窗口输入的行数
int SizeDialog::rowCnt(){
    return ui->spinRow->value();
}
//返回对话框窗口输入的列数
int SizeDialog::columnCnt(){
    return ui->spinColumn->value();
}
