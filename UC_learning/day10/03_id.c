/*
 #include <unistd.h>
 pid_t getpid(void);//返回调用进程的PID水印
 pid_t getppid(void);//返回调用进程的父进程的PID
 uid_t getuid(void);//返回调用进程的实际用户ID
 gid_t getgid(void);//返回调用进程的实际组ID
 uid_t geteuid(void);//返回调用进程的有效用户ID
 gid_t getegid(void);//返回调用进程的有效组ID
 */

#if 0
//进程的各种I
#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("    进程的PID:%d\n",getpid());
    printf("  父进程的PID:%d\n",getppid());
    printf("   实际用户ID:%d\n",getuid());
    printf("     实际组ID:%d\n",getgid());
    printf("   有效用户ID:%d\n",geteuid());
    printf("     有效组ID:%d\n",getegid());
    return 0;
}
#endif
//不同的用户有不同的id，有效用户id决定了进程访问系统资源的能力。
/*
 进程的PID:11727
父进程的PID:11728
实际用户ID:501
  实际组ID:20
有效用户ID:501
  有效组ID:20
 */
