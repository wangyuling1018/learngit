/*
 内存映射文件
     #include <sys/mman.h>
     void* mmap(void* start, size t length, int prot, int flags,int fd, off t offset);
         功能:建立虚拟内存到物理内存或磁盘文件的映射:
         参数:start:映射区虚拟内存的起始地址，NULL系统自动选定后返回。
             length:映射区字节数，自动按页圆整。
             prot:映射区操作权限，可取以下值:
                 PROT_READ-映射区可读
                 PROT_WRITE-映射区可写
                 PROT_EXEC-映射区可执行
                 PROT_NONE-映射区不可访问
             lags:映射标志，可取以下值:
                 MAP_ANONYMOUS -匿名映射，将虚拟内存映射到物理内存而非文件，忽略fd和offset参数
                 MAP_PRIVATE -对映射区的写操作只反映到缓冲区中并不会真正写入文件  //私有映射，通过虚拟地址写，先到缓冲区再到文件里
                 MAP_SHARED -对映射区的写操作直接反映到文件中                 //公有映射，通过虚拟地址写，直接写到文件里
                 MAP_DENYWRITE -拒绝其它对文件的写操作
                 MAP_FIXED -若在start上无法创建映射，则失败(无此标志系统会自动调整)
             fd:文件描述符
             offset:文件偏移量，自动按页(4K)对齐    //从文件的哪个字节开始映射，只能是页（4096）的整数倍
         返回值:成功返回映射区虚拟内存的起始地址，失败返回MAP FAILED(-1)。
        // MAP_PRIVATE和MAP_SHARED 二选一，
         
 解除内存映射
     # include <sys/mman.h>
     int munmap(void* start, size_t length);
         功能:解除虚拟内存到物理内存或磁盘文件的映射:
         参数:start:映射区虚拟内存的起始地址。
             length:映射区字节数，自动按页圆整。
         返回值:成功返回0，失败返回-1。
     munmap允许对映射区的一部分解映射，但必须按页处理


 */

//建立虚拟内存到磁盘文件的映射
#if 0
//内存映射文件
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(void){
    //打开文件
    int fd = open("./mmap.txt",O_RDWR | O_CREAT | O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //映射文件
    char* start = mmap(NULL,4096,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if(start == MAP_FAILED){
        perror("mmap");
        return -1;
    }
    //操作文件
    strcpy(start,"abcedfg");//write //向文件里面写 //error,文件空间大小为0,mmap.txt的空间大小为0
    printf("%s\n",start);//read     //从文件里面读

    //解除映射
    munmap(start,4096);
    //关闭文件
    close(fd);
    return 0;
}
// 运行报错，因为文件大小没有设置
#endif

