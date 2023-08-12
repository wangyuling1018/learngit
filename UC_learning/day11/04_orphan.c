/*
 孤儿进程
     ●父进程创建子进程以后，子进程在操作系统的调度下与其父进程同时运行如果父进程先于子进程终止，子进程即成为孤儿进程，
      同时被某个专门的进程收养，即成为该进程的子进程，因此该进程又被称为孤儿院进程
 */

#if 0

//孤儿进程演示
#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("%d进程:我是父进程,我要创建子进\n",getpid());

    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代买
    if(pid == 0){
        printf("%d进程:我的父进程是%d\n",getpid(),getppid());
        sleep(2);
        printf("%d进程:我的父进程是%d\n",getpid(),getppid());
        return 0;
    }

    //父进程代码
    sleep(1);
    printf("%d进程:我是父进程,我马上死\n",getpid());
    return 0;
}
#endif

/*输出结果：
 (base) wangyulingdeMacBook-Pro:day11 wyl$ gcc 04_orphan.c
 (base) wangyulingdeMacBook-Pro:day11 wyl$ ./a.out
 22277进程:我是父进程,我要创建子进
 22281进程:我的父进程是22277
 22277进程:我是父进程,我马上死
 (base) wangyulingdeMacBook-Pro:day11 wyl$ 22281进程:我的父进程是1
 */
