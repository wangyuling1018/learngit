/*
 暂停
     #include <unistd.h>
     int pause(void);
         功能:无限睡眠
         返回值: 成功阻塞，失败返回-1
     ➢该函数使调用进(线)程进入无时限的睡眠状态，直到有信号终止了该进程或被其捕获。如果有信号被调用进程捕获，在信号处理函数返回以后，
      pause函数才会返回，其返回值-1，同时置errno为EINTR，表示阻塞的系统调用被信号打断。pause函数要么不返回，要么返回-1，永远不会返回0。
    笔记：pause会被信号打断，如果有信号来了，等信号处理函数结束后，pause函数才会返回
 */
#if 0

//暂停
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
        printf("%d进程:我是子进程,我要一睡不醒\n",getpid());
        int ret = pause();
        printf("%d进程:pause函数返回%d\n",getpid(),ret);
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
 (base) 176x212x32x15:day15 wyl$ gcc 06_pause.c -o p
 (base) 176x212x32x15:day15 wyl$ ./p
 32773进程:给子进程发送2号信号
 32774进程:我是子进程,我要一睡不醒
 //回车，父进程发送2号信号
 32774进程:2号信号处理开始
 //信号处理函数睡5秒
 32774进程:2号信号处理结束
 32774进程:pause函数返回-1
 */
