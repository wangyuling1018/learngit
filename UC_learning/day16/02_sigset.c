/*
 信号集
     ●多个信号组成的信号集合谓之信号集
     ●系统内核用sigset_t类型表示信号集
         ➢在<signal.h>中又被定义为typedef __sigset_t sigset_t;
         ➢在<sigset.h>中有如下类型定义
             #define _SIGSET_NWORDS (1024/(8* sizeof(unsigned long int)))
             typedef struct {
                 unsigned long int __val[_SIGSET_NWORDS];
             }__sigset_t;
     ●sigset_t类型是一个结构体,但该结构体中只有一个成员，是一个包含32个元素的整数数组(针对32位系统而言)

     ●可以把sigset_t类型看成一个由1024个二进制位组成的大整数
         ➢其中的每一位对应一个信号，其实目前远没有那么多信号
         ➢某位为1就表示信号集中有此信号，反之为0就是无此信号
         ➢当需要同时操作多个信号时，常以sigset_t作为函数的参数或返回值的类型
     笔记：
     1、信号集的使用场景：在操作多个信号的时候，使用信号集
     2、sigset_t 本质是一个数组，这个数组有32个元素，每个元素是4个字节，共计是128个字节的存储区。
         共1024个比特位。通过比特位表示是否有某个信号，共1024个比特位。例如：第31位是1，表示有31号信号；第2位是0，表示没有2号信号

 信号集操作相关函数
     #include <signal.h>
     int sigfillset (sigset_t* sigset);
         功能:填满信号集，即将信号集的全部信号位置1  //1024个比特位是1
         参数:sigset：信号集
         返回值:成功返回0，失败返回-1非会员水”

     #include <signal.h>
     int sigemptyset (sigset t* sigset);
         功能:清空信号集，即将信号集的全部信号位清0  //1024个比特位是0
         参数:sigset：信号集
         返回值:成功返回0，失败返回-1

     #include <signal.h>
     int sigaddset (sigset t* sigset, int signum);
         ➢功能:加入信号，即将信号集中与指定信号编号对应的信号位置1
         ➢参数: sigset：信号集
               signum:信号编号
         ➢返回值:成功返回0，失败返回-1

     #include <signal.h>
     int sigdelset (sigset t* sigset, int signum);
         功能:删除信号，即将信号集中与指定信号编号对应的信号位清0
         参数:sigset：信号集
              signum:信号编号
         返回值:成功返回0，失败返回-1

     #include <signal.h>
     int sigismember (const sigset t* sigset, int signum);
         功能:判断信号集中是否有某信号，即检查信号集中与指定信号编号对应的信号位是否为1
         参数:sigset：信号集
             signum:信号编号
         返回值:有则返回1，没有返回0，失败返回-1
     笔记：
     1、参数1加了const，是因为不修改指针所指的数据所以加const修饰，
     2、注意：在设计函数的时候，尤其是针对指针类型的数据，一定要考虑const是加还是不加。通过指针传递过来一
         块存储区地址，你对这块存储区仅仅是为了读而已，在设计形参的时候最好加上const关键字，以避免手抖修改了这块数据。
 */

#if 0

//信号集
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

//搞定一个字节
void printb(char byte){
    for(int i = 0;i < 8;i++){
        printf("%d",byte & (1 << 7 - i) ? 1 : 0);
    }
    printf(" ");//空格
}
/*
 按位与  & ：
     任何数据和1做按位与, 结果不变
     任何数据和0做按位与, 结果为0
 按位或 | ：
     任何数据和1做按位或, 结果为1
     任何数据和0做按位或, 结果保持不变
 
 一个字节8个比特位，byte分别与(1 << 7 - i)相&，获取byte中的每个比特位的值。
 1 << 1 -> 二进制的：10
 1 << 2 -> 二进制的：100
 1 << 3 -> 二进制的：1000
 1 << 4 -> 二进制的：10000
 1 << 5 -> 二进制的：100000
 1 << 6 -> 二进制的：1000000
 1 << 7 -> 二进制的：10000000
 */

//搞定一块存储区
//buf 接存储区的首地址
//size 接存储区的大小
void printm(void* buf,size_t size){
    for(int i = 0;i < size;i++){
        printb(((char*)buf)[size-1-i]); //倒着打印
        if((i + 1) % 4 == 0){//打4个字节后换一行
            printf("\n");
        }
    }
}

int main(void){
    //信号集
    sigset_t sigset;
    //printf("%d\n",sizeof(sigset)); //不同系统，字节数不一样 ，macos是4个字节，linux是128个字节
    printf("填满信号集\n");
    sigfillset(&sigset);
    printm(&sigset,sizeof(sigset));
    printf("清空信号集\n");
    sigemptyset(&sigset);
    printm(&sigset,sizeof(sigset));
    printf("添加2号信号\n");
    sigaddset(&sigset,SIGINT);
    printm(&sigset,sizeof(sigset));
    printf("添加3号信号\n");
    sigaddset(&sigset,SIGQUIT);
    printm(&sigset,sizeof(sigset));
    printf("删除2号信号\n");
    sigdelset(&sigset,SIGINT);
    printm(&sigset,sizeof(sigset));
    printf("信号集中%s2号信号\n",sigismember(&sigset,SIGINT) ? "有" : "无");
    printf("信号集中%s3号信号\n",sigismember(&sigset,SIGQUIT) ? "有" : "无");
    return 0;
}
#endif
/*
 填满信号集
 11111111 11111111 11111111 11111111
 清空信号集
 00000000 00000000 00000000 00000000
 添加2号信号
 00000000 00000000 00000000 00000010
 添加3号信号
 00000000 00000000 00000000 00000110
 删除2号信号
 00000000 00000000 00000000 00000100
 信号集中无2号信号
 信号集中有3号信号
 */
