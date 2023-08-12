#include "clockwidget.h"
#include "ui_clockwidget.h"
#include <QTime>

ClockWidget::ClockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClockWidget)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);//创建定时器
    m_timer->start(1000);//启动定时器，1秒钟发一次

    //信号和槽函数的连接
    connect(m_timer,SIGNAL(timeout()),this,SLOT(onTimerTimeout()));

}

ClockWidget::~ClockWidget()
{
    m_timer->stop();//停止定时器
    delete ui;
}

//定时器超时的槽函数
void ClockWidget::onTimerTimeout(){
    QTime curTime = QTime::currentTime();// 获取当前时间
    ui->lcdHour->display(curTime.hour());// 小时
    ui->lcdMinute->display(curTime.minute());// 分钟
    ui->lcdSecond->display(curTime.second());// 秒

}
