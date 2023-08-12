#include "widget.h"

#include <QApplication>
#include <QThread>
#include <QFile>
#include <QMutex>
#include <QReadWriteLock>
#include <QDebug>
#include <QDir>

QMutex mutex;
QReadWriteLock rwlock;
class ReadThread1:public QThread{
protected:
    void run(){
       //mutex.lock();
       //rwlock.lockForRead();
        QReadLocker locker(&rwlock);
       qDebug() << "读线程1：加锁";
       QString path = QDir::currentPath();
       QFile file(path + "stu.txt");
       if(file.open(QIODevice::ReadOnly)){
           qDebug() << "读线程1:" << file.readAll();
           file.close();
       }else{
           qDebug() << "读线程1:打开文件失败";
       }
       qDebug() << "读线程1:解锁";
       //mutex.unlock();
       //rwlock.unlock();
    }
};

class ReadThread2:public QThread{
protected:
    void run(){
        //mutex.lock();
        //rwlock.lockForRead();
         QReadLocker locker(&rwlock);
       qDebug() << "读线程2：加锁";
       QString path = QDir::currentPath();
       QFile file(path + "stu.txt");
       if(file.open(QIODevice::ReadOnly)){
           qDebug() << "读线程2:" << file.readAll();
           file.close();
       }else{
           qDebug() << "读线程2:打开文件失败";
       }
       qDebug() << "读线程2：解锁";
       //mutex.unlock();
       //rwlock.unlock();
    }
};

class WriteThread1:public QThread{
protected:
    void run(){
        //mutex.lock();
        //rwlock.lockForWrite();
        QWriteLocker locker(&rwlock);
       qDebug() << "写线程1：加锁";
       QString path = QDir::currentPath();
       QFile file(path + "stu.txt");
       if(file.open(QIODevice::Append)){
           file.write("ABCDEFG");
           file.flush();
           sleep(5);
           file.write("HIJKLMN");
           file.close();
       }else{
           qDebug() << "写线程1:打开文件失败";
       }
       qDebug() << "写线程1：解锁";
       //mutex.unlock();
       //rwlock.unlock();
    }
};

class WriteThread2:public QThread{
protected:
    void run(){
       //mutex.lock();
        //rwlock.lockForWrite();
        QWriteLocker locker(&rwlock);
       qDebug() << "写线程2：加锁";
       QString path = QDir::currentPath();
       //qDebug() << path;
       QFile file(path + "stu.txt");
       if(file.open(QIODevice::Append)){
           file.write("1234567");
           file.flush();
           sleep(5);
           file.write("99876543");
           file.close();
       }else{
           qDebug() << "写线程2:打开文件失败";
       }
       qDebug() << "写线程2：解锁";
       //mutex.unlock();
       //rwlock.unlock();
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WriteThread1 write1;
    write1.start();
    WriteThread2 write2;
    write2.start();
    ReadThread1 read1;
    read1.start();
    ReadThread2 read2;
    read2.start();

    //Widget w;
    //w.show();
    return a.exec();
}
