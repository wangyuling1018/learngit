//
//  read.c
//  UC_learning
//
//  Created by 王育玲 on 2023/5/26.
//
//从文件中读取数据
#if 0
#include <stdio.h>
#include<fcntl.h> // open  //f -file ,cntl- control,文件控制，关于文件的操作的头文件
#include <unistd.h> // read,write,close
#include <string.h>
int main(void){
    //打开文件
    int fd = open("/Users/wyl/C++_Projects/UC_learning/day07/sh.txt",O_RDONLY);
    if(fd == -1){
        perror("open");
        return -1;
    }

    //写入数据
    char buf[128];
    ssize_t size = read(fd, buf, sizeof(buf) - 1);//留一个给\0
    if(size == -1){
        perror("size");
        return -1;
    }
    printf("实际读取到%ld个字节\n",size);
    printf("%s\n",buf);
    //关闭文件
    close(fd);
    return 0;
}
#endif
/*
 实际读取到12个字节
 hello world!
 Program ended with exit code: 0
 */
