#include "workthread.h"
#include <QDebug>

WorkThread::WorkThread()
{
    isStoped = false;
}

void WorkThread::run(){
    while(!isStoped){
        for(int i = 0;i < 10; i++){
            qDebug() <<QThread::currentThreadId() << ":" << i << i <<i;
        }
    }
    //isStoped = false;
}

void WorkThread::stop(){
    isStoped = true;
}
