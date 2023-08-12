#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    thread = new QThread;
    work = new Work;
    //将工作对象移动到线程
    work->moveToThread(thread);
    //连接信号和槽
    // 槽函数一旦触发，就会交由目标线程(thread)的exec()处理
    connect(ui->btnStart,SIGNAL(clicked()),work,SLOT(doWork()));
    // 线程结束时，删除工作对象
    connect(thread,SIGNAL(finished()), work, SLOT(deleteLater()));
    //开启线程
    thread->start();
}

Widget::~Widget()
{
    thread->terminate();
    thread->wait();
    delete thread;
    thread = nullptr;
    delete ui;
}

