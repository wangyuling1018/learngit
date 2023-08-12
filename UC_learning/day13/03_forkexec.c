
/*
 ●调用exec函数固然可以创建出新的进程，但是新进程会取代原来的进程。如果既想创建新的进程，同时又希望原来的
  进程继续存在，则可以考虑fork+ exec模式，即在fork产生的子进程里调用exec函数，新进程取代了子进程，但父进程依然存在
 */
#if 0
// fork + exec
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程变身
    if(pid == 0){
        if(execl("/bin/ls","ls","-i","-l",NULL) == -1){
            perror("execl");
            return -1;
        }
        //return 0; 可以不写，execl成功后，变身成ls，执行ls，执行完ls后return
    }
    //父进程回收子进程僵尸
    int s;//用来输出子进程的终止状态
    pid_t childpid = waitpid(-1,&s,0);
    if(childpid == -1){
        perror("waitpid");
        return -1;
    }
    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }

    
    pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    if(pid == 0){
        if(execl("./new","new","123","hello",NULL) == -1){
            perror("execl");
            return -1;
        }
        //return 0;
    }

    childpid = waitpid(-1,&s,0);
    if(childpid == -1){
        perror("waitpid");
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
 (base) 176x212x32x15:day13 wyl$ gcc 03_forkexec.c -o fe
 (base) 176x212x32x15:day13 wyl$ ./fe
 total 480
 108352517 -rw-rw-r--@ 1 wyl  staff    445  9  4  2022 01_new.c
 108431522 -rw-rw-r--@ 1 wyl  staff   9413  5 30 11:05 02_exec.c
 108431137 -rw-rw-r--@ 1 wyl  staff   1578  5 30 11:05 03_forkexec.c
 108346616 -rwxr-xr-x  1 wyl  staff  49648  5 29 17:51 a.out
 108426291 -rw-r--r--@ 1 wyl  staff   8634  5 30 11:02 bj_13
 108417198 -rwxr-xr-x  1 wyl  staff  49696  5 30 10:55 exec
 108432624 -rwxr-xr-x  1 wyl  staff  49608  5 30 11:06 fe
 108353305 -rwxr-xr-x  1 wyl  staff  49472  5 29 17:55 new
 正常终止:0
 PID : 5315
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
 CONDA_SHLVL=1
 CONDA_PROMPT_MODIFIER=(base)
 TERM_PROGRAM_VERSION=445
 TERM_SESSION_ID=7A7B1BC2-0EF9-47B7-BB26-836D2C5C6F74
 USER=wyl
 LD_LIBRARY_PATH=/usr/local/Cellar/qt/6.4.2_2/lib:
 CONDA_EXE=/Users/wyl/Anaconda/anaconda3/bin/conda
 SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.XSNniSj08C/Listeners
 _CE_CONDA=
 PATH=/usr/local/Cellar/qt/6.4.2_2/bin:/usr/local/mysql-5.7.20-macos10.12-x86_64/bin:/usr/local/mysql-connector-c++-8.0.33/lib64:/usr/local/mysql-5.7.20-macos10.12-x86_64/bin/mysql_config:/usr/local/bin:/usr/local/sbin:/Users/wyl/Anaconda/anaconda3/bin:/Users/wyl/Anaconda/anaconda3/condabin:/Volumes/cmake-3.25.0-rc2-macos-universal/CMake.app/Contents/bin:/Library/Frameworks/Python.framework/Versions/3.7/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public:/usr/local/share/dotnet:~/.dotnet/tools:/Library/Apple/usr/bin:/Library/Frameworks/Mono.framework/Versions/Current/Commands:/Applications/Xamarin Workbooks.app/Contents/SharedSupport/path-bin
 LaunchInstanceID=32F3E6CE-DC8A-410C-9764-E8323BA91888
 CONDA_PREFIX=/Users/wyl/Anaconda/anaconda3
 __CFBundleIdentifier=com.apple.Terminal
 PWD=/Users/wyl/C++_Projects/UC_learning/day13
 LANG=zh_CN.UTF-8
 XPC_FLAGS=0x0
 _CE_M=
 XPC_SERVICE_NAME=0
 HOME=/Users/wyl
 SHLVL=1
 HOMEBREW_PREFIX=/usr/local
 LOGNAME=wyl
 CONDA_DEFAULT_ENV=base
 INFOPATH=/usr/local/share/info:
 HOMEBREW_CELLAR=/usr/local/Cellar
 SECURITYSESSIONID=186a6
 _=./fe
 --------------------------
 正常终止:0

 */
