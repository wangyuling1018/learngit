/*
 #include <signal.h>
 typedef void(*sighandler_t)(int);
 sighandler_t signal(int signum, sighandler_t handler);
     功能:设置调用进程针对特定信号的处理方式
     参数:signum信号编号
         handler信号的处理方式， 可以如下取值
             SIG_IGN       - 忽略
             SIG_DFL       - 默认
             信号处理函数指针 - 捕获
     返回值:成功返回原信号处理方式，如果之前未处理过则返回NULL，失败返回SIG_ERR。
 笔记：
 1、函数的功能：对那个那个（参数1）信号做什么什么（参数2）处理。参数1是信号，参数2是处理方式。
 2、sighandler_t是函数指针类型。
 3、参数1:可以是数字，也可以是宏。
 4、Typedef void(*sighandler_t)(int);是对sighandler_t的定义。sighandler_t是函数指针的别名。
 5、参数2:传函数的地址。函数是void signal(int)的函数，参数必须是int，返回值必须是void。
 6、SIG_ERR、SIG_DFL 、SIG_IGN这些宏被强转成指针类型的-1、0、1.
 7、返回值：我当前在程序中是不是第一次对2号信号做处理，如果是第一次处理，则返回NULL，如果我在程序中对于2号信号有过多次处理，
   则返回上一次对该信号的处理方式。
 8、实际工作中很少用到signal的返回值，也就不需要去写这条定义Typedef void(*sighandler_t)(int); -----笔试和面试的时候会问。
 9、在信号处理函数执行其间，如果有相同的信号同一个时间多次到来，只保留1个，其余统统丢弃。
 10、信号处理函数是内核处理的。不是main函数处理的。内核负责传参数，将捕获的信号传递给signum。内核负责处理信号函数，
   内核负责传递信号参数。

 */
#if 0

//信号的处理
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

typedef void (*sighandler_t)(int);//实际工作中很少用到signal的返回值，也就不需要去写这条定义Typedef void(*sighandler_t)(int);

//信号处理函数
void sigfun(int signum){ //形参类型必须是int，内核调用该函数
    printf("捕获到%d号信号\n",signum);
}

int main(void){
    //忽略2号信号
    sighandler_t ret = signal(SIGINT,SIG_IGN);
    if(ret == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("ret = %p\n",ret); //如果之前未处理过2号信号则返回NULL
    //for(;;);
 

    //第二次对2号信号处理 捕获
    ret = signal(SIGINT,sigfun);
    if(ret == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("ret = %p\n",ret);//之前处理过2号信号，成功返回上一次信号处理方式SIG_IGN = 1
    //for(;;);
  
    //恢复默认处理方式
    ret = signal(SIGINT,SIG_DFL);
    if(ret == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("ret = %p\n",ret);//之前处理过2号信号，成功返回上一次信号处理方式sigfun，返回sigfun的地址。
    printf("fun = %p\n",sigfun);
    for(;;);
    return 0;
}

#endif

/*忽略2号信号
 (base) 176x212x32x15:day14 wyl$ gcc 01_signal.c -o si
 (base) 176x212x32x15:day14 wyl$ ./si
 ret = 0x0
 ^C^C^C^C^C^C^C^C^\Quit: 3。   //按ctrl+\退出
 */

/*第二次对2号信号处理 捕获
 (base) 176x212x32x15:day14 wyl$ gcc 01_signal.c -o si
 (base) 176x212x32x15:day14 wyl$ ./si
 ret = 0x0
 ret = 0x1
 ^C捕获到2号信号
 ^C捕获到2号信号
 ^C捕获到2号信号
 ^C捕获到2号信号
 ^C捕获到2号信号
 ^C捕获到2号信号
 çç^\Quit: 3      //按ctrl+\退出
 */

/*恢复默认处理方式
 (base) 176x212x32x15:day14 wyl$ gcc 01_signal.c -o si
 (base) 176x212x32x15:day14 wyl$ ./si
 ret = 0x0
 ret = 0x1
 ret = 0x10d35cdf0
 fun = 0x10d35cdf0
 ^C                     //按ctrl+c退出
 */
