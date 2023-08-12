#include "locatedialog.h"
#include "ui_locatedialog.h"

LocateDialog::LocateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LocateDialog)
{
    ui->setupUi(this);
}

LocateDialog::~LocateDialog()
{
    delete ui;
}
//窗口显示事件处理函数
void LocateDialog::showEvent(QShowEvent*){
    emit changeActioneEnabled(false);
}
//窗口关闭事件处理函数
void LocateDialog::closeEvent(QCloseEvent*){
    emit changeActioneEnabled(true);
}

//设置spinBox的输入最大值
void LocateDialog::setSpinRange(int rowcnt,int colCnt){
    ui->spinRow->setMaximum(rowcnt-1);
    ui->spinColumn->setMaximum(colCnt-1);
}
// 响应主窗口的信号，设置spinBox的当前值
void LocateDialog::setSpinValue(int rowNo,int colNo){
    ui->spinRow->setValue(rowNo);
    ui->spinColumn->setValue(colNo);
}
// "设定文字": 发射信号
void LocateDialog::on_btnSetText_clicked()
{
    int rowNo = ui->spinRow->value();
    int colNo = ui->spinColumn->value();
    QString text = ui->lineEditSetText->text();
    emit changedCellText(rowNo,colNo,text);
}

