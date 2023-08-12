/*
 调用exit函数令进程终止
     #include <stdlib.h>
     void exit(int status);
         功能:令进程终止
         参数: status进程的退出码，相当于main函数的返回值该函数不返回! ! !
     ➢虽然exit函数的参数和main函数的返回值都是int类型，但只有其中最低数位的字节可被其父进程回收，高三个字节会被忽略，
          因此在设计进程的退出码时最好不要超过一字节的值域范围
     ➢通过return语句终止进程只能在main函数中实现，但是调用exit函数终止进程可以在包括main函数在内的任何函数中使用。
     ➢exit函数在终止调用进程之前还会做几件收尾工作
         A、调用实现通过atexit或on_exit函数注册的退出处理函数;
         B、冲刷并关闭所有仍处于打开状态的标准I/O流;
         C、删除所有通过tmpfile函数创建的临时文件;
         D、exit(status);
         
     ➢习惯上，还经常使用EXIT_SUCCESS和EXIT_FAILURE两个宏作为调用exit函数的参数，分别表示成功和失败。
          它们的值在多数系统中被定义成0和-1，但一般建议使用宏，这样做兼容性更好

     注册退出处理函数
     #include <stdlib.h>
     int atexit (void (*function) (void));
         参数:function 函数指针，指向退出处理函数印
         返回值:成功返回0,失败返回-1
     ➢注意atexit函数本身并不调用退出处理函数，而只是将function参数所表示的退出处理函数地址，保存(注册)在系统内核的
     某个地方(进程表项)。待到exit函数被调用或在main函数里执行return语句时，再由系统内核根据这些退出处理函数的地址来调用它们。此过程亦称回调

     #include <stdlib.h>
     int on_exit(void(*function)(int，void*),void*arg);
         参数:function 函数指针，指向退出处理函数。其中第一个参数来自传递给exit函数的status参数或在main函数里
                          执行return语句的返回值，而第二个参数则来自传递给on_exit函数的arg参数
             arg 泛型指针，将作为第二个参数传递给function所指向的退出处理函数
         返回值:成功返回0,失败返回-1

 3、调用_exit/_Exit函数令进程终止
     #include <unistd.h>
     void exit(int status);
         参数:status进程退出码，相当于main函数的返回值该函数不返回!
     #include <stdlib.h>
     void Exit(int status);
         参数:status 进程退出码，相当于main函数的返回值该函数不返回!

     ➢exit在终止调用进程之前也会做几件收尾工作，但与exit函数所做的不同。事实上，exit 函数在做完它那三件收尾工作
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
         A. 关闭所有仍处打开状态的文件描述符
         B、将调用进程的所有子进程托付给init进程收养
         C、向调用进程的父进程发送SIGCHLD(17)信号
         D、令调用进程终止运行，将status的低八位作为退出码保存在其终止状态中
     终止状态是一个int整数，子进程在内存中所占的资源(4个字节)就是终止状态，也就是尸体
     注册函数可以有多个，注册的顺序和执行的顺序是相反的
     系统可以直接调用_exit或_Exit。也算正常终止

 */

//exit函数，在哪里调用就在哪里死
#if 0

//exit函数演示
#include<stdio.h> 
#include<stdlib.h>// exit()
/*
int fun(void){
    printf("我是fun,哈哈哈\n");
    exit(0);//哪调哪死
    return 5;
}
int main(void){
    int ret = fun();
    printf("fun返回%d\n",ret);
    return 0;
}
 //输出：我是fun,哈哈哈
*/

/*

//退出处理函数 atexit，无法传参数
void doit(void){
    printf("我是退出处理函数\n");
}

int fun(void){
    printf("我是fun,哈哈哈\n");
    exit(0);//哪调哪死
    return 5;
}

int main(void){
    //注册退出处理函数
    atexit(doit); //退出处理函数要注册才能使用，内核调用退出处理函数
    int ret = fun();
    printf("fun返回%d\n",ret);
    return 0;
}*/

/*
 我是fun,哈哈哈
 我是退出处理函数
 Program ended with exit code: 0
 */


//退出处理函数 on_exit，可以传参数
void doit(void){
    printf("我是退出处理函数\n");
}
//退出处理函数
void doit2(int status,void* abc){
    printf("status = %d\n",status);//status进程退出码
    printf("abc = %s\n",(char*)abc);
}

int fun(void){
    printf("我是fun,哈哈哈\n");
    exit(0);//哪调哪死
    return 5;
}

int main(void){
    //注册退出处理函数
    atexit(doit); //先注册，后执行
    on_exit(doit2,"hello"); //后注册，先执行
    int ret = fun();
    printf("fun返回%d\n",ret);
    return 0;
}
//2个注册退出处理函数的执行顺序和注册顺序是相反的
/*
 我是fun,哈哈哈
 status = 0
 abc = hello
 我是退出处理函数
 */
#endif

