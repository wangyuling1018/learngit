/*
 设置掩码与检测未决
     # include <signal.h>
     int sigprocmask (int how, const sigset_t* sigset,sigset_t* oldset);
         功能:设置调用进程的信号掩码
         参数:how:修改信号掩码的方式，可取以下值
                 SIG_BLOCK-将sigset中的信号加入当前信号掩码
                 SIG_UNBLOCK-从当前信号掩码中删除sigset中的信号
                 SIG_SETMASK-把sigset设置成当前信号掩码
             sigset:信号集，取NULL则忽略此参数
             oldset:输出原信号掩码，取NULL则忽略此参数
         返回值:成功返回0，失败返回-1
     例子:
     sigset_t sigset;
     sigemptyset (&sigset);
     sigaddset (&sigset, SIGINT);
     sigaddset (&sigset, SIGQUIT);
     sigset_t oldset;
     if (sigprocmask (SIG_SETMASK, &sigset,&oldset)==-1){
         perror ("sigprocmask");
         exit (EXIT FAILURE);
     }

     #include < siqnal.h>
     int sigpending (sigset_ t* sigset);
         功能:获取调用进程的未决信号集
         参数: sigset: 输出未决信号集
         返回值:成功返回0，失败返回-1
     例子:
         sigset_t sigset;
         if(sigpending (&sigset) ==-1){
             perror("sigpending");
             exit(EXIT_FAILURE);
         }
         if(sigismember(&sigset, SIGINT) == 1){
             printf("SIGINT信号未决\n");
         }

 可靠和不可靠信号的屏蔽
     ●对于可靠信号，通过sigprocmask函数设置信号掩码以后，每种被屏蔽信号中的每个信号都会被阻塞，
      并按先后顺序排队，一旦解除屏蔽，这些信号会被依次递送
     ●对于不可靠信号，通过sigprocmask函数设置信号掩码以后，每种被屏蔽信号中只有第一个会被阻塞，
      并在解除屏蔽后被递送，其余的则全部丢失
 笔记：
     1、信号屏蔽：信号来了，等一会，进程忙完，再处理该信号
     2、信号忽略：信号来了，等一会，进程忙完，找不到该信号了，也就处理不了该信号
     3、有5个17号信号每秒中来一个，当第一个17信号正在处理，此时信号掩码中有17号信号（17号信号被进程屏蔽），当第一个信号处理完后，
       17号信号就从信号掩码中删除了（17号信号屏蔽被解除了），此时有4个17信号正在等待被处理，正在等待被处理的4个信号，
       只处理1个（17号信号又被加入信号掩码中），丢3个。 --- 17信号是不可靠信号



 */

#if 0
//信号屏蔽
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

//假装更新数据库
void updatedb(void){
    for(int i = 0;i < 5;i++){
        printf("正在更新第%d条数据\n",i+1);
        sleep(1);
    }
}
//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}

int main(void){
    //设置对２号信号的捕获　signal
    int signum = SIGINT/* 50*/;
    if(signal(signum,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //对２号信号进行屏蔽　　sigprocmask
    printf("%d进程:屏蔽%d号信号\n",getpid(),signum);
    //信号集,应该有要屏蔽的2号信号
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset,signum);
    sigset_t oldset;//用来输出射之前的信号掩码
    sigprocmask(SIG_SETMASK,&sigset,&oldset);
    //创建子进程 fork
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
        //子进程向父进程发送２号信号　５次　kill
    if(pid == 0){
        for(int i = 0;i < 5;i++){
            printf("%d进程:向父进程发送%d号信号\n",getpid(),signum);
            kill(getppid(),signum);
        }
        return 0;
    }

    //父进程更新数据库
    updatedb();
    //父进程解除对２号信号的屏蔽
    printf("%d进程:解除对%d号信号的屏蔽\n",getpid(),signum);
    sigprocmask(SIG_SETMASK,&oldset,NULL);

    for(;;);
    return 0;
}


#endif
/*屏蔽2号信号
 (base) 176x212x32x15:day17 wyl$ gcc 01_sigprocmask.c
 (base) 176x212x32x15:day17 wyl$ ./a.out
 12758进程:屏蔽2号信号
 正在更新第1条数据
 12759进程:向父进程发送2号信号
 12759进程:向父进程发送2号信号
 12759进程:向父进程发送2号信号
 12759进程:向父进程发送2号信号
 12759进程:向父进程发送2号信号
 正在更新第2条数据
 正在更新第3条数据
 正在更新第4条数据
 正在更新第5条数据
 12758进程:解除对2号信号的屏蔽
 12758进程:捕获到2号信号        //2是不可靠信号，解除屏蔽后，会处理1个，其余全部丢失
 */


/* 屏蔽50信号
  (base) 176x212x32x15:day17 wyl$ gcc 01_sigprocmask.c
  (base) 176x212x32x15:day17 wyl$ ./a.out
  12758进程:屏蔽50号信号
  正在更新第1条数据
  12759进程:向父进程发送50号信号
  12759进程:向父进程发送50号信号
  12759进程:向父进程发送50号信号
  12759进程:向父进程发送50号信号
  12759进程:向父进程发送50号信号
  正在更新第2条数据
  正在更新第3条数据
  正在更新第4条数据
  正在更新第5条数据
  12758进程:解除对50号信号的屏蔽
  12758进程:捕获到50号信号  //50是可靠信号，解除屏蔽后，会全部捕获到
  12758进程:捕获到50号信号
  12758进程:捕获到50号信号
  12758进程:捕获到50号信号
  12758进程:捕获到50号信号
 */


