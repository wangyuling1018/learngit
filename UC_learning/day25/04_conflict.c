/*
 并发冲突
     ●当多个线程同时访问其共享的进程资源时，如果不能相互协调配合，就难免会出现数据不一致或不完整的问题。 这种现象被称为线程间的并发访问冲突,简称并发冲突
         ➢假设有整型全局变量g_cn被初始化为0
         ➢int g_cn = 0;
         ➢启动两个线程，同时执行如下线程过程函数，分别对该全局变量做一百万次累加
         ➢void* start routine (void* arg) {
             int i;
             for(i = 0;i < 1000000; ++i)
                 ++g_cn;
             return NULL;
         }
         ➢两个线程结束后，g_cn的值理想情况下应该是两百万，但实际情况却往往少于两百万， 且每次运行的结果不尽相同
 */
#if 0
//并发冲突
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int a = 0;
//线程过程函数
void* pthread_add(void* arg){
    for(int i = 0;i < 100000;i++){
        a++;
    }
    return NULL;
}

int main(void){
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
 (base) 176x212x32x33:day25 wyl$ gcc 04_conflict.c -o c
 (base) 176x212x32x33:day25 wyl$ ./c
 a = 104134
 (base) 176x212x32x33:day25 wyl$ ./c
 a = 114823
 (base) 176x212x32x33:day25 wyl$ ./c
 a = 105255
 (base) 176x212x32x33:day25 wyl$ ./c
 a = 123827
 (base) 176x212x32x33:day25 wyl$ ./c
 a = 105936
 (base) 176x212x32x33:day25 wyl$ ./c
 a = 108200
 */
