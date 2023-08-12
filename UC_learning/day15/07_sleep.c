/*
 睡眠
    #include <unistd.h>
    unsigned int sleep(unsigned int seconds);
        功能:有限睡眠
        参数:seconds 以秒为单位的睡眠时限
        返回值:返回0或剩余秒数。
    ➢该函数使调用进程睡眠seconds秒，除非有信号终止了调用进程或被其捕获
    ➢如果有信号被调用进程捕获，在信号处理函数返回以后，sleep函数才会返回，且返回值为剩余的秒数，否则该函数将返回0，表示睡眠充足
    
    #include <unistd.h>
    int usleep(useconds_t usec);
        功能:更精确的有限睡眠
        参数:usec以微秒(1微秒=10-秒)为单位的睡眠时限
        返回值:成功返回0,失败返回-1
    ➢如果有信号被调用进程捕获，在信号处理函数返回以后，usleep函数才会返回，且返回值为-1，同时置errno为EINTR，表示阻塞的系统调用被信号中断
    笔记：sleep\usleep能被信号打断
        1s = 1000ms, 1ms = 1000us
        1s = 1000000us
        0.1s = 100000us
        0.01s = 10000us
        0.001s = 1000us
        0.00001s = 100us
 
*/

#if 0

//睡眠
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:%d号信号处理开始\n",getpid(),signum);
    sleep(5);
    printf("%d进程:%d号信号处理结束\n",getpid(),signum);
}

int main(void){
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程调用pause
    if(pid == 0){
        //捕获2号信号
        if(signal(SIGINT,sigfun) == SIG_ERR){
            perror("signal");
            return -1;
        }
        printf("%d进程:我是子进程,我要睡10秒钟\n",getpid());
        int ret = sleep(10);
        printf("%d进程:sleep函数返回%d\n",getpid(),ret);
        return 0;
    }
    //父进程给子进程发送信号
    printf("%d进程:给子进程发送2号信号\n",getpid());
    getchar();
    if(kill(pid,SIGINT) == -1){
        perror("kill");
        return -1;
    }

    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    return 0;
}

#endif

/*
 (base) 176x212x32x15:day15 wyl$ gcc 07_sleep.c
 (base) 176x212x32x15:day15 wyl$ ./a.out
 34542进程:给子进程发送2号信号
 34543进程:我是子进程,我要睡10秒钟
 //回车，父进程发送2号信号
 34543进程:2号信号处理开始
 34543进程:2号信号处理结束
 34543进程:sleep函数返回3

 */
