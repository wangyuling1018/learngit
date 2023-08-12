/*
 ●exec不是一个函数而是一堆函数(共6个)，一般称为exec函数族。它们的功能是一样的，用法也很相近，只是参数的形式和数量略有不同
     #include <unistd.h>
     int execl(const char* path, const char* arg, ..);
         笔记： 1、execl = execute + list,执行 + 列表。
             2、path :可执行程序所在的路径。例如：./a.out
             3、arg,... ：arg + 可变长参数，执行程序的命令，例如：./a.out "a.out" "hello" "123" ,其中"a.out" "hello" "123"是可变长参数
             4、以NULL结束:execl("./a.out","a.out" "hello" "123",NULL);
     int execlp(const char* file, const char* arg, ...);
         笔记：1、file：文件名，根据PATH环境变量找这个文件，没找到execlp就报错
     int execle(const char* path, const char* arg, ..,char* const envp[]);
         笔记：
     int execv(const char* path, char* const argv[]);
     int execvp(const char* file, char* const argv[]);
     int execve(const char* path, char* const argv[],char* const envp[]);
 ●exec函数族一 共包括6个函数，它们的函数名都是在exec后面加上- 到两个字符后缀，不同的字符后缀代表不同的含义
     ➢l: 即list,新进程的命令行参数以字符指针列表(Const char* arg, ..)的形式传入,列表以空指针结束
     ➢p:即path,若第一一个参数中不包含"I"，则将其视为文件名，并根据PATH环境变量搜索该文件
     ➢e:即environment,新进程的环境变量以字符指针数组(char* const envp[])的形式传入, 数组以空指针结束，
       不指定环境变量则从调用进程复制
     ➢V:即vector,新进程的命令行参数以字符指针数组(char* const argv[])的形式传入，数组以空指针结束
 ●其实6个exec函数中只有execve是真正的系统调用，其它5个函数不过是对execve函数的简单包装
 ●调用exec函数不仅改变调用进程的地址空间和进程映像，调用进程的一些属性也发生了变化
     ➢任何处于阻塞状态的信号都会丢失
     ➢被设置为捕获的信号会还原为默认操作
     ➢有关线程属性的设置会还原为缺省值
     ➢有关进程的统计信息会复位
     ➢与进程内存相关的任何数据都会丢失，包括内存映射文件
     ➢标准库在用户空间维护的一切数据结构(如通过atexit或on_exit函数注册的退出处理函数)都会丢失
 ●但也有些属性会被新进程继承下来，比如PID、PPID、实际用户ID和实际组ID、优先级，以及文件描述符等
 ●注意如果进程创建成功，exec函数是不会返回的，因为成功的exec调用会以跳转到新进程的入口地址作为结束，
   而刚刚运行的代码是不会存在于新进程的地址空间中的。但如果进程创建失败，exec函数会返回-1
 ●调用exec函数固然可以创建出新的进程，但是新进程会取代原来的进程。如果既想创建新的进程，同时又希望原来的
  进程继续存在，则可以考虑fork+ exec模式，即在fork产生的子进程里调用exec函数，新进程取代了子进程，但父进程依然存在

 笔记：
     6、execl执行成功后是不返回的。因为：execl是旧进程调用的，execl一旦成功了就开始执行新进程了，
      返回给谁呢？返回给旧进程吗？旧进程已经被取代了。返回给新进程吗？又不是新进程调用的execl。
     7、进程的取代一般用于bash上。在bash上敲./a.out或ls，这些可执行程序./a.out和ls都是bash的子进程。
      bash和这些子进程之间的关系是啥呢？实际上是用到了execl和fork的组合。当在命令行上敲./a.out的时候，bash就开始忙了，
      bash会创建（fork）一个子进程，创建子进程后，bash会控制这个子进程execl变身成a.out，所以这个子进程就是a.out
     8、新进程取代旧进程，实际上是一个进程，并不是2个进程，只是我干的活不一样了而已。PID没有变，是一个进程，
      只是前后所执行的功能发生了改变了而已。
     9、新进程和旧进程不是父子关系，是对等关系。且变身前后的父子关系没有变更，之前父进程是谁，现在父进程还是谁。
     10、.bashrc文件是脚本文件，里面有很多命令的别名，例如：“ls”的别名是“--color=auto”，在终端窗口上执行ls，
      默认执行的是--color=auto。.bashrc文件影响的是bash，在bash下执行ls，ls是bash的子进程，
      那么ls就会受到.bashrc文件的影响，继承关系。很多关于bash的操作都会写到.bashrc文件中。
     11、fork创建子进程，这个子进程是父进程的副本，子进程所执行的功能具有一定的局限性。而单纯用exec，原有的功能又会被取代掉。
      如果既想执行一些新奇的功能，又想保留原有的功能，就用fork+exec模式。fork创建子进程，然后让子进程做exec变身。
     12、Execlp:file是文件名，execlp=execl + PATH环境变量。execlp依次到PATH环境变量中记录的路径中找你要变身的文件。
      如果所有的路径都没有找到，那么execlp就会报错。
     13、Execle：execl + envp环境变量。变身为什么要环境变量？子进程会继承父进程环境变量的内容，变身如果没有做特别的指定的话，
      变身前的环境变量和变身后的环境变量一样。现在想要给变身后的环境变量做一个指定。通过指定环境变量实现变身前和变身后进程的信息传递。
      如果想要给变身后的进程传递点什么东西？可以通过指定环境变量。。。
     14、Execv = exec + vector向量，vector向量就是指更加好用的数组。将命令行参数以数组的形式传递进来。
     15、Execl = exec + list列表。将命令行参数以列表的形式传递进来。
 */

