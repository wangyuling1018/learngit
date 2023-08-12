/*
 ●基于消息队列实现进程间通信的编程模型
     步骤    进程A       函数              进程B         步骤
     1    创建消息队列    msgget           获取消息队列    1
     2    发送接收消息    msgsnd/msgrcv    发送接收消息    2
     3    销毁消息队列    msgctl           ————          ————
 */


#if 0

//读取消息队列
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/msg.h>

int main(void){
    //合成键
    printf("%d进程:合成键\n",getpid());
    key_t key = ftok(".",100);
    if(key == -1){
        perror("ftok");
        return -1;
    }
    //获取消息队列
    printf("%d进程:获取消息队列\n",getpid());
    int msgid = msgget(key,0);
    if(msgid == -1){
        perror("msgid");
        return -1;
    }
    //读取消息队列
    printf("%d进程:接收数据\n",getpid());
    for(;;){
        struct{
            long type;//消息类型
            char data[128];//消息内容
        } msgbuf = {};
        ssize_t size = msgrcv(msgid,&msgbuf,sizeof(msgbuf.data)-1,100,/*0*/ IPC_NOWAIT);
        if(size == -1){
            if(errno == EIDRM){//对方销毁消息队列   //阻塞方式，对方的消息队列销毁后，走这里退出
                printf("%d进程:对方销毁消息队列\n",getpid());
                break;
            }else if(errno == ENOMSG){ //非阻塞方式，需要增加的条件判断
                printf("%d进程;暂时没有消息,一会再来....\n",getpid());
                sleep(1);
            }else{                     //非阻塞方式，对方的消息队列销毁后，走这里退出，原因：不是守着msgrcv，每次循环进msgrcv看看消息队列，当突然有一次进入发现msgrcv发现消息队列没有了，就会报错
                perror("msgrcv");
                return -1;
            }
        }else{  
            printf("%ld>>%s",msgbuf.type,msgbuf.data);
        }
    }
    printf("%d进程:大功告成\n",getpid());

    return 0;
}


#endif

//开2个窗口

//-----------msgrcv函数的参数msgflag = 0,阻塞-------------------
/*
 (base) 176x212x32x15:day19 wyl$ ./wmsg
 7934进程:合成键
 7934进程:创建消息队列
 7934进程:发送消息
 ijgnagna                   //开第3个窗口，ipcs查看消息数量、已用字节数
 gianga;gn
 ieennene
 !
 7934进程:销毁消息队里
 7934进程:大功告成
 */
/*
 (base) 176x212x32x15:day19 wyl$ ./rmsg
 7939进程:合成键
 7939进程:获取消息队列
 7939进程:接收数据
 100>>ijgnagna              //开第3个窗口，ipcs查看消息数量、已用字节数
 100>>gianga;gn
 100>>ieennene
 7939进程:对方销毁消息队列
 7939进程:大功告成
 */

//--------msgrcv函数的参数msgflag = IPC_NOWAIT,非阻塞-----------
/*
 (base) 176x212x32x15:day19 wyl$ ./wmsg
 8443进程:合成键
 8443进程:创建消息队列
 8443进程:发送消息
 gag                    //开第3个窗口，ipcs查看消息数量、已用字节数
 ging
 ingagn
 !
 8443进程:销毁消息队里
 8443进程:大功告成
 */
/*
 (base) 176x212x32x15:day19 wyl$ ./rmsg
 8446进程:合成键
 8446进程:获取消息队列
 8446进程:接收数据
 8446进程;暂时没有消息,一会再来....         //开第3个窗口，ipcs查看消息数量、已用字节数
 8446进程;暂时没有消息,一会再来....
 8446进程;暂时没有消息,一会再来....
 100>>gag
 8446进程;暂时没有消息,一会再来....
 100>>ging
 8446进程;暂时没有消息,一会再来....
 100>>ingagn
 8446进程;暂时没有消息,一会再来....
 msgrcv: Invalid argument       //对方销毁，走的是报错

 */
