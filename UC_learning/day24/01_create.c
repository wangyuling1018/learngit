/*
 #include <pthread.h>
 int pthread_create(pthread_t* tid, pthread_attr_t const* attr,
 void*(*start_routine)(void*),void* arg)
     功能:创建新线程
     参数:tid:输出线程ID。pthread_t即unsigned long int
         attr:线程属性，NULL表示缺省属性。                               //一般为NULL
         start_routine:线程过程函数指针，所指向的函数将在被创建的线程中执行。 //函数指针，指向void* ()(void*)类型的函数，该函数就是一个线程，这个函数叫线程过程函数
         arg:传递给线程过程函数的参数。
     返回值:成功返回0,失败返回错误码!
     
 ●线程过程函数
     ➢void* thread_proc(void* arg){ ...}
     ➢定义线程过程函数，该函数会在所创建的线程中被执行，代表了线程的任务。
     ➢而main函数其实就是主线程的线程过程函数。
     ➢main函数一旦返回，主线程即告结束。主线程一旦结束， 进程即告结束。进程一旦结束 , 其所有的子线程统统结束
     
 ●补充说明:
     ➢A.pthread_create函数本身并不调用线程过程函数，而是在系统内核中开启独立的线程， 并立即返回，在该线程中
      执行线程过程函数。
     ➢B.pthread_create函数返回时，所指定的线程过程函数可能尚未执行，也可能正在执行,甚至可能已经执行完毕。
     ➢C.主线程和通过pthread_create函数创建的多个子线程，在时间上"同时"运行，如果不附加任何同步条件，则它们每一
      个执行步骤的先后顺序是完全无法确定的，这就叫做自由并发。
 */

#if 0
//线程的创建
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h> //sleep

//线程过程函数
void* pthread_fun(void* arg){
    printf("%ld线程:我是子线程\n",pthread_self());//getpid()
    printf("%ld线程:接受到-->%s\n",pthread_self(),(char*)arg);
    return NULL;
}

int main(void){
    printf("%ld线程:我是主线程,我要创建子线程\n",pthread_self());
    pthread_t tid;//用来输出线程的ID
    int error = pthread_create(&tid,NULL,pthread_fun,"hello world!"); //每个线程都有独立的错误码
    if(error){
        fprintf(stderr,"pthread_create:%s\n",strerror(error)); //不能用perror、全局变量errno，不知道是主线程还是子线程最近一次出错
        return -1;
    }
    printf("%ld线程:我是主线程,我创建了子线程%ld\n",pthread_self(),tid);
    sleep(1);//主线程阻塞,保证子线程执行完毕
    return 0;
}
#endif
/*
 (base) 176x212x32x15:day24 wyl$ gcc 01_create.c -o create -lpthread     //linux下要链接库编译 -pthread 或 -lpthread
 (base) 176x212x32x15:day24 wyl$ ./create.out
 4683355648线程:我是主线程,我要创建子线程
 4683355648线程:我是主线程,我创建了子线程123145366081536
 123145366081536线程:我是子线程
 123145366081536线程:接受到-->hello world!
 */
