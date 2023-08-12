/*
 系统I/O与标准I/O
     ●当系统调用函数被执行时，需要在用户态和内核态之间来回切换，因此频繁执行系统调用函数会严重影响性能
     ●标准库做了必要的优化，内部维护一一个缓冲区，只在满足特定条件时才将缓冲区与系统内核同步，借此降低执行系统调用的频率，
      减少进程在用户态和内核态之间来回切换的次数，提高运行性能
      笔记：
         标准库调用       系统调用
         fopen     ->    open    //fopen底层调用open
         fread     ->    read    //fread底层调用read
         fwrite    ->    write   //fwrite底层调用write
         fclose    ->    close   //fclose底层调用close
         标准库调用比系统调用快。
 */
#if 0

//系统IO
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    int fd = open("/Users/wyl/C++_Projects/UC_learning/day07/sysio.txt",O_WRONLY | O_CREAT | O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }

    for(int i = 0;i < 100000;i++){
        write(fd,&i,sizeof(i));
    }

    close(fd);
    return 0;
}

#endif
/*
 (base) 176x212x32x5:day07 wyl$ gcc 05stdio.c  -o stdio
 (base) 176x212x32x5:day07 wyl$ gcc 06sysid.c -o sysid
 (base) 176x212x32x5:day07 wyl$ time ./stdio

 real    0m0.288s
 user    0m0.005s
 sys    0m0.002s
 (base) 176x212x32x5:day07 wyl$ time ./sysid

 real    0m0.520s
 user    0m0.024s
 sys    0m0.235s

*/

//time用来计算可执行程序的执行时间

