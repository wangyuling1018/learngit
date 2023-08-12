#include "mythread.h"
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

static int cnt = 0;
static QMutex mutex;

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{
    isStopped = false;
}

void MyThread::run(){
    while(!isStopped){
        //mutex.lock();  // 锁定互斥量  死等，阻塞函数，与unlock一起使用
        //while(!mutex.tryLock(100)) //不死等，尝试失败后，就去干其他事情，与unlock一起使用
        //    qDebug() << currentThread() << "尝试加锁失败";
        QMutexLocker locker(&mutex);// 构造QMutexLocker,同时锁定mutex
        cnt += 1;
        qDebug() << cnt << ":" << currentThread();
        //mutex.unlock();// 解锁互斥量
        msleep(500);
    }// 调用 ~QMutexLocker()：解锁mutex    销毁QMutexLocker
    isStopped = false;
}
void MyThread::stop(){
    isStopped = true;
}

