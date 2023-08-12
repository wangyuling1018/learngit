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
//子进程是否会继承父进程对信号的处理
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

//信号处理函数
void sigfun(int signum){
    printf("捕获到%d号信号\n",signum);
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
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码不结束
    if(pid == 0){
        printf("%d进程:我是子进程\n",getpid());
        for(;;);
        return 0;
    }
    //父进程代码
    printf("%d进程:我是父进程,拜拜\n",getpid());

    return 0;
}

#endif


/*开2个窗口，一个窗口
 (base) 176x212x32x15:day15 wyl$ gcc 02_fork.c
 (base) 176x212x32x15:day15 wyl$ ./a.out
 25855进程:我是父进程,拜拜
 25856进程:我是子进程
 (base) 176x212x32x15:day15 wyl$ 捕获到3号信号
 捕获到3号信号
 捕获到3号信号
 捕获到3号信号
 捕获到3号信号


 */
/*另一个窗口 ，25856是子进程
 (base) 176x212x32x15:~ wyl$ kill -2 25856
 (base) 176x212x32x15:~ wyl$ kill -2 25856   // 子进程忽略2号信号
 (base) 176x212x32x15:~ wyl$ ps aux          //查看25856是否还在
 (base) 176x212x32x15:~ wyl$ kill -3 25856  //子进程捕获到3号信号
 (base) 176x212x32x15:~ wyl$ kill -3 25856
 (base) 176x212x32x15:~ wyl$ kill -3 25856
 (base) 176x212x32x15:~ wyl$ kill -3 25856
 (base) 176x212x32x15:~ wyl$ kill -3 25856
 (base) 176x212x32x15:~ wyl$ kill -9 25856   //子进程被9号信号杀死
 (base) 176x212x32x15:~ wyl$ ps aux
 */
