/*
 #include < stdlib.h>
 int system (const char* command);
     ➢功能:执行shell命令
     ➢参数: command shell命令行字符串
     ➢返回值:成功返回command进程的终止状态，失败返回-1

 ➢system函数执行command参数所表示的命令行，并返回命令进程的终止状态
 ➢若command参数取NULL,返回非0表示Shell可用，返回0表示Shell不可用

 ●在system函数内部调用了vfork、 exec和waitpid等函数
     ➢如果调用vfork或waitpid函数出错，则返回-1
     ➢如果调用exec函数出错，则在子进程中执行exit(127)
     ➢如果都成功，则返回command进程的终止状态(由waitpid的status参数获得)

 ●使用system函数而不用vfork+exec的好处是，system函数针对各种错误和信号都做了必要的处理，
  而且system是标准库函数，可跨平台使
  
 笔记：
     1、system是标准库函数，对应shell命令而言不一定敲在终端窗口的命令行中，我也可以在程序执行的时候通过函数执行。
     2、command是你想执行的命令。
     3、system底层干的事情就是fork+exec+waitpid。
     4、vfork创建子进程。fork创建子进程，会复制一份父进程的数据，exec变身后覆盖复制过来的数据。vfork创建子进程，
      父进程会被挂起，子进程暂时用一下父进程的数据，不会复制一份父进程的数据，exec变身后子进程就自己的数据了。
      所以变身的时候基本上都选用vfork。

 */

#if 0
//system函数演示
#include<stdio.h>
#include<stdlib.h>//system
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    int s = system("ls -i -l");
    if(s == -1){
        perror("system");
        return -1;
    }
    
    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }

    s = system("./new");
    if(s == -1){
        perror("system");
        return -1;
    }

    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }
    return 0;
}
#endif

/*
 (base) 176x212x32x15:day13 wyl$ gcc 04_system.c -o sys
 (base) 176x212x32x15:day13 wyl$ ./sys
 total 600
 108352517 -rw-rw-r--@ 1 wyl  staff    445  9  4  2022 01_new.c
 108431522 -rw-rw-r--@ 1 wyl  staff   9413  5 30 11:05 02_exec.c
 108454272 -rw-rw-r--@ 1 wyl  staff   4163  5 30 11:22 03_forkexec.c
 108454360 -rw-rw-r--@ 1 wyl  staff    628  5 30 11:22 04_system.c
 108346616 -rwxr-xr-x  1 wyl  staff  49648  5 29 17:51 a.out
 108426291 -rw-r--r--@ 1 wyl  staff   8634  5 30 11:02 bj_13
 108417198 -rwxr-xr-x  1 wyl  staff  49696  5 30 10:55 exec
 108432624 -rwxr-xr-x  1 wyl  staff  49608  5 30 11:06 fe
 108353305 -rwxr-xr-x  1 wyl  staff  49472  5 29 17:55 new
 108454703 -rwxr-xr-x  1 wyl  staff  49520  5 30 11:22 sys
 正常终止:0
 PID : 6848
 ---------命令行参数-------
 ./new
 ----------环境变量--------
 MANPATH=/usr/local/share/man:
 TERM_PROGRAM=Apple_Terminal
 SHELL=/bin/bash
 TERM=xterm-256color
 HOMEBREW_BOTTLE_DOMAIN=https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles/
 TMPDIR=/var/folders/g7/kgb_s0491sx7t8hqgwxd25nh0000gn/T/
 HOMEBREW_REPOSITORY=/usr/local/Homebrew
 CONDA_SHLVL=1
 TERM_PROGRAM_VERSION=445
 CONDA_PROMPT_MODIFIER=(base)
 TERM_SESSION_ID=7A7B1BC2-0EF9-47B7-BB26-836D2C5C6F74
 USER=wyl
 LD_LIBRARY_PATH=/usr/local/Cellar/qt/6.4.2_2/lib:
 CONDA_EXE=/Users/wyl/Anaconda/anaconda3/bin/conda
 SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.XSNniSj08C/Listeners
 _CE_CONDA=
 PATH=/usr/local/Cellar/qt/6.4.2_2/bin:/usr/local/mysql-5.7.20-macos10.12-x86_64/bin:/usr/local/mysql-connector-c++-8.0.33/lib64:/usr/local/mysql-5.7.20-macos10.12-x86_64/bin/mysql_config:/usr/local/bin:/usr/local/sbin:/Users/wyl/Anaconda/anaconda3/bin:/Users/wyl/Anaconda/anaconda3/condabin:/Volumes/cmake-3.25.0-rc2-macos-universal/CMake.app/Contents/bin:/Library/Frameworks/Python.framework/Versions/3.7/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public:/usr/local/share/dotnet:~/.dotnet/tools:/Library/Apple/usr/bin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/Applications/Xamarin Workbooks.app/Contents/SharedSupport/path-bin
 _=./new
 LaunchInstanceID=32F3E6CE-DC8A-410C-9764-E8323BA91888
 __CFBundleIdentifier=com.apple.Terminal
 CONDA_PREFIX=/Users/wyl/Anaconda/anaconda3
 PWD=/Users/wyl/C++_Projects/UC_learning/day13
 LANG=zh_CN.UTF-8
 XPC_FLAGS=0x0
 XPC_SERVICE_NAME=0
 _CE_M=
 SHLVL=2
 HOME=/Users/wyl
 HOMEBREW_PREFIX=/usr/local
 LOGNAME=wyl
 CONDA_DEFAULT_ENV=base
 HOMEBREW_CELLAR=/usr/local/Cellar
 INFOPATH=/usr/local/share/info:
 SECURITYSESSIONID=186a6
 --------------------------
 正常终止:0
 */






