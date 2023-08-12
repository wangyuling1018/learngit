/*
 #include <signal.h>
 typedef void(*sighandler_t)(int);
 sighandler_t signal(int signum, sighandler_t handler);
     功能:设置调用进程针对特定信号的处理方式
     参数:signum信号编号
         handler信号的处理方式， 可以如下取值
             SIG_IGN       - 忽略
             SIG_DFL       - 默认
             信号处理函数指针 - 捕获
     返回值:成功返回原信号处理方式，如果之前未处理过则返回NULL，失败返回SIG_ERR。
 笔记：
 1、函数的功能：对那个那个（参数1）信号做什么什么（参数2）处理。参数1是信号，参数2是处理方式。
 2、sighandler_t是函数指针类型。
 3、参数1:可以是数字，也可以是宏。
 4、Typedef void(*sighandler_t)(int);是对sighandler_t的定义。sighandler_t是函数指针的别名。
 5、参数2:传函数的地址。函数是void signal(int)的函数，参数必须是int，返回值必须是void。
 6、SIG_ERR、SIG_DFL 、SIG_IGN这些宏被强转成指针类型的-1、0、1.
 7、返回值：我当前在程序中是不是第一次对2号信号做处理，如果是第一次处理，则返回NULL，如果我在程序中对于2号信号有过多次处理，
   则返回上一次对该信号的处理方式。
 8、实际工作中很少用到signal的返回值，也就不需要去写这条定义Typedef void(*sighandler_t)(int); -----笔试和面试的时候会问。
 9、在信号处理函数执行其间，如果有相同的信号同一个时间多次到来，只保留1个，其余统统丢弃。
 10、信号处理函数是内核处理的。不是main函数处理的。内核负责传参数，将捕获的信号传递给signum。内核负责处理信号函数，
   内核负责传递信号参数。

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
/*
//情况2 - 收尸的时候多收几个，但是不完美，万一有一个子进程一直不死则阻塞了，wait是阻塞函数
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

*/
//情况3 - waitpid非阻塞函数 --- 背下来
void sigchild(int signum){
    printf("捕获到%d号信号\n",signum);
    sleep(2);
    for(;;){
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        if(pid == -1){
            if(errno == ECHILD){
                printf("没有子进程了\n");
                break;
            }
        }else if(pid == 0){//非阻塞执行的代码
            printf("所有的子进程都在运行\n");
            break;
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

    pid_t six = fork();
    if(six == -1){
        perror("fork");
        return -1;
    }
    if(six == 0){
        printf("%d进程:我是oldsix老六\n",getpid()); //老六 不结束
        sleep(10);
        return 0;
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

/*情况3 - waitpid非阻塞函数
 (base) 176x212x32x15:day15 wyl$ gcc 01_sigchild.c -o si
 (base) 176x212x32x15:day15 wyl$ ./si
 24730进程:我是子进程
 24731进程:我是子进程
 24732进程:我是子进程
 24733进程:我是子进程
 24734进程:我是子进程
 24735进程:我是oldsix老六
 捕获到20号信号
 回收了24734进程的僵尸
 回收了24733进程的僵尸
 回收了24732进程的僵尸
 回收了24731进程的僵尸
 回收了24730进程的僵尸
 所有的子进程都在运行
 捕获到20号信号
 所有的子进程都在运行
 捕获到20号信号
 回收了24735进程的僵尸
 没有子进程了
 */
