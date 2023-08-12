/*
 修改文件大小
     #include <unistd.h>
     int truncate(char const* path, off_t length);
     int ftruncate(int fd,off t length);
         功能:修改指定文件的大小
         参数:path:文件路径
             length:文件大小
             fd:文件描述符
         返回值:成功返回0，失败返回-1。
     该函数既可以把文件截短，也可以把文件加长，所有的改变均发生在文件的尾部，新增加的部分用数字0填充。
 */

#if 0

//修改文件大小
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    //先打开文件
    int fd = open("./trunc.txt",O_RDWR | O_CREAT | O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //写入数据 abcde  5
    char* buf = "abcde";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //修改文件打下为  3
    if(ftruncate(fd,3) == -1){
        perror("ftruncate");
        return -1;
    }//文件内容变为：abc
    
    
    //修改文件大小为  5
    if(truncate("./trunc.txt",5) == -1){
        perror("truncate");
        return -1;
    }//文件内容变为：abc^@^@  //^@^@空洞，不占磁盘空间
    //文件空洞，运用于下载，下载过程中的文件就是空洞，提前占一个地方，下载完这个文件就填满了
     

    //关闭文件
    close(fd);
    return 0;
}
#endif

