/*
 读写冲突
     ➢如果两个或两个以上的进程同时向一个文件的某个特定区域写入数据，那么最后写入文件的数据极有可能因为写操作的交错而产生混乱
     ➢如果一个进程写而其它进程同时在读一个文件的某个特定区域，那么读出的数据极有可能因为读写操作的交错而不完整
     ➢多个进程同时读一一个文件的某个特定区域，不会有任何问题，它们只是各自把文件中的数据拷贝到各自的缓冲区中，并不会改变文件的内容，相互之间也就不会冲突
     ➢由此可以得出结论，为了避免在读写同一个文件的同一个区域时发生冲突，进程之间应该遵循以下规则，如果一个进程正在写，那么其它进程既不能写也不能读，
      如果一个进程正在读，那么其它进程不能写但是可以读
 
 //写和写、写和读不能同时操作
 //读和读可以同时操作

 */

#if 0

//写冲突演示
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

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

    //将命令行带入的数据,写入文件中
    for(int i = 0;i < strlen(argv[1]);i++){
        if(write(fd,&argv[1][i],sizeof(argv[1][i])) == -1){
            perror("write");
            return -1;
        }
        sleep(1);
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
 1 helloworldhelloworldhellohellohewlolrold  //同时写入的结果
 */
//setbuf(stdout,NULL);//关闭输出缓冲区,关闭缓冲区，open函数中文件路径可以写相对路径
