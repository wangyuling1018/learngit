
#if 0

//回收多个子进程
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
int main(void){
    //创建多个子进程
    for(int i = 0;i < 5;i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        if(pid == 0){
            printf("%d进程:我是子进程\n",getpid());
            sleep(i + 1);
            return i;//共计5个进程,如果没有该return则有32个进程。//子进程1秒中死一个
        }
    }

    //回收子进程
    for(;;){
        int s;//用来输出子进程的终止状态
        pid_t pid = wait(&s);
        if(pid == -1){
            if(errno == ECHILD){
                printf("已经没有子进程了\n");
                break;
            }else{
                perror("wait");
                return -1;
            }
        }
        printf("%d进程:回收了%d进程的僵尸\n",getpid(),pid);

        if(WIFSIGNALED(s)){//异常退出
            printf("异常退出:%d\n",WTERMSIG(s));
        }else{//正常退出
            printf("正常退出:%d\n",WEXITSTATUS(s));
        }
    }


    return 0;
}

#endif

/*
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 03_waitall.c
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./a.out
 31904进程:我是子进程
 31905进程:我是子进程
 31906进程:我是子进程
 31907进程:我是子进程
 31908进程:我是子进程
 31903进程:回收了31904进程的僵尸
 正常退出:0
 31903进程:回收了31905进程的僵尸
 正常退出:1
 31903进程:回收了31906进程的僵尸
 正常退出:2
 31903进程:回收了31907进程的僵尸
 正常退出:3
 31903进程:回收了31908进程的僵尸
 正常退出:4
 已经没有子进程了
 */
