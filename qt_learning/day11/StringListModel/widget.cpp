#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model  = new QStringListModel(this);// 创建数据模型
    QStringList strList;
    strList << "北京" << "上海" << "天津" << "重庆" << "河北" << "河南" << "广州" << "四川";
    model->setStringList(strList);//导入striList的内容
    ui->listView->setModel(model);//设置数据模型
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked /*双击后可编辑*/
                                  | QAbstractItemView::SelectedClicked /*选中后单击可编辑*/);//设置listview可编辑的触发
}

Widget::~Widget()
{
    delete ui;
}

//恢复列表
void Widget::on_btnListInit_clicked()
{
    QStringList strList;
    strList << "北京" << "上海" << "天津" << "重庆" << "河北" << "河南" << "广州" << "四川";
    model->setStringList(strList);//导入striList的内容
}

//添加项
void Widget::on_btnItemAppend_clicked()
{
    model->insertRow(model->rowCount());// 在尾部添加一行
    QModelIndex index = model->index(model->rowCount()-1,0,QModelIndex());
    model->setData(index,QString("New Append Item"),Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);// 设置当前选中的行

}

//插入项
void Widget::on_btnItemInsert_clicked()
{
    QModelIndex index = ui->listView->currentIndex();// 当前项的模型索引
    model->insertRow(index.row(),QModelIndex());
    model->setData(index,QString("New Insert Item"),Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);// 设置当前选中的行
}

//删除当前项
void Widget::on_btnItemDelete_clicked()
{
    QModelIndex index = ui->listView->currentIndex();// 当前项的模型索引
    model->removeRow(index.row());
}

//清除列表
void Widget::on_btnItemClear_clicked()
{
    model->removeRows(0,model->rowCount());
}

//显示数据模型StringList
void Widget::on_bntDisplay_clicked()
{
    ui->plainTextEdit->clear();
    QStringList strList;
    strList = model->stringList();
    for(int i = 0; i < strList.size(); i++){
        ui->plainTextEdit->appendPlainText(strList.at(i));
    }
}

// 清空文本
void Widget::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}

//点击listView时，在label中显示当前项的行列号
void Widget::on_listView_clicked(const QModelIndex &index)
{
    ui->labelCurlItem->setText(QString("当前项的行号：%1 ,列号：%2").arg(index.row()).arg(index.column()));
}

