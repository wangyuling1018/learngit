/*
 #include < unistd.h>
 pid_t fork(void);
     ➢功能:创建调用进程的子进程
     >返回值:成功分别在父子进程中返回子进程的PID和O， 失败返回-1。
     ➢注意! ! !该函数调用一次返回两次，在父进程中返回所创建子进程的PID，而在子进程中返回0，函数的调用者可以
     根据返回值的不同，分别为父子进程编写不同的处理分支
     ➢系统中总的线程数达到了上线，或者用户的总进程数达到了上线，fork函数 会返回失败。
         线程上线: /proc/sys/kernel/threads-max
         进程上线: ulimit -u
 笔记：
     成功，返回给父进程子进程的id，返回给子进程0；失败返回-1；
     创建子进程成功后，fork以下的代码，子进程也会执行一遍。
    子进程是父进程的副本。复制的是父进程的变量。

 为父子进程设计相同的执行过程
     int main(void){
         .....
         pid_t pid = fork();
         if(pid == -1){
             perror("fork");
             return-1;
         }
         ......   \父子进程都
         return 0;/执行的代码
     }

 为父子进程设计先不同而后相同的执行过程
     int main(void){
         ....
         pid_t pid = fork();
         if(pid == -1){
             perror("fork");
             return -1;
         }
         if(pid == 0){
             .... -子进程执行的代码
         else{
             .... -父进程执行的代码
         }
          ...   \父子进程都
         return 0;/执行的代码
     }

 为父子进程设计不同的执行过程
 int main(void) {
     ....
     pid_ t pid = fork();
     if(pid == -1){
         perror("fork");
         return -1;
     }
     if(pid == 0){
         .....   \子进程执
         return 0; /行的代码
     }
     .....      \父进程执
     return 0; /行的代码
 }
 */

#if 0
//创建子进程
#include<stdio.h>
#include<unistd.h>
/*
int main(void){
    printf("%d进程:我是父进程,我要调用fork函数,创建子进程了\n",getpid());

    //创建子进程
    pid_t abc = fork();
    if(abc == -1){
        perror("fork");
        return -1;
    }

    printf("%d进程:肚子有点饿,想吃铁锅炖大鹅\n",getpid());
    return 0;
}
 */
/*
 15516进程:我是父进程,我要调用fork函数,创建子进程了
 15516进程:肚子有点饿,想吃铁锅炖大鹅
 15518进程:肚子有点饿,想吃铁锅炖大鹅
 Program ended with exit code: 0
 */

int main(void){
    printf("%d进程:我是父进程,我要调用fork函数,创建子进程了\n",getpid());

    //创建子进程
    pid_t abc = fork();
    if(abc == -1){
        perror("fork");
        return -1;
    }
    if(abc == 0){
        printf("%d进程:哈哈哈哈哈\n",getpid());
    }else{
        printf("%d进程:嘿嘿嘿嘿嘿\n",getpid());
    }

    printf("%d进程:肚子有点饿,想吃铁锅炖大鹅\n",getpid());
    return 0;
}
/*
 12550进程:我是父进程,我要调用fork函数,创建子进程了
 12550进程:嘿嘿嘿嘿嘿
 12550进程:肚子有点饿,想吃铁锅炖大鹅
 12552进程:哈哈哈哈哈
 12552进程:肚子有点饿,想吃铁锅炖大鹅
 Program ended with exit code: 0
 */
#endif

