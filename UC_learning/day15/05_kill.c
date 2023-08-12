/*
 #include <signal.h>
 int kil(lpid. t pid, int signum);
     功能:向指定的进程发送信号
     参数: pid可以如下取值
             -1 -向系统中的所有进程发送信号
             >0 -向特定进程(由pid标识)发送信号
         signum:信号编号，取0可用于检查pid进程是否存在，如不存在kil函数会返回-1,且errno为ESRCH
     返回值:成功(至少发出去一个信号)返回0, 失败返回-1

 #include <signal.h>
 int raise(int signum);
     功能:向调用进程自己发送信号
     参数:signum 信号编号
     返回值:成功返回0，失败返回非0会员水印
     kill(getpid(),signum)等价于该函数
 */

#if 0

//kill函数演示
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
#include<sys/wait.h>

//用来判断进程是否存在
int isexist(pid_t pid){
    if(kill(pid,0) == -1){// 发送失败
        if(errno == ESRCH){
            return 1;
        }else{
            perror("kill");
            exit(-1);
        }
    }
    return 0;
}// 0 pid进程存在 1 pid进程不存在 kill失败结束程序

//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}

int main(void){
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程 捕获2号信号
    if(pid == 0){
        /*
        //捕获2号信号
        if(signal(SIGINT,sigfun) == SIG_ERR){//父进程不会继承子进程的信号处理
            perror("signal");
            return -1;
        }*/
        for(;;);
        return 0;
    }
    //父进程 给子进程发送 2号信号
    printf("父进程发送2号信号\n");
    getchar();//获取一个字符，控制程序执行，不敲回车，程序一直阻塞在这里
    if(kill(pid,SIGINT) == -1){
        perror("kill");
        return -1;
    }
    getchar();//获取一个字符
    printf("子进程%s\n",isexist(pid) ? "不存在" : "存在");

    getchar();
    printf("收尸\n");
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    getchar();
    printf("子进程%s\n",isexist(pid) ? "不存在" : "存在");

    return 0;
}



#endif

/*
 (base) 176x212x32x15:day15 wyl$ gcc 05_kill.c -o kill
 (base) 176x212x32x15:day15 wyl$ ./kill
 父进程发送2号信号
 //回车,发送2号信号
 //回车，判断子进程在不在
 子进程存在
 //回车，收尸
 收尸
 //回车，判断子进程在不在
 子进程不存在
 */
