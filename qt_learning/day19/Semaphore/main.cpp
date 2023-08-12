#include "dialog.h"

#include <QApplication>
#include <QSemaphore> //信号量
#include <QDebug>
#include <QRandomGenerator>
#include <QTime>
#include <QThread>

#define DATASIZE 100
#define BUFFERSIZE 8

int buffer[BUFFERSIZE];
QSemaphore freeSpaces(BUFFERSIZE); //生产者信号量(可用空位数)
QSemaphore dataSpaces(0);        //消费者信号量（可用数据数）

//生产者线程
class ProducerThread:public QThread{
protected:
    void run(){
        for(int i=0;i<DATASIZE;i++){
            freeSpaces.acquire(1);//获取一个生产者信号量（获取一个空位)
            buffer[i%BUFFERSIZE] = i+1;
            qDebug() << "生产者生产了数据：" << (i+1);
            //生产者生产了一个数据，对于生产者而言是使用了一个空位资源，对于消费者而言，是增加了一个可用的数据
            dataSpaces.release(1);
            msleep(QRandomGenerator::global()->bounded(100,500));
        }
    }
};

//消费者线程
class ConsumerThread:public QThread{
protected:
    void run(){
        for(int i=0;i<DATASIZE;i++){
            dataSpaces.acquire(1);//获取一个消费者信号量（获取一个数据）
            qDebug() << "消费者消费了数据：" << buffer[i%BUFFERSIZE];
            //消费者消费了一个数据，对于生产者而言，就是多了一个空位
            freeSpaces.release(1);
            msleep(QRandomGenerator::global()->bounded(100,500));
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QRandomGenerator::global()->bounded(QTime::currentTime().msec());
    ProducerThread producer;
    producer.start();
    ConsumerThread comsumer;
    comsumer.start();

    producer.wait();
    comsumer.wait();

    //Dialog w;
    //w.show();
    return a.exec();
}
