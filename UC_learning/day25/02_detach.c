/*
 什么是分离线程
     ●一个线程在默认情况下都是可汇合线程，这样的线程在终止以后其资源会被保留，其中含有线程过程函数的返回值及线程ID等信息，
     父线程可以通过pthread_join函数获得线程过程函数的返回值，同时释放这些资源。如果在创建线程以后，对其调用
     pthread_detach函数并返回成功，该线程即成为分离线程，这样的线程终止以后其资源会被系统自动回收，不需要也无法通过pthread_join函数汇合它。

 分离线程
     #include < pthread.h>
     int pthread detach(pthread t tid);
         功能:使指定的线程进入分离状态
         参数: tid线程的ID
         返回值:成功返回0，失败返回错误码。
 笔记：
     1、由于pthread_join函数是阻塞函数，pthread_join收资源就会阻塞主函数，某些情况主线程不能阻塞，有没有两全其美的方法，
     我既能收资源又不阻塞主线程？分离线程，默认情况下线程是可回收的，可汇入的，但是我们可以把这个线程设置成分离线程，如果这个
     线程具有分离属性的话，这个线程不需要主线程去回收，内核去回收线程的资源。
     2、pthread_join不能和设置分离属性(pthread_detach)一起使用，否则报错。
 */
#if 0
//分离线程
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
//线程过程函数
void* pthread_fun(void* arg){
    for(int i = 0;i < 100;i++){
        putchar('-');
        usleep(50000); //0.05秒
    }
    return NULL;
}

int main(void){
    setbuf(stdout,NULL);//关闭输出缓冲区
    pthread_t tid;
    pthread_attr_t attr;//线程的属性
    pthread_attr_init(&attr);//初始化
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);//将分离属性给attr
    //int error = pthread_create(&tid, NULL, pthread_fun, NULL);
    int error = pthread_create(&tid,&attr,pthread_fun,NULL); //创建线程，同时设置tid具有attr内的属性
    if(error){
        fprintf(stderr,"pthread_create:%s\n",strerror(error));
        return -1;
    }
    
    //设置成分离线程
    /*
    error = pthread_detach(tid);
    if(error){
        fprintf(stderr,"pthread_detach:%s\n",strerror(error));
        return -1;
    }*/
    
    /*
    error = pthread_join(tid,NULL);
    if(error){
        fprintf(stderr,"pthread_join:%s\n",strerror(error));
        return -1;
    }
    //pthread_detach和pthread_join不能同时存在，否则报错
    */
    for(int i = 0;i < 100;i++){
        putchar('+');
        usleep(100000);
    }
    return 0;
}
#endif
/* pthread_join会阻塞主线程
 (base) 176x212x32x33:day25 wyl$ gcc 02_detach.c -o de
 (base) 176x212x32x33:day25 wyl$ ./de
 ----------------------------------------------------------------------------------------------------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++(base) 176x212x32x33:day25 wyl$
 */

/* pthread_detac不会阻塞主线程，主线程和子线程各自跑各自的
 (base) 176x212x32x33:day25 wyl$ gcc 02_detach.c -o de
 (base) 176x212x32x33:day25 wyl$ ./de
 +--+--+--+--+--+--+--+--+--+--+-+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-+--+--+--+--+--+--+--+-++++++++++++++++++++++++++++++++++++++++++++++++(base) 176x212x32x33:day25 wyl$
 */

/*
 (base) 176x212x32x33:day25 wyl$ gcc 02_detach.c -o de
 (base) 176x212x32x33:day25 wyl$ ./de
 +--+--+--+--+--+--+--+--+--+--+--+--+--+--+-+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+-+--+--+--+--+--+-^C
 */
