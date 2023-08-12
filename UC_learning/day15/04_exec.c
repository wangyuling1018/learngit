/*
 信号处理的继承与恢复
     ●fork函数创建的子进程会继承父进程的信号处理方式。
         ➢父进程中对某个信号进行捕获，则子进程中对该信号依然捕获
         ➢父进程中对某个信号进行忽略，则子进程中对该信号依然忽略
     ●exec家族函数创建的新进程对信号的处理方式和原进程稍有不同
         ➢原进程中被忽略的信号，在新进程中依然被忽略
         ➢原进程中被捕获的信号，在新进程中被默认处理

 */
#if 0
//新进程是否会进程旧进程的信号处理方式
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}

int main(void){
    //忽略2号信号
    if(signal(SIGINT,SIG_IGN) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //捕获3号信号
    if(signal(SIGQUIT,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //变身成new
    if(execl("./new","new",NULL) == -1){
        perror("execl");
        return -1;
    }

    return 0;
}
#endif

//开2个窗口

/*一个窗口
 (base) 176x212x32x15:day15 wyl$ gcc 03_new.c -o new
 (base) 176x212x32x15:day15 wyl$ ls
 01_sigchild.c    03_new.c    a.out        new
 02_fork.c    04_exec.c    bj_15        si
 (base) 176x212x32x15:day15 wyl$ gcc 04_exec.c -o exec
 (base) 176x212x32x15:day15 wyl$ ./exec
 26695进程:我是变身后的新进程
 Quit: 3
 */

/*另一个窗口
 (base) 176x212x32x15:~ wyl$ kill -2 26695  //新进程忽略2号信号
 (base) 176x212x32x15:~ wyl$ kill -3 26695  //新进程退出，3号信号默认处理方式是退出
 */
