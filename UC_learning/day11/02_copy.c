/*
 ●由fork产生的子进程是其父进程的不完全副本，子进程在内存中的映像除了代码区与父进程共享同-块物理内存，
  其它各区映射到独立的物理内存，但其内容从父进程拷贝。
 
 代码区是只读的，所以父、子进程可以共享，因为无法修改
 其他区域是不能共享的
 */

#if 0

//子进程是父进程的不完全副本
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int global = 10;//数据区
int main(void){
    int local = 20;//栈区
    int* heap = malloc(sizeof(int));//堆区
    *heap = 30;
    
    printf("%d进程:%p:%d,%p:%d,%p:%d\n",getpid(),&global,global,&local,local,heap,*heap);

    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码
    if(pid == 0){
        printf("%d进程:%p:%d,%p:%d,%p:%d\n",getpid(),&global,++global,&local,++local,heap,++*heap);
        return 0;
    }

    //父进程代码
    sleep(1);
    printf("%d进程:%p:%d,%p:%d,%p:%d\n",getpid(),&global,global,&local,local,heap,*heap);
    
        
    return 0;
}

#endif
/*
 19159进程:0x100008038:10,0x7ff7bfeff3c8:20,0x600000004060:30
 19161进程:0x100008038:11,0x7ff7bfeff3c8:21,0x600000004060:31
 19159进程:0x100008038:10,0x7ff7bfeff3c8:20,0x600000004060:30
 Program ended with exit code: 0
 */
