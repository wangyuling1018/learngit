/*
 #include <sys/wait.h>
 pid_t waitpid(pid_t pid, int* status, int options);
     功能:等待并回收任意或特定子进程
     参数:pid可以以下取值
             -1 等待并回收任意子进程，相当于wait函数
             >0 等待并回收特定子进程
         status 用于输出子进程的终止状态，可置NULL
         options可以如下取值
                 0  阻塞模式，若所等子进程仍在运行，则阻塞直至其终止。
                 WNOHANG 非阻塞模式，若所等子进程仍在运行，则返回0.
     返回值:成功返回所回收子进程的PID或者0，失败返回-1。
     waitpid(-1,&status,0) 等价于wait(&status);
 笔记：
     1、阻塞方式：子进程没有结束，我就在这儿等，等到子进程结束了，我再回收。
     2、非阻塞方式：子进程没有结束，我就返回0，可以先去干点别的事情，过一会我再回来看看子进程结束了没有，
      结束了我就收，没有结束我再返回0。

 */
#if 0
//回收特定子进程，阻塞回收
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    //创建多个子进程
    pid_t pids[5];
    for(int i = 0;i < 5;i++){
        pids[i] = fork();
        if(pids[i] == -1){
            perror("fork");
            return -1;
        }
        if(pids[i] == 0){
            printf("%d进程:我是子进程\n",getpid());
            sleep(i + 1);
            return 0;
        }
    }
    
    //回收特定子进程
    for(int i = 4;i >= 0;i--){
        printf("%d进程:我要收%d进程的僵尸\n",getpid(),pids[i]);
        pid_t pid = waitpid(pids[i],NULL,0); //阻塞回收
        if(pid == -1){
            perror("waitpid");
            return -1;
        }
        printf("%d进程:我已经收了%d的僵尸\n",getpid(),pid);
    }

    return 0;
}
#endif

/*
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 04_waitpid.c
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./a.out
 32422进程:我是子进程
 32423进程:我是子进程
 32424进程:我是子进程
 32421进程:我要收32426进程的僵尸
 32425进程:我是子进程
 32426进程:我是子进程
 32421进程:我已经收了32426的僵尸
 32421进程:我要收32425进程的僵尸
 32421进程:我已经收了32425的僵尸
 32421进程:我要收32424进程的僵尸
 32421进程:我已经收了32424的僵尸
 32421进程:我要收32423进程的僵尸
 32421进程:我已经收了32423的僵尸
 32421进程:我要收32422进程的僵尸
 32421进程:我已经收了32422的僵
 */
