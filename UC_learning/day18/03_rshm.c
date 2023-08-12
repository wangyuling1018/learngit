 /*
  ●基于共享内存实现进程间通信的编程模型
      步骤    进程A        函数                 进程B        步骤
      1    创建共享内存    shmget               获取共享内存    1
      2    加载共享内存    shmat                加载共享内存    2
      3    使用共享内存    strcpy/printf/...    使用共享内存    3     //memcpy
      4    卸载共享内存    shmdt                卸载共享内存    4
      5    销毁共享内存    shmctl               ————          ————
  */

#if 0
//读取共享内存
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
int main(void){
    //合成键
    printf("%d进程:合成键\n",getpid());
    key_t key = ftok(".",123);
    if(key == -1){
        perror("ftok");
        return -1;
    }
    //获取共享内存
    printf("%d进程:获取共享内存\n",getpid());
    int shmid = shmget(key,0,0);
    if(shmid == -1){
        perror("shmget");
        return -1;
    }
    //加载共享内存
    printf("%d进程:加载共享内存\n",getpid());
    char* shmaddr = shmat(shmid,NULL,0);
    if(shmaddr == (void*)-1){
        perror("shmat");
        return -1;
    }
    //读取共享内存
    getchar();
    printf("%d进程:读取共享内存\n",getpid());
    printf("%s\n",shmaddr);

    //卸载共享内存
    printf("%d进程:卸载共享内存\n",getpid());
    if(shmdt(shmaddr) == -1){
        perror("shmdt");
        return -1;
    }
    printf("%d进程:大功告成\n",getpid());
    return 0;
}
#endif

//开2个窗口
/*
 (base) 176x212x32x15:day18 wyl$ ./wshm
 34985进程:合成键
 34985进程:创建共享内
 34985进程:加载共享内存
                            //第一次按回车     //开第3个窗口，ipcs查看 状态：1
 34985进程:卸载共享内存
 //第三次按回车                   //开第3个窗口，ipcs查看 状态:1
 34985进程:删除共享内存
 34985进程:大功告成
                                //开第3个窗口，ipcs查看 状态:0

 */
/*
 (base) 176x212x32x15:day18 wyl$ ./rshm
 34994进程:合成键
 34994进程:获取共享内存
 34994进程:加载共享内存
                        //第二次按回车 //开第3个窗口，ipcs查看 状态:2
 34994进程:读取共享内存
 key=0x7b08cc68,shmid=131072,pid=34985
                        //开第3个窗口，ipcs查看 状态:2
 34994进程:卸载共享内存
 34994进程:大功告成
                        //开第3个窗口，ipcs查看 状态:1

*/




