#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
public:
    explicit MyThread(QObject *parent = nullptr);
    void stop();
protected:
    void run();
private:
   bool isStopped;
};

#endif // MYTHREAD_H
