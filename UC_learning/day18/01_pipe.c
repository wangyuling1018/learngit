/*
 无名管道
     ● 无名管道是一一个与文件系统无关的内核对象，主要用于父子进程之间的通信, 需要用专门的系统调用函数创建
     #include < unistd.h>
     int pipe(int pipefd[2]);
         ➢功能:创建无名管道
         ➢参数: pipefd 输出两个文件描述符:
                 pipefd[0] -用于从无名管道中读取数据;
                 pipefd[1] -用于向无名管道中写入数据。
         ➢返回值:成功返回0，失败返回-1
     笔记：pipe做了2件事情：1、创建了管道。2、将读端描述符存入pipefd[0]中，将写端描述符存入pipefd[1]中

     ● 基于无名管道实现进程间通信的编程模型
         ➢1.父进程调用pipe函数在系统内核中创建无名管道对象，并通过该函数的输出参数pipefd，获得分别用于读写该管道的两个文件描述符pipefd[0]和pipefd[1]
         ➢2.父进程调用fork函数，创建子进程。子进程复制父进程的文件描述符表，因此子进程同样持有分别用于读写该管道的两个文件描述符pipefd[0]和pipefd[1]
         ➢3. 负责写数据的进程关闭无名管道对象的读端文件描述符pipefd[0]，而负责读数据的进程则关闭该管道的写端文件描述符pipefd[1]
         ➢4.父子进程通过无名管道对象以半双工的方式传输数据。如果需要在父子进程间实现双向通信，较一般化的做法是创建两个管道，一个从父流向子，一个从子流向父
         ➢5.父子进程分别关闭自己所持有的写端或读端文件描述符。在与一一个无名管道对象相关联的所有文件描述符都被关闭以后，该无名管道对象即从系统内核中被销毁


     ● 特殊情况
         ●1、从写端已被关闭的管道读取，只要管道中还有数据，依然可以被正常读取，一直到管道中没有数据了，这时read函数会返回0(既不是返回-1，也不是阻塞)，指示读到文件尾。
         ●2、向读端已被关闭的管道写入会直接触发SIGPIPE(13)信号。该信号的默认操作时终止执行写入动作的进程。但如果执行写入动作的进程事先已将对SIGPIPE(13)信号的处理设置为忽略或捕获，则write函数会返回-1, 并置errno为EPIPE。
         ●3、 系统内核通常为每个管道维护一一个大小为4096字节的内存缓冲区。如果写管道时发现缓冲区的空闲空间不足以容纳此次write
             所要写入的字节，则write会阻塞，直到缓冲区的空闲空间变得足够大为止。
         ●读取一个写端处于开放状态的空管道，将直接导致read函数阻塞。 //意思是：写端的描述符没有关，就是有进程用着写端，这个时候去读，就会导致read函数等待，即read函数阻塞。
     笔记：
         1、无名管道：本质也是内核维护的内存缓冲区，只是借助文件描述符（读端描述符和写端描述符）去表示这块内存缓冲区（管道）。
         4、不用的写端或读端，不用就要立即关闭。否则就会阻塞。只要有进程没有关闭写端，表示写端还在用着，还在被占用着，
         read函数处于阻塞状态。
         5、写端的描述符没有关，就是有进程用着写端，这个时候去读，就会导致read函数等待，即read函数阻塞。
 */

#if 0
//无名管道演示
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void){
    //父进程创建无名管道,得到读端和写端的描述符
    int fd[2];//用来存储读端和写端的文件描述符
    if(pipe(fd) == -1){
        perror("pipe");
        return -1;
    }
    printf("fd[0] = %d\n",fd[0]);//读端描述符
    printf("fd[1] = %d\n",fd[1]);//写端描述符
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程 通过读端,读取数据
    if(pid == 0){
        //不用的写端或读端，不用就要立即关闭。否则就会阻塞。只要有进程没有关闭写端，表示写端还在用着，还在被占用着，read函数处于阻塞状态。
        printf("%d进程:关闭写端\n",getpid()); //不用必须先关闭，
        close(fd[1]);
        for(;;){
            char buf[128] = {};
            ssize_t size = read(fd[0],buf,sizeof(buf)-1);
            if(size == -1){
                perror("read");
                return -1;
            }
            if(size == 0){
                printf("父进程关闭写端\n");
                break;
            }
            printf(">>>%s",buf);
        }
        printf("%d进程:关闭读端\n",getpid());
        close(fd[0]);
        /*
        //写端的描述符没有关，就是有进程用着写端，这个时候去读，就会导致read函数等待，即read函数阻塞。
        printf("%d进程:关闭写端\n",getpid()); //error，
        close(fd[1]);
         */
        
        return 0;
    }

    //父进程 通过写端,写入数据
    printf("%d进程:关闭读端\n",getpid());//不用必须先关闭
    close(fd[0]);
    for(;;){
        char buf[128] = {};
        fgets(buf,sizeof(buf),stdin);
        //给 !  退出
        if(strcmp(buf,"!\n") == 0){
            break;
        }

        if(write(fd[1],buf,strlen(buf)) == -1){
            perror("write");
            return -1;
        }
    }
    printf("%d进程:关闭写端\n",getpid());
    close(fd[1]);
    /*
     printf("%d进程:关闭读端\n",getpid());//error，
     close(fd[0]);
     */
    
    //父进程收尸
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    printf("%d进程:回收了子进程的僵尸\n",getpid());

    return 0;
}

#endif


/*
 (base) 176x212x32x15:day18 wyl$ gcc 01_pipe.c
 (base) 176x212x32x15:day18 wyl$ ./a.out
 fd[0] = 3
 fd[1] = 4
 27618进程:关闭读端
 27619进程:关闭写端
 ignageanga
 >>>ignageanga
 gianeaegn
 >>>gianeaegn
 iwngaeinga
 >>>iwngaeinga
 ieninga
 >>>ieninga
 !
 27618进程:关闭写端
 父进程关闭写端
 27619进程:关闭读端
 27618进程:回收了子进程的僵尸
 */





