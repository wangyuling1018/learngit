/*
 3、调用_exit/_Exit函数令进程终止
     #include <unistd.h>
     void exit(int status);
         参数:status进程退出码，相当于main函数的返回值该函数不返回!
     #include <stdlib.h>
     void Exit(int status);
         参数:status 进程退出码，相当于main函数的返回值该函数不返回!

     ➢_exit在终止调用进程之前也会做几件收尾工作，但与exit函数所做的不同。事实上，exit 函数在做完它那三件收尾工作
     之后紧接着就会调用_exit函数
         A、关闭所有仍处于打开状态的文件描述符
         B、将调用进程的所有子进程托付给init进程收养
         C、向调用进程的父进程发送SIGCHLD(17)信号
         D、令调用进程终止运行，将status的低八位作为退出码保存在其终止状态中
             
 笔记：
     init是1号进程，也叫孤儿院进程。不同的系统1号进程扮演不同的角色。
     正常终止，进行以下一系列的收尾工作，如所示：
     A、调用实现通过atexit或on_exit函数注册的退出处理函数;
     B、冲刷并关闭所有仍处于打开状态的标准I/0流;
     C、删除所有通过tmpfile函数创建的临时文件;
     D、_exit(status)：
         D1. 关闭所有仍处打开状态的文件描述符
         D2、将调用进程的所有子进程托付给init进程收养
         D3、向调用进程的父进程发送SIGCHLD(17)信号
         D4、令调用进程终止运行，将status的低八位作为退出码保存在其终止状态中
     终止状态是一个int整数，子进程在内存中所占的资源(4个字节)就是终止状态，也就是尸体
     注册函数可以有多个，注册的顺序和执行的顺序是相反的
     系统可以直接调用_exit或_Exit。也算正常终止
 */
#if 0
//exit函数演示
#include<stdio.h>
#include<stdlib.h>// exit()
#include <unistd.h> //_exit()

//退出处理函数
void doit(void){
    printf("我是退出处理函数\n");
}
//退出处理函数
void doit2(int status,void* abc){
    printf("status = %d\n",status);
    printf("abc = %s\n",(char*)abc);
}

int fun(void){
    printf("我是fun,哈哈哈\n");
    //exit(0);//哪调哪死,正常终止的执行顺序：A、B、C、D（D1、D2、D3、D4）
    _exit(0); //哪调哪死,正常终止的执行顺序：D（D1、D2、D3、D4），不执行A、B、C，所以不执行注册退出处理函数
    return 5;
}

int main(void){
    //注册退出处理函数
    atexit(doit);
    //on_exit(doit2,"hello");
    int ret = fun();
    printf("fun返回%d\n",ret);
    return 0;
}
#endif

/*
 (base) wangyulingdeMacBook-Pro:day12 wyl$ gcc 01_exit.c -o exit
 (base) wangyulingdeMacBook-Pro:day12 wyl$ ./exit
 我是fun,哈哈哈
 */
