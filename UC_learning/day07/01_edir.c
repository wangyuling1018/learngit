//
//  redir.c
//  UC_learning
//
//  Created by 王育玲 on 2023/5/26.
//
/*
 ●系统内核缺省为每个进程打开三个文件描述符， 它们在unistd.h头文件中被定义为三个宏
     ➢#define STDIN FILENO 0//标准输入 - 键盘，scanf
     ➢#define STDOUT FILENO 1//标准输出 - 显示器，printf
     ➢#define STDERR FILENO 2//标准错误 - 显示器，perror
 */
/*
 1、每个进程都有一个进程表，进程表中有文件描述符表，文件描述符表可以理解为一个复杂的数据结构，文件描述符就是文件描述符表中的下标，
  产生新的文件描述符时，系统总是从下标0开始在文件描述符表中寻找最小的未使用项。
 2、修改一个进程默认的文件描述符不影响其他进程。
 */
//命令./redir >aaa.txt 输出重定向，将结果输出到aaa.txt中 ,底层实现与本代码类似，shell将./redir进程的文件描述符1改了，1不再指向键盘了，而是指向文件了
//重定向
//重定向
#if 0
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(void){
    //1 - 默认对应显示器 ，修改1对应某个文件，prinf（）？
    close(1);//关闭文件描述符1，使1空闲
    int fd = open("/Users/wyl/C++_Projects/UC_learning/day06/open.txt",O_RDWR | O_CREAT | O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    printf("fd = %d\n",fd); //输出 fd = 1
    
    return 0;
}
#endif

