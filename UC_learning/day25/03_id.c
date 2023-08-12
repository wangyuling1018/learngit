/*
 线程ID
     笔记：
         Pthread_t类型是POSIX标准提供的，表示不同的线程id，不同的操作系统都支持pthread_t类型，该类型可能有的系统
     是long int，有的系统可能是unsigned long，有的系统是struct结构体，pthread_t只是相当于一个接口这么个东西，至于你系统底层
     用什么去支持它，这个无所谓。现在去比较2个struct类型的pthread_t，无法用“==”或“=！”去比较。所以posix线程库专门提供了
     一个比较函数pthread_equal。
     
     ●pthread_t类型的线程ID是POSIX线程库内部维护的线程的唯一标识，通常表现为一个很大的整数，跨平台，可移植。
         #include <pthread.h>
         pthread_t pthread_self(void);
         返回调用线程的(POSIX线程库的)TID

     ●syscall(SYS_gettid)函数返回是一个long int类型整数，是系统内核产生线程唯一标识。一个进程的PID其实就是它的主线程的TID。
         #include <sys/syscall.h>
         long int syscall(SYS_gettid);
         返回调用线程的(系统内核的)TID。

     ●pthread_t类型在不同系统会被实现为不同的数据类型，甚至可能会使用结构体。因此判断两个线程ID是否相等或不相等，
     最好不要使用"=="或"!="运算符，因为这些关系运算符只能用于C语言内置的简单类型，而对于结构类型的数据不适用。
         ➢#include < pthread.h>
         ➢int pthread_equal(pthread_t t1, pthread_t t2);
         ➢若两个参数所表示的TID相等返回非零，否则返回0。
 */
#if 0
//线程的ID
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>

//线程过程函数
void* pthread_fun(void* arg){
    printf("子线程:进程的PID       %d\n",getpid());
    printf("子线程:线程的posixTID  %ld\n",pthread_self());
    printf("子线程:线程的内核TID    %ld\n",syscall(SYS_gettid));
    return NULL;
}

int main(void){
    printf("主线程:进程的PID       %d\n",getpid());
    printf("主线程:线程的posixTID  %ld\n",pthread_self());
    printf("主线程:线程的内核TID    %ld\n",syscall(SYS_gettid));
    pthread_t tid;
    pthread_create(&tid,NULL,pthread_fun,NULL);
    pthread_join(tid,NULL);
    return 0;
}
#endif

/*
 (base) 176x212x32x33:day25 wyl$ ./id
 主线程:进程的PID       9919
 主线程:线程的posixTID  4605113856
 主线程:线程的内核TID    4294967295
 子线程:进程的PID       9919
 子线程:线程的posixTID  123145550356480
 子线程:线程的内核TID    4294967295
 */
