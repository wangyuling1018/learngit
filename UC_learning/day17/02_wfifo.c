/*
 //有名管道：用于任意两个进程通信。
 
 #include <sys/stat.h>
 int mkfifo(char const* pathname, mode_t mode);
 功能:创建有名管道
 参数:pathname:有名管道名，即管道文件的路径。
     mode:权限模式。
 返回值:成功返回0，失败返回-1
 
 ● 有名管道不仅可以用于Shell命令，也可以在代码中使用基于有名管道实现进程间通信的编程模型
         步骤    进程A    函数          进程B    步骤
         1    创建管道    mkfifo       ————    ———
         2    打开管道    open         打开管道    1
         3    读写管道    read/write   读写管道    2
         4    关闭管道    close        关闭管道    3
         5    删除管道    unlink        ————    ——
 */

//从键盘获取数据函数：scanf、getchar、fgets、read(0,..)

#if 0

//向管道文件中写入数据
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void){
    //创建管道文件
    printf("%d进程:创建管道文件\n",getpid());
    if(mkfifo("./myfifo",0664) == -1){
        perror("mkfifo");
        return -1;
    }
    //打开管道文件
    printf("%d进程:打开管道文件\n",getpid());
    int fd = open("./myfifo",O_WRONLY);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //发送数据
    printf("%d进程:发送数据\n",getpid());
    for(;;){
        //通过键盘获取要写入的数据
        char buf[128] = {};
        fgets(buf,sizeof(buf),stdin);
        //人为指定退出条件,输入 ! 时,退出循环
        if(strcmp(buf,"!\n") == 0){
            break;
        }
        //写入管道文件
        if(write(fd,buf,strlen(buf)) == -1){
            perror("write");
            return -1;
        }
    }
    //关闭管道文件
    printf("%d进程:关闭管道文件\n",getpid());
    close(fd);
    //删除管道文件
    printf("%d进程:删除管道文件\n",getpid());
    unlink("./myfifo");
    printf("%d进程:大功告成\n",getpid());
    return 0;
}
#endif

//同时开2个窗口
/*
 (base) 176x212x32x15:day17 wyl$ ./wfifo
 19965进程:创建管道文件
 19965进程:打开管道文件
 19965进程:发送数据
 giangeaga'g
 ngkangnag
 gaeg



 oega
 ien000
 999

 03jt
 !
 19965进程:关闭管道文件
 19965进程:删除管道文件
 19965进程:大功告成

 */

/*
 (base) 176x212x32x15:day17 wyl$ ./rfifo
 19979进程:打开管道文件
 19979进程:接受数据
 >>giangeaga'g
 >>ngkangnag
 >>gaeg
 >>
 >>
 >>
 >>oega
 >>ien000
 >>999
 >>
 >>03jt
 19979进程:对方关闭管道文件
 19979进程:关闭管道文件
 19979进程:大功告成
 */
