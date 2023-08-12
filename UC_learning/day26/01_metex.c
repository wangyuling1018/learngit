/*
 线程同步
     ●缺省情况下，一个进程中的线程是以异步方式运行的，即各自运行各自的，彼此间不需要保持步调的协调一致
     ●某些情况下，需要在线程之间建立起某种停等机制，即一或多个线程有时必须停下来，等待另外一或多个线程执行完
      一个特定的步骤以后才能继续执行，这就叫同步
     ●并发冲突问题
         ➢任何时候只允许一个线程持有共享数据，其它线程必须阻塞于调度队列之外，直到数据持有者不再持有该数据为止
     ●资源竞争问题
         ➢任何时候只允许部分线程拥有有限的资源，其它线程必须阻塞于调度队列之外，直到资源拥有者主动释放其所拥有的资源为止
     ●条件等待问题
         ➢当某些条件一时无法满足时，一些线程必须阻塞于调度队列之外，直到令该条件满足的线程用信号唤醒它们为止

 互斥锁
     ●线程间可以通过互斥锁解决资源竞争的问题。
     ●任何时候都只能一个线程持有互斥锁，即加锁成功，在其持有该互斥锁的过程中，其它线程对该锁的加锁动作都会引发阻塞，
     只有当持有互斥锁的线程主动解锁，那些在加锁动作上阻塞的线程中的一个采用恢复运行并加锁成功。
     ●pthread_mutex_t 表示互斥锁数据类型
     
     笔记：
     1、现线程同步的方式一：互斥锁。
     2、互斥锁是2个线程去抢这个把锁，哪个线程抢到，哪个线程去用。
     2、文件锁是2个进程去给已经加了多把锁的文件再去加一把锁，看看新加的锁与文件已经加的锁是否有冲突，如果有冲突就不能再加锁了，
         如果能加上就能访问文件。例如已经有了写锁，再次加一把写锁就加不了。
     
 初始化互斥锁
     #include <pthread h>
     int pthread_mutex_init(pthread_mutex_t* mutex, pthread_mutexattr_t const* attr);
         功能:初始化互斥体
         参数:mutex:互斥体
             attr:互斥体属性
         返回值:成功返回0，失败返回错误码。
     也可以静态方式初始化互斥锁:
         pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER；  //常用的初始化锁


 销毁互斥锁
     # include <pthread_h>
     int pthread_mutex_destroy(pthread_mutex_t* mutex);
         功能:销毁互斥体
         参数:mutex:互斥体
         返回值:成功返回0，失败返回错误码。

 锁定互斥锁
     #include < pthread.h>
     int pthread_mutex_lock (pthread_mutex_t* mutex);
         功能:锁定互斥体
         参数: mutex互斥体
         成功:返回0，失败返回错误码


 解锁互斥锁
     #include <pthread.h>
     int pthread_mutex_unlock(pthread_mutex_t*mutex);
         功能:解锁互斥锁
         参数:mutex互斥锁
         成功:返回0，失败返回错误码
 */
#if 0

//互斥锁
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int a = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//线程过程函数
void* pthread_add(void* arg){
    //加锁
    //pthread_mutex_lock(&mutex);
    for(int i = 0;i < 100000;i++){
        pthread_mutex_lock(&mutex);
        a++;
        pthread_mutex_unlock(&mutex);
    }
    //解锁
    //pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(void){
    //pthread_mutex_t mutex; //不能放在main中，子线程无法拿到该锁
    pthread_t t1,t2;
    pthread_create(&t1,NULL,pthread_add,NULL);
    pthread_create(&t2,NULL,pthread_add,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("a = %d\n",a);
    return 0;
}
#endif

/*
 (base) 176x212x32x33:day26 wyl$ gcc 01_metex.c -o m
 (base) 176x212x32x33:day26 wyl$ ./m
 a = 200000
 (base) 176x212x32x33:day26 wyl$ ./m
 a = 200000
 (base) 176x212x32x33:day26 wyl$ ./m
 a = 200000
 */
