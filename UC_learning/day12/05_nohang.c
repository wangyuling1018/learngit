
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

//非阻塞回收
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
int main(void){
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程假装很忙,不结束
    if(pid == 0){
        printf("%d进程:我是子进程,我很忙\n",getpid());
        sleep(10);
        return 0;
    }
    //父进程以非阻塞方式回收
    for(;;){
        pid_t pid = waitpid(-1,NULL,WNOHANG); //非阻塞方式
        if(pid == -1){
            if(errno == ECHILD){//没有子进程
                printf("没有子进程可回收了\n");
                break;
            }else{//其他原因错误
                perror("waitpid");
                return -1;
            }
        }else if(pid == 0){
            printf("子进程在运行,没法收,干点别的\n");
            printf("肚子有点饿,想吃锅包肉\n");
            sleep(1);
        }else{
            printf("已经回收了%d进程的僵尸\n",pid);
        }
    
    }

    return 0;
}

#endif

/*
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 05_nohang.c
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./a.out
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 33004进程:我是子进程,我很忙
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 子进程在运行,没法收,干点别的
 肚子有点饿,想吃锅包肉
 已经回收了33004进程的僵尸
 没有子进程可回收了
 */
