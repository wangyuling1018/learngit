#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>

class WorkThread : public QThread
{
public:
    WorkThread();
    void stop();
protected:
    void run();
private:
    bool isStoped;
};

#endif // WORKTHREAD_H
