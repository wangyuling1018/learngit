#include "work.h"
#include <QDebug>
#include <QThread>

Work::Work(QObject *parent)
    : QObject{parent}
{

}
void Work::doWork(){
    while(1){
        for(int i=0;i<10;i++)
            qDebug() << QThread::currentThread() << ":" << i << i << i;
    }
}
