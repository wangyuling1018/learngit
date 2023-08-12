#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnStart_clicked()
{
    myThread1.start();
    myThread2.start();
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
}


void Widget::on_btnStop_clicked()
{
    myThread1.stop();
    myThread2.stop();
    myThread1.wait();
    myThread2.wait();
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);

}

