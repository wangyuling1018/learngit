/*
 ●基于消息队列实现进程间通信的编程模型
     步骤    进程A       函数              进程B         步骤
     1    创建消息队列    msgget           获取消息队列    1
     2    发送接收消息    msgsnd/msgrcv    发送接收消息    2
     3    销毁消息队列    msgctl           ————          ————
 */

#if 0
//写入消息队列
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>

int main(void){
    //合成键
    printf("%d进程:合成键\n",getpid());
    key_t key = ftok(".",100);
    if(key == -1){
        perror("ftok");
        return -1;
    }
    //创建消息队列
    printf("%d进程:创建消息队列\n",getpid());
    int msgid = msgget(key,IPC_CREAT | IPC_EXCL | 0664);
    if(msgid == -1){
        perror("msgget");
        return -1;
    }
    //写入消息队列
    printf("%d进程:发送消息\n",getpid());
    for(;;){
        //通过键盘获取要发送的数据
        struct {
            long type;//消息类型
            char data[128];//消息内容
        } msgbuf = {100,""};
        fgets(msgbuf.data,sizeof(msgbuf.data),stdin);

        //输入!结束循环
        if(strcmp(msgbuf.data,"!\n") == 0){
            break;
        }
    
        //将数据发送到消息队列
        if(msgsnd(msgid,&msgbuf,strlen(msgbuf.data),0) == -1){
            perror("msgsnd");
            return -1;
        }

    }
    //销毁消息队里
    printf("%d进程:销毁消息队里\n",getpid());
    if(msgctl(msgid,IPC_RMID,NULL) == -1){
        perror("msgctl");
        return -1;
    }
    printf("%d进程:大功告成\n",getpid());
    return 0;
}
#endif
//-----------msgrcv函数的参数msgflag = 0,阻塞-------------------
/*
 (base) 176x212x32x15:day19 wyl$ ./wmsg
 7934进程:合成键
 7934进程:创建消息队列
 7934进程:发送消息
 ijgnagna               //开第3个窗口，ipcs查看消息数量、已用字节数
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
 100>>ijgnagna          //开第3个窗口，ipcs查看消息数量、已用字节数
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
 8446进程;暂时没有消息,一会再来....             //开第3个窗口，ipcs查看消息数量、已用字节数
 8446进程;暂时没有消息,一会再来....
 8446进程;暂时没有消息,一会再来....
 100>>gag
 8446进程;暂时没有消息,一会再来....
 100>>ging
 8446进程;暂时没有消息,一会再来....
 100>>ingagn
 8446进程;暂时没有消息,一会再来....
 msgrcv: Invalid argument

 */



/*
 如果通过ctrl+c结束程序，消息队列没有手动撤销，再次运行程序就会报错，因为创建消息队列msgget的参数包含PC_EXCL，意思是已存在的消息队列就会返回-1
 通过ipcs查看已经存在的消息队列
 需要手动删除已经创建的消息队列，命令：ipcrm -q
 
(base) 176x212x32x15:day19 wyl$ ./wmsg
10314进程:合成键
10314进程:创建消息队列
10314进程:发送消息
^C                      //ctrl+c退出
(base) 176x212x32x15:day19 wyl$ ./wmsg      //再次运行
10327进程:合成键
10327进程:创建消息队列
msgget: File exists                         //报错，因为消息队列已经存在就会返回-1
(base) 176x212x32x15
*/
