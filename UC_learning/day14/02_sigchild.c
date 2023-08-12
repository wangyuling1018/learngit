/*
 太平间信号
     ●如前所述，无论一个进程是正常终止还是异常终止，都会通过系统内核向其父进程发送SIGCHLD(17)信号。父进程完全可以在针对SIGCHLD(17)信号的信号处理函数中，异步地回收子进程的僵尸，简洁而又高效
         void sigchld (int signum){
             pid_t pid = wait(NULL);
             if (pid == -1){
                 perror ("wait");
                 exit (EXIT_FAILURE);
             }
             printf ("%d子进程终止\n",pid);
         }

     ●但这样处理存在一一个潜在的风险，就是在sigchld信号处理函数执行过程中，又有多个子进程终止，由于SIGCHLD(17)信号不可靠， 可能会丢失，形成漏网僵尸，因此有必要在一一个循环过程中回收尽可能多的僵尸
         void sigchld (int signum) {
             for (;;) {
                 pid_t pid = wait (NULL);
                 if(pid == -1){
                     if (errno != ECHILD) {
                         perror ("wait");
                         exit (EXIT_FAILURE);
                         }
                     printf ("子进程都死光了\n"); break;
                 }
                 printf (" %d子进程终止\n", pid);
             }
         }

     ●但上面的代码同样存在问题，因为当所有的子进程都处于运行状态时wait函数会阻塞,这时sigchld信号处理函数就不会返回，被信号中断的操作也就无法继续。为此，可以考虑用具有非阻塞特性的waitpid函数取代wait函数
         void sigchld (int signum){
                 for (;;){
                     pid_t pid = waitpid (-1,NULL, WNOHANG);
                     if (pid==-1){
                         if (errno!= ECHILD){
                             perror ("wait");
                             exit (EXIT_FAILURE);
                         }
                         printf("子进程都死光了\n"); break;
                     }
                     if (!pid) break;
                 printf ("%d子进程终止\n",pid);
                 }
         }
         笔记：
             1、17号信号就是太平间信号
             2、子进程只要死，就有17号信号到来，主进程就会去收尸，收完尸后主进程继续执行----简洁而又高效
             3、主进程对17号信号进行捕获，不会影响主进程本来的工作，主进程没事的时候就干本来的工作，有事情的时候就去收尸，子进程死会发送17号信号。
             4、在信号处理函数执行其间，如果有相同的信号同一个时间多次到来，只保留1个，其余统统丢弃。
 */
#if 0
//17号信号演示
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<errno.h>

//信号处理函数,完成对子进程的收尸
/*
//情况1 - 在信号处理函数执行其间，如果有相同的信号同一个时间多次到来，只保留1个，其余统统丢弃。
void sigchild(int signum){
    printf("捕获到%d号信号\n",signum);
    sleep(2);//第一次信号处理期间，其他4个子进程已经来了，第一次执行完后，再执行一次，其他3个丢失
    pid_t pid = wait(NULL);
    if(pid == -1){
        perror("wait");
        return;//exit(-1);
    }
    printf("回收了%d进程的僵尸\n",pid);

}
 */

//情况2 - 收尸的时候多收几个，但是不完美，万一有一个子进程阻塞了，wait是阻塞函数
void sigchild(int signum){
    printf("捕获到%d号信号\n",signum);
    sleep(2);//第一次信号处理期间，其他4个子进程已经来了，第一次执行完后，再执行一次，其他3个丢失
    for(;;){
        pid_t pid = wait(NULL);
        if(pid == -1){
            if(errno ==  ECHILD){
                printf("没有子进程了");
                break;
            }else{
                perror("wait");
                return;//exit(-1);
            }
        }else{
            printf("回收了%d进程的僵尸\n",pid);
        }
        
    }
}



int main(void){
    //对17号信号进行捕获
    if(signal(SIGCHLD,sigchild) == SIG_ERR){
        perror("signal");
        return -1;
    }

    //创建多个子进程
    for(int i = 0;i < 5;i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        if(pid == 0){
            printf("%d进程:我是子进程\n",getpid());
            //sleep(i+1);//5个子进程1秒钟死一个
            sleep(1); //5个子进程同时死
            return 0;
        }
    }
    //父进程代码
    for(;;);

    return 0;
}
#endif
/* 情况1 ---- 5个子进程同时死，只回收了2个，丢失了3个
 (base) 176x212x32x15:day14 wyl$ gcc 02_sigchild.c -o d
 (base) 176x212x32x15:day14 wyl$ ./d
 20526进程:我是子进程
 20527进程:我是子进程
 20528进程:我是子进程
 20529进程:我是子进程
 20530进程:我是子进程
 捕获到20号信号
 回收了20530进程的僵尸
 捕获到20号信号
 回收了20529进程的僵尸

 */


/*情况2 - 收尸的时候多收几个，但是不完美，万一有一个子进程阻塞了，wait是阻塞函数
 (base) 176x212x32x15:day14 wyl$ gcc 02_sigchild.c -o d
 (base) 176x212x32x15:day14 wyl$ ./d
 21839进程:我是子进程
 21840进程:我是子进程
 21841进程:我是子进程
 21842进程:我是子进程
 21843进程:我是子进程
 捕获到20号信号
 回收了21843进程的僵尸
 回收了21842进程的僵尸
 回收了21841进程的僵尸
 回收了21840进程的僵尸
 回收了21839进程的僵尸
 
 
 */

