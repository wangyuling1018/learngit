


#if 0
//文件锁演示
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

//加锁
int wlock(int fd,int wait){
    struct flock lock;//表示锁结构
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;//一直锁到文件尾
    lock.l_pid = -1;

    return fcntl(fd,wait ? F_SETLKW : F_SETLK,&lock);
}

//解锁
int unlock(int fd){
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = -1;
    return fcntl(fd,F_SETLK,&lock);
}

int main(int argc,char* argv[]){
    
    setbuf(stdout,NULL);//关闭输出缓冲区
    
    // a.out hello
    if(argc < 2){
        fprintf(stderr,"用法:./a.out <字符串>\n");
        return -1;
    }
    
    //打开文件
    int fd = open("./conflict.txt",O_WRONLY | O_CREAT | O_APPEND,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    
    //以阻塞方式加锁
    /*
    if(wlock(fd,1) == -1){
     perror("wlock");
     return -1;
     }
     */
    
    
    //以非阻塞方式加锁
    while(wlock(fd,0) == -1){
        if(errno == EACCES || errno == EAGAIN){//非阻塞方式,加不上锁
            printf("文件被其他进程锁定,无法加锁,干点别的去.....\n");
            sleep(1);
        }else{//其他原因导致的出错,正常错误处理
            perror("wlock");
            return -1;
        }
    }
    
    
    //将命令行带入的数据,写入文件中
    for(int i = 0;i < strlen(argv[1]);i++){
        if(write(fd,&argv[1][i],sizeof(argv[1][i])) == -1){
            perror("write");
            return -1;
        }
        sleep(1);
    }
    
    //解锁
    if(unlock(fd) == -1){
        perror("unlock");
        return -1;
    }
    
    //关闭文件
    close(fd);
    return 0;
}
#endif


/*
 开2个窗口
 第一个窗口：
 (base) 176x212x32x5:day08 wyl$ ./a.out hello
 第二个窗口：
 (base) 176x212x32x5:day08 wyl$ ./a.out  world
 (base) 176x212x32x5:day08 wyl$ vi conflict.txt
 1 helloworld
 */
