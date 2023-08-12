#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnStop->setEnabled(false);
    qDebug() <<"主线程："<< QThread::currentThreadId() << "开始运行.....";

}

Widget::~Widget()
{
    delete ui;
}

//开始
void Widget::on_btnStart_clicked()
{
    //创建主线程
    for(int i = 0; i < MAXSIZE; i++)
        workThread[i] = new WorkThread;
    //启动主线程
    for(int i = 0; i < MAXSIZE; i++)
        workThread[i]->start();

    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);

}

//停止
void Widget::on_btnStop_clicked()
{
    for(int i = 0; i < MAXSIZE; i++){
        workThread[i]->stop();
        workThread[i]->wait();
        workThread[i] = Q_NULLPTR;
    }
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
}

