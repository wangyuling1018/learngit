/*
 僵尸进程
     ●父进程创建子进程以后，子进程在操作系统的调度下与其父进程同时运行。如果子进程先于父进程终止，但由于某种原因，
      父进程并没有回收该子进程的终止状态，这时子进程即处于僵尸状态，被称为僵尸进程
     ●僵尸进程虽然已不再活动，即不会继续消耗处理机资源，但其所携带的进程终止状态会消耗内存资源。因此，
      作为程序的设计者，无论对子进程的终止状态是否感兴趣，都应该尽可能及时地回收子进程的僵尸。
      
 */

#if 0

//僵尸进程演示
#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("%d进程:我是父进程,创建子进程\n",getpid());
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1; //进程正常终止
    }
    
    //子进程代码
    if(pid == 0){
        printf("%d进程:我是子进程,马上结束,变僵尸\n",getpid());
        return 0;
    }
    //父进程代码
    printf("%d进程:我是父进程,我很忙\n",getpid());
    sleep(10);//10s内，子进程是僵尸
    //wait  waitpid
    return 0;
}
#endif

/*
 (base) wangyulingdeMacBook-Pro:day11 wyl$ gcc 05_zombie.c -o zom
 (base) wangyulingdeMacBook-Pro:day11 wyl$ ./zom
 22766进程:我是父进程,创建子进程
 22766进程:我是父进程,我很忙
 22767进程:我是子进程,马上结束,变僵尸
 
 再开一个窗口：ps aux ,22767的状态是Z+
 USER               PID  %CPU %MEM      VSZ    RSS   TT  STAT STARTED      TIME COMMAND
 wyl              22767   0.0  0.0        0      0 s000  Z+    3:29下午   0:00.00 (zom)
 */
