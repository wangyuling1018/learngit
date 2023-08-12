#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);//创建数据模型
    model->setRootPath(QDir::currentPath());//设置根目录

    ui->listView->setModel(model);//设置视图的数据模型
    ui->tableView->setModel(model);
    ui->treeView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

//点击treeview时，在窗口底部的控件中显示当前目录（文件）的信息
void Widget::on_treeView_clicked(const QModelIndex &index)
{
    ui->ckbIsDir->setChecked(model->isDir(index));//是否是目录
    ui->labelFileName->setText(model->fileName(index));//文件名
    ui->labelFilePath->setText(model->filePath(index));//路径
    ui->labelType->setText((model->type(index)));//类型
    int sz = model->size(index)/1024;//字节数（KB）
    if(sz < 1024) // <1M
        ui->labelSize->setText(QString("%1 KB").arg(sz));
    else
        ui->labelSize->setText(QString::asprintf("%.1f MB",sz/1024.0));
}

