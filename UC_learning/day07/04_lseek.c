/*
 笔记：
     1、文件读写位置决定了从哪里度，往哪里写，
     2、文件读写位置本质是整数，相对文件首的偏移量。
     3、文件读写位置随着读写操作同步增加。
         

 #include <unistd.h>
 off_t lseek(int fd, off_t offset, int whence);
     功能:人为调整文件读写位置
     参数:fd:文件描述符。
         offset: 文件读写位置偏移字节数
         whence:offset参数的偏移起点，可以如下取值:
                 SEEK_SET -从文件头(首字节)开始
                 SEEK_CUR -从当前位置(最后被读写字节的下一个字节)开始
                 SEEK_END -从文件尾(最后一个字节的下一个字节)开始
     返回值:成功返回调整后的文件读写位置，失败返回-1


 lseek函数的功能仅仅是修改保存在文件表项中的文件读写位置，并不实际引发任何I/O动作
     -lseek(fd,-7,SEEK_CUR);//从当前位置向文件头偏移7字节
     -lseek(fd,0,SEEK_CUR);// 返回当前文件读写位置
     -lseek(fd,0,SEEK_END);//返回文件总字节数
     //偏移量为整数，往前偏移，偏移量为负数，往后便宜

 ●可以通过lseek函数将文件读写位置设到文件尾之后，在超过文件尾的位置上写入数据，将在文件中形成空洞，位于文件中
  但没有被写过的字节都被设为0，文件空洞不占用磁盘空间，但被计算在文件大小之内
 */


#if 0
//文件读写位置
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    //打开文件
    int fd = open("/Users/wyl/C++_Projects/UC_learning/day07/lseek.txt",O_RDWR | O_CREAT | O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //向文件中写入数据  hello world! 
    char* buf = "hello world!";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //通过lseek函数,更改文件读写位置
    if(lseek(fd,-6,SEEK_END) == -1){
        perror("lseek");
        return -1;
    }
    //再次向文件写入数据  linux! 
    //hello linux!
    buf = "linux!";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //再次调整文件读写位置
    if(lseek(fd,6,SEEK_END) == -1){ //以文件尾往后偏移6个字节，偏的是数字0，空洞
        perror("lseek");
        return -1;
    }
    //第三次向文件写入数据
    //ello linux!^@^@^@^@^@^@这个是啥?   //数字0的assci码是\0,在文本中显示就是^@，^@是空洞
    buf = "这个是啥?";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //关闭文件
    close(fd);
    return 0;
}
#endif

