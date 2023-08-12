/*
 主线程和通过pthread_create函数创建的多个子线程，在时间上"同时"运行，如果不附加任何同步条件，则它们每一
  个执行步骤的先后顺序是完全无法确定的，这就叫做自由并发。
 */
#if 0
//线程自由并发
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

//线程过程函数
void* pthread_fun(void* arg){
    for(;;){
        printf("%d",(int)arg);
    }
}
//创建5个线程，分别打印1、2、3、4、5
int main(void){
    setbuf(stdout,NULL);
    pthread_t tid;//用来输出线程tid
    for(int i = 0;i < 5;i++){
        int error = pthread_create(&tid,NULL,pthread_fun,(void*)i);//(void*)i,将整数i转成地址，保证每个线程打印不同的数字
        if(error){
            fprintf(stderr,"pthread_crerate:%s\n",strerror(error));
            return -1;
        }
    }
    getchar();
    return 0;
}
#endif
/*
 (base) 176x212x32x15:day24 wyl$ ./a.out
 0000000000000000000000111111112444444402224244444400000000000000001111112222222224441111111112033333444001111103333300111111111044111131341132210044444444444422223000022300000022222333333102222233333222222222222222222222222223300441111121223311111120000000044100000000000111144311111111100222223333311433333333331110333113431
 */
