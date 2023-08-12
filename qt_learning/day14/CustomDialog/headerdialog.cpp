#include "headerdialog.h"
#include "ui_headerdialog.h"

HeaderDialog::HeaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeaderDialog)
{
    ui->setupUi(this);
    headerModel = new QStringListModel(this);
    ui->listView->setModel(headerModel);
}

HeaderDialog::~HeaderDialog()
{
    delete ui;
}

//使用主窗口的model的表头初始化对话框的headerModel
void HeaderDialog::setHeaderList(QStringList& headers){
    headerModel->setStringList(headers);
}
//返回对话框窗口修改后的字符串列表
QStringList HeaderDialog::HeaderList(){
    return headerModel->stringList();
}
