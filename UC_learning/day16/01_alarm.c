/*
 闹钟
     #include <unistd.h>
     unsigned int alarm(unsigned int seconds);
         功能:设置闹钟
         参数：seconds 以秒为单位的闹钟时间
         返回值:返回0或先前所设闹钟的剩余秒数。
     ➢alarm函数使系统内核在该函数被调用以后seconds秒的时候，向调用进程发送SIGALRM(14)信号
     ➢若在调用该函数前已设过闹钟且尚未到期，则该函数会重设闹钟，并返回先前所设闹钟的剩余秒数，否则返回0
     ➢若seconds取0，则表示取消先前设过且尚未到期的闹钟
    笔记：实现某个固定功能，在固定时长之后去执行，
        一般用的场景：在固定时长后，触发某个功能，实现一个延时操作
 */

#if 0

//闹钟
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}

int main(void){
    //捕获14号信号
    if(signal(SIGALRM,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //不是阻塞函数
    printf("alarm(10)返回%d\n",alarm(10));

    //getchar();
    sleep(7);
    
    printf("alarm(5)返回%d\n",alarm(5));
    for(;;);
    return 0;
}

#endif
/*
 (base) 176x212x32x15:day16 wyl$ gcc 01_alarm.c -o ar
 (base) 176x212x32x15:day16 wyl$ ./ar
 alarm(10)返回0   //第一次设置闹钟，返回0
 alarm(5)返回3    //10-7=3,剩余秒数
 35322进程:捕获到14号信号
 */