#if 0
//exec家族函数
#include<stdio.h>
#include<unistd.h>

int main(void){
    //setbuf(stdout,NULL);//关闭输出缓冲区

    printf("%d进程:我马上就要变身了\n",getpid());
    
    /*情况1
    //if(execl("./new","./new","123","hello",NULL) == -1){ 或
    if(execl("./new","new","123","hello",NULL) == -1){
        perror("execl");
        return -1;
    }*/
    /*情况2
     if(execl("/bin/ls","ls","-i","-l","--color=auto",NULL) == -1){
        perror("execl");
        return -1;
    }
    */

   /*情况3
     if(execlp("ls","ls","-l","--color=auto",NULL) == -1){
        perror("execlp");
        return -1;
    }
    */

    char* envp[] = {"NAME=laozhang","AGE=18","FOOD=liurouduan",NULL}; //以NULL结尾
    /*情况4
     if(execle("./new","new","123",NULL,envp) == -1){//envp是为 new可执行程序 指定的环境变量，旧进程的环境变量就丢失了
        perror("envp");
        return -1;
    }
    */
    ///*情况5
    
    char* argv[] = {"new","123","hello",NULL};
    if(execve("./new",argv,envp) == -1){
        perror("execve");
        return -1;
    }
     //*/
    printf("%d进程:哈哈哈哈,变身成功了\n",getpid());//原本的进程不在了，这段代码不会执行
    return 0;
}
#endif

/*情况1
 (base) wangyulingdeMacBook-Pro:day13 wyl$ gcc 02_exec.c -o exec
 (base) wangyulingdeMacBook-Pro:day13 wyl$ ./exec
 37022进程:我马上就要变身了
 PID : 37022
 ---------命令行参数-------
 new
 123
 hello
 ----------环境变量--------
 MANPATH=/usr/local/share/man:
 TERM_PROGRAM=Apple_Terminal
 TERM=xterm-256color
 SHELL=/bin/bash
 HOMEBREW_BOTTLE_DOMAIN=https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles/
 HOMEBREW_REPOSITORY=/usr/local/Homebrew
 TMPDIR=/var/folders/g7/kgb_s0491sx7t8hqgwxd25nh0000gn/T/
 */

/*情况2
 (base) 176x212x32x15:day13 wyl$ gcc 02_exec.c -o exec
 (base) 176x212x32x15:day13 wyl$ ./exec
 1551进程:我马上就要变身了
 total 352
 108352517 -rw-rw-r--@ 1 wyl  staff    445  9  4  2022 01_new.c
 108377620 -rw-rw-r--@ 1 wyl  staff   2047  5 30 10:27 02_exec.c
 108346616 -rwxr-xr-x  1 wyl  staff  49648  5 29 17:51 a.out
 108333531 -rw-r--r--@ 1 wyl  staff   8345  5 29 17:42 bj_13
 108378274 -rwxr-xr-x  1 wyl  staff  49560  5 30 10:28 exec
 108353305 -rwxr-xr-x  1 wyl  staff  49472  5 29 17:55 new
 */

/*情况3
 (base) 176x212x32x15:day13 wyl$ gcc 02_exec.c -o exec
 (base) 176x212x32x15:day13 wyl$ ./exec
 1696进程:我马上就要变身了
 total 352
 -rw-rw-r--@ 1 wyl  staff    445  9  4  2022 01_new.c
 -rw-rw-r--@ 1 wyl  staff   2396  5 30 10:29 02_exec.c
 -rwxr-xr-x  1 wyl  staff  49648  5 29 17:51 a.out
 -rw-r--r--@ 1 wyl  staff   8345  5 29 17:42 bj_13
 -rwxr-xr-x  1 wyl  staff  49560  5 30 10:29 exec
 -rwxr-xr-x  1 wyl  staff  49472  5 29 17:55 new
 */

/*情况4
 (base) 176x212x32x15:day13 wyl$ gcc 02_exec.c -o exec
 (base) 176x212x32x15:day13 wyl$ ./exec
 3411进程:我马上就要变身了
 PID : 3411
 ---------命令行参数-------
 new
 123
 ----------环境变量--------
 NAME=laozhang
 AGE=18
 FOOD=liurouduan
 --------------------------
 */

/*情况5
 (base) 176x212x32x15:day13 wyl$ gcc 02_exec.c -o exec
 (base) 176x212x32x15:day13 wyl$ ./exec
 4222进程:我马上就要变身了
 PID : 4222
 ---------命令行参数-------
 new
 123
 hello
 ----------环境变量--------
 NAME=laozhang
 AGE=18
 FOOD=liurouduan
 --------------------------
 */
