#include "widget.h"

#include <QApplication>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>
#include <QThread>
#include <QTime>
#include <QRandomGenerator>
#include <cstdlib>

#define DATASIZE 100
#define BUFFERSIZE 8
int buffer[BUFFERSIZE];//缓冲区
QWaitCondition bufferNotEmpty;//非空
QWaitCondition bufferNoFull;   //非满

int numUsable = 0; //可用数据数（0～BUFFERSIZE）
int indexx = 0; //消费者消费数据的索引

QMutex mutex;
//生产者线程
class ProducerThread:public QThread{
protected:
    void run(){
        for(int i = 0; i< 100;i++){
            mutex.lock();
            if(numUsable == BUFFERSIZE){//缓冲区已满
                qDebug() << "缓冲区已满，等等。。。";
                bufferNoFull.wait(&mutex);//等待缓冲区有空位（bufferNotFull条件成立） //解锁让消费者去拿数据，等待消费者拿完后有空位，我再去存数据
            }
            buffer[i%BUFFERSIZE] = i+1;//缓冲区未满，向缓冲区写入一个数字 //取余是为了循环存入数据
            ++numUsable;
            qDebug() << "生产者生产了数据：" << (i+1);
            msleep(QRandomGenerator::global()->bounded(100,500));
            mutex.unlock();
            bufferNotEmpty.wakeAll();//唤醒等待缓冲区有数据（bufferNotEmpty条件成立）的线程 //告诉所有消费者，缓冲区现在有数据
        }
    }
};

//消费者线程
class ComsumerThread:public QThread{
protected:
    void run(){
        for(int i= 0;i<100;i++){
            mutex.lock();
            if(numUsable == 0){//缓冲区为空
                qDebug() << "缓冲区已空，等待...";
                bufferNotEmpty.wait(&mutex);//等待缓冲区有数据（bufferNotEmpty条件成立） //解锁让生产者放数据，等待缓冲区有数据了，我再去拿
            }
            qDebug() <<"消费者" << currentThreadId() << "消费了数据：" << buffer[indexx];
            --numUsable;
            indexx = (++indexx)%BUFFERSIZE;//取余是为了循环取数据
            msleep(QRandomGenerator::global()->bounded(100,500));
            mutex.unlock();
            bufferNoFull.wakeAll();//唤醒等待缓冲区有空位（buffNotFull条件成立） //告诉生产者，缓冲区有空位可用放数据了
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRandomGenerator::global()->bounded(QTime::currentTime().msec());

    ProducerThread producer;
    producer.start();
    ComsumerThread comsumer;
    comsumer.start();
    ComsumerThread comsumer2;
    comsumer2.start();

    producer.wait();
    comsumer.wait();
    comsumer2.wait();



    //Widget w;
    //w.show();
    return a.exec();
}
