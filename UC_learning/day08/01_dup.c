/*
 文件描述符的复制
     #include < unistd.h>
     int dup(int oldfd);
         功能:复制文件描述符表的特定条目到最小可用项:
         参数: oldfd: 源文件描述符
         返回值:成功返回目标文件描述符，失败返回-1
     ●dup函数将oldfd参数所对应的文件描述符表项复制到文件描述符表第一个空闲项中，同时返回该表项对应的文件描述符。
      dup函数返回的文件描述符一定是调用进程当前未使用的最小文件描述符。
     ●dup函数只复制文件描述符表项，不复制文件表项和v节点，因此该函数所返回的文件描述符可以看做是参数文件描述符oldfd的副本，它们标识同一个文件表项
     ●注意，当关闭文件时，即使是由dup函数产生的文件描述符副本，也应该通过close函数关闭，因为只有当关联于一个文件表项的所有文件描述符都被关闭了，
      该文件表项才会被销毁，类似地，也只有当关联于一个v节点的所有文件表项都被销毁了，v节点才会被从内存中删除，因此从资源合理利用的角度讲，凡是明确
      不再继续使用的文件描述符，都应该尽可能及时地用close函数关闭
     ●dup函数究竟会把oldfd参数所对应的文件描述符表项，复制到文件描述符表的什么位置，程序员是无法控制的，这完全由调用该函数时文件描述符表的使用情况决定，
      因此对该函数的返回值做任何约束性假设都是不严谨的
     ●由dup函数返回的文件描述符与作为参数传递给该函数的文件描述符标识的是同一个文件表项，而文件读写位置是保存在文件表项而非文件描述符表项中的，
      因此通过这些文件描述符中的任何一个，对文件进行读写或随机访问，都会影响通过其它文件描述符操作的文件读写位置。这与多次通过open函数打开同一个文件不同

     #include <unistd.h>
     int dup2(int oldfd, int newfd);
         功能:复制文件描述符表的特定条目到指定项:
         参数:oldfd:源文件描述符
             newfd:目标文件描述符
         返回值:成功返回目标文件描述符(newfd)，失败返回-1。
     ●dup2函数在复制由oldfd参数所标识的源文件描述符表项时，会先检查由newfd参数所标识的目标文件描述符表项是否空闲，若空闲则直接将前者复制给后者，
      否则会先将目标文件描述符newfd关闭，使之成为空闲项，再行复制。
      笔记：
        oldfd与newfd指向同一个文件表项，文件表项中存的文件读写位置，通过oldfd、newfd操作的是同一个文件读写位置。
 */

//工作中一般用文件描述符进行输出重定向，例如：日志输出到后台日志文件中。
#if 0

//文件描述符的复制
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    
    setbuf(stdout,NULL);//关闭输出缓冲区

    //打开文件,得到文件描述符 oldfd
    int oldfd = open("./dup.txt",O_WRONLY | O_CREAT | O_TRUNC,0664);
    if(oldfd == -1){
        perror("open");
        return -1;
    }
    //复制文件描述符,得到新文件描述符 newfd
    //int newfd = dup(oldfd); //oldfd = 3, newfd = 4
    int newfd = dup2(oldfd,1);//1关闭，1对应dup.txt，oldfd = 3, newfd = 1
    if(newfd == -1){
        perror("dup");
        return -1;
    }
    // printf  -->  1  --> dup.txt
    printf("oldfd = %d\n",oldfd);
    printf("newfd = %d\n",newfd);
    //通过 oldfd  向文件写入数据 hello world!   12
    char* buf = "hello world!";
    if(write(oldfd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //通过 newfd  调整文件读写位置              6
    if(lseek(newfd,-6,SEEK_END) == -1){
        perror("lseek");
        return -1;
    }
    //再次通过 oldfd 向文件写入数据 linux!  
    buf = "linux!";
    if(write(oldfd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //关闭文件
    close(oldfd);
    close(newfd);
    return 0;
}

/*
int newfd = dup(oldfd); //oldfd = 3, newfd = 4
     (base) 176x212x32x5:day08 wyl$ gcc 01_dup.c -o dup
     (base) 176x212x32x5:day08 wyl$ ./dup
     oldfd = 3
     newfd = 4
     (base) 176x212x32x5:day08 wyl$ vi dup.txt
     1 hello linux!
    
 int newfd = dup2(oldfd,1);//1关闭，1对应dup.txt，oldfd = 3, newfd = 1
     (base) 176x212x32x5:day08 wyl$ gcc 01_dup.c -o dup
     (base) 176x212x32x5:day08 wyl$ ./dup
     (base) 176x212x32x5:day08 wyl$ vi dup.txt
     (base) 176x212x32x5:day08 wyl$ vi dup.txt
     1 oldfd = 3
     2 newfd = 1
     3 hello linux!
     ~

 */


#endif




