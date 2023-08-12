/*
 wait
     #include <sys/wait.h>
     pid_t wait(int* status);  //阻塞函数
         功能:等待并回收任意子进程 //谁先死就先收谁
         参数:status用于输出子进程的终止状态，可置NULL //status输出型参数，输出子进程的终止状态，NULL表示对应子进程的终止状态不关心
         返回值:成功返回所回收的子进程的PID，失败返回-1
     父进程在创建若干子进程以后调用wait函数:
         ➢A.若所有子进程都在运行，则阻塞，直到有子进程终止才返回;
         ➢B.若有-个子进程已终止，则返回该子进程的PID并通过status参数输出其终止状态;
         ➢C.若没有任何可被等待并回收的子进程,则返回-1,置errno为ECHILD。
     ●在任何一个子进程终止前，wait函数只能阻塞调用进程，如果有一个子进程在wait函数被调用之前，已经终止并处于
      僵尸状态，wait函数会立即返回，并取得该子进程的终止状态，同时子进程僵尸消失。由此可见wait函数主要完成三个任务
         ➢1. 阻塞父进程的运行，直到子进程终止再继续，停等同步
         ➢2. 获取子进程的PID和终止状态，令父进程得知谁因何而死
         ➢3.为子进程收尸，防止大量僵尸进程耗费系统资源
     ●以上三个任务钟，即使前两个与具体需求无关，仅仅第三个也足以凸显wait函数的重要性，尤其是对那些多进程服务
      器型的应用而言
     ●子进程的终止状态通过wait函数的status参数输出给该函数调用者。<sys/wait.h>头文件提供了几个辅助
       分析进程终止状态的工具宏
     ●WIFEXITED(status)
         ➢真:正常终止WEXITSTATUS(status)->进程退出码
         ➢假:异常终止WTERMSIG(status)->终止进程的信号
     ●WIFSIGNALED(status)
         ➢真:异常终止WTERMSIG(status) ->终止进程的信号
         ➢假:正常终止WEXITSTATUS(status) ->进程退出码
     ●事实上，无论一个进程是正常终止还是异常终止，都会通过系统内核向其父进程发送SIGCHLD(17)信号。
      父进程可以忽略该信号，也可以提供一个针对该信号的信号处理函数，在信号处理函数中以异步的方式回收子进程。
      这样做不仅流程简单，而且僵尸的存活时间短，回收效率高

     笔记：
     1、回收任意子进程：谁先死了，就先收谁的尸体。
     2、通过终止状态可以知道进程是怎么死的，是正常死的还是异常的。
     3、int* status是输出型参数。输出型参数：给谁的地址，就把数据输出到谁的里面。wait输出的是你所回收的子进程的终止状态。
      终止状态是一个int整数，子进程在内存中所占的资源(4个字节)就是终止状态，也就是尸体，僵尸。子进程终止时会return 0或
      return -1或exit(0)等，会产生终止状态，其中0、-1是退出码，父进程会拿到这个终止状态。终止状态包含退出码，终止状态是4个字节，
      其中低1个字节是退出码。
     4、如果父进程回收子进程时，不关心子进程的是如何终止的，即不关心子进程的终止状态，那么参数可设置为NULL。
     5、终止状态包含退出码，终止状态4个字节，其中低8位（低1个字节）存的是退出码。
     6、父进程拿到子进程的终止状态后，通过下面几个宏可以知道子进程是如何被终止的。WIFEXITED 、WIFSIGNALED
         
 */

#if 0

//子进程的回收
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程睡觉
    if(pid == 0){
        printf("%d进程:我是子进程,我要睡觉\n",getpid());
        //sleep(5);
        //return 10; //10是终止状态，退出码是终止状态中的第一个字节，10没有超过255，退出码是10
        //return 300;  //300是终止状态，退出码是终止状态中的第一个字节，300超过255了，退出码是44
        //exit(300);
        //_exit(300);
        //_Exit(300);
        //abort();
        return 6;
    }
    //父进程等待并回收子进程
    printf("%d进程:我是父进程,要等子进程结束并收尸\n",getpid());
    int s;//用来输出所回收的子进程的终止状态
    pid_t childpid = wait(&s);
    if(childpid == -1){
        perror("wait");
        return -1;
    }
    printf("%d进程:我是父进程,回收了%d进程的僵尸\n",getpid(),childpid);

    if(WIFEXITED(s)){//正常终止
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{//异常终止
        printf("异常终止:%d\n",WTERMSIG(s));
    }
    
    return 0;
}


#endif

/* sleep(5); 输出
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 02_wait.c -o wait
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./wait
 30606进程:我是父进程,要等子进程结束并收尸
 30607进程:我是子进程,我要睡觉
 30606进程:我是父进程,回收了30607进程的僵尸
 正常终止:6

 */
/*return 300;  输出
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 02_wait.c -o wait
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./wait
 30730进程:我是父进程,要等子进程结束并收尸
 30731进程:我是子进程,我要睡觉
 30730进程:我是父进程,回收了30731进程的僵尸
 正常终止:44
 */
/* exit(300);  _exit(300);  _Exit(300);
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 02_wait.c -o wait
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./wait
 31068进程:我是父进程,要等子进程结束并收尸
 31069进程:我是子进程,我要睡觉
 31068进程:我是父进程,回收了31069进程的僵尸
 正常终止:44
 */
/*abort(); return 6;
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 02_wait.c -o wait
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./wait
 31250进程:我是父进程,要等子进程结束并收尸
 31251进程:我是子进程,我要睡觉
 31250进程:我是父进程,回收了31251进程的僵尸
 异常终止:6
 */
