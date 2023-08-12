/*
 ●由fork产生的子进程是其父进程的不完全副本，子进程在内存中的映像除了代码区与父进程共享同-块物理内存，
  其它各区映射到独立的物理内存，但其内容从父进程拷贝。
 
 子进程复制父进程的文件描述符表，不复制文件表项，意味着：父、子进程可以通过文件描述符访问同一个文件，相互影响文件读写位置
 */
#if 0

//子进程复制父进程的文件描述符表
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    //setbuf(stdout,NULL);//关闭输出缓冲区
    //父进程创建文件得到文件描述符
    int fd = open("./ftab.txt",O_CREAT | O_TRUNC | O_WRONLY,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //父进程向文件中写入数据  hello world!  12
    char* buf = "hello world!";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码，调整文件的读写位置
    if(pid == 0){
        // 子进程也有变量fd,值也是3
        if(lseek(fd,-6,SEEK_END) == -1){
            perror("lseek");
            return -1;
        }
        close(fd);
        return 0;
    }
    //父进程代码 再次向文件写入
    sleep(1);
    buf = "linux!";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //关闭文件
    close(fd);
    return 0;
}

#endif

/*
 (base) wangyulingdeMacBook-Pro:day11 wyl$ gcc 03_ftab.c -o ftab
 (base) wangyulingdeMacBook-Pro:day11 wyl$ ./ftab
 (base) wangyulingdeMacBook-Pro:day11 wyl$ ls
 01_fork.c    02_copy.c    03_ftab.c    bj_11        ftab        ftab.txt
 (base) wangyulingdeMacBook-Pro:day11 wyl$ vi ftab.txt
   1 hello linux!
 */
