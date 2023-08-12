//
//  write.c
//  UC_learning
//
//  Created by 王育玲 on 2023/5/26.
//
/*
 为啥read,write的头文件不是<fcntl.h>？
    因为read,write不仅仅操作文件，还可以是管道、通信等等，万物皆文件，只要是能看作是文件的，都可以用。
    read,write不很强大，系统内核、用户等都用的多，例如printf底层就是用的write
 */
//向文件中写入数据
#if 0
#include <stdio.h>
#include<fcntl.h> // open  //f -file ,cntl- control,文件控制，关于文件的操作的头文件
#include <unistd.h> // read,write,close
#include <string.h>
int main(void){
    //打开文件
    int fd = open("/Users/wyl/C++_Projects/UC_learning/day07/sh.txt",O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1){
        perror("open");
        return -1;
    }
    printf("fd = %d\n",fd);
    
    //写入数据
    char* buf = "hello world!";
    ssize_t size = write(fd,&buf, strlen(buf));
    if(size == -1){
        perror("write");
        return -1;
    }
    printf("实际向系统文件写入%ld个字节\n",size);
    //关闭文件
    close(fd);
    
    
    return 0;
}
#endif

/*
 如何确定ssize_t\long_int等的具体类型？
    gcc -E write.c -o write.i
    vi write.i
    /ssize_t  并按enter键
    然后按n键
 */

/*
 fd = 3
 实际向系统文件写入12个字节
 */

/*
 ls -l 查看sh.txt 有12字节
 vi sh.txt
 :wq
 ls -l 查看sh.txt 有13字节，多了一个\n,系统自动加的
 */
