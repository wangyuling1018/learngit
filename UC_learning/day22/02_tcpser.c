/*
 #include <sys/socket.h>
 int socket(int domain, int type, int protocol);
     功能:创建套接字
     参数:domain:通信域，协议族，可取以下值:
             AF_LOCAL/AF_UNIX -本地套接字，进程间通信
             AF_INET -基于IPv4的网络通信
             AF_INET6 -基于IPv6的网络通信
             AF_PACKET -基于底层包的网络通信
         type:套接字类型，可取以下值:
             SOCK_STREAM -流式套接字，基于TCP协议     //套接字工作在传输层，用的TCP协议，自上向下地压入协议栈的时候，每下压一层不需要手动加包头，协议栈自己做
             SOCK_DGRAM  -数据报套接字，基于UDP协议   //套接字工作在传输层，用的UDP协议，自上向下地压入协议栈的时候，每下压一层不需要手动加包头，协议栈自己做
             SOCK_RAW    -原始套接字，工作在传输层以下 //如果套接字工作在物理层，自上向下地压入协议栈的时候，每下压一层需要手动加包头（从应用层开始往下加，直到物理层）
         protocol:特殊协议，对于流式和数据报套接字而言，只能取0
     返回值:成功返回表示套接字对象的文件描述符，失败返回-1。   //返回的是侦听套接字
     //套接字工作在物理层，有优势，例如：嗅探工具、抓包工具，如果套接字工作在应用层，抓包工具只能抓到TCP、UDP的包，其他类型的包抓不到。
     
 ●套接字接口库通过地址结构定位一个通信主体，可以是一个文件，可以是一台远程主机，也可以是执行者自己
     ➢基本地址结构，本身没有实际意义，仅用于泛型化参数    //泛化类型sockaddr，类似void*，sockaddr_un*、sockaddr_in*都可以转换为sockaddr*
         struct sockaddr {
             familyt sa_family;//地址族
             char sa_data[14];//地址值
         };
     ➢本地地址结构，用于AF_LOCAL/AF_UNIX域的本地通信
         struct sockaddr_un {
             sa_family_t sun_family; // 地址族(AF_LOCAL/AF_UNIX)
             char sun_path[];//本地套接字文件的路径
         };
     ➢网络地址结构，用于AF_INET域的IPv4网络通信
         struct sockaddr_in {
             sa_family_t sin_family; //地址族(AF_INET)
             in port_t sin_port;//端口号(0~65535)-unsigned short
             struct in_addr sin_addr;// IP地址- unsigned int
         };
         struct in_addr{
             in_addr_t s_addr;
         };
         typedef uint16_t in_port_t;//无符号16位整数
         typedef uint32_t in_addr_t; //无符号32位整数
 
 #include <sys/socket.h>
 int bind(int sockfd, struct sockaddr const* addr, socklen_t addrlen);
     功能:将套接字和本机的地址结构绑定在-起
     参数: sockfd: 套接字描述符。
          addr:自己的地址结构。
          addrlen:地址结构的字节数
     返回值:成功返回0,失败返回-1。

 #include <sys/socket.h>
 int connect(int sockfd, struct sockaddr const* addr, socklen_t addrlen);
     功能:将套接字和对方的地址结构连接在一起
     参数:sockfd:套接字描述符
         addr:对方的地址结构。
         addrlen:地址结构的字节数
     返回值:成功返回0，失败返回-1。
 
 #include <sys/socket.h>
 int listen(int sockfd, int backlog)
     功能:启动侦听:在指定套接字上启动对连接请求的侦听功能
     参数:sockfd:套接字描述符，在调用此函数之前是一个主动套接字，是不能感知连接请求的，在调用此函数并成功返回
                之后，是一个被动套接字，具有感知连接请求的能力。
          backlog:未决连接请求队列的最大长度，- -般取不小于1024的值。 //等待连接请求的有多少个，不少于1024个
     返回值:成功返回0，失败返回-1。
     
 #include <sys/socket.h>
 int accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen);
     功能:等待并接受连接请求，在指定套接字上阻塞，直到连接建立完成。
     参数:sockfd:侦听套接字描述符。
         addr:输出连接请求发起方的地址信息。        //输出客户端的地址信息
         addrlen:输出连接请求发起方的地址信息字节数。//输出客户端的地址信息字节数
     返回值:成功返回可用于后续通信的连接套接字描述符，失败返回-1。  //返回的是通信套接字
     //accept函数表示3次握手完成
 
 #include <unistd.h>
 ssize_t write(int fd, void const* buf, size_t count);
     功能:向指定的文件写入数据
     参数:fd：文件描述符
         buf：内存缓冲区，即要写入的数据
         count：期望写入的字节数     //期望与实际的有时候并不是一致的
     返回值:成功返回实际写入的字节数，失败返回-1。
    //从buf向fd写入count个字节

 #include <unistd.h>
 ssize_t read(int fd, void* buf, size_t count);
 功能:从指定的文件中读取数据
 参数:fd：文件描述符
     buf：内存缓冲区，存读取到的数据
     count：期望读取的字节数
 返回值:成功返回实际读取的字节数，失败返回-1。
 笔记：
     返回值>0，表示实际读取的字节数。
     返回值=0，表示正常读完文件。
     返回值=-1，表示失败

 
 编程模型
     步骤    服务器    服务器           客户机           客户机       步骤
     1    创建套接字    socket         socket          创建套接字     1
     2    准备地址结构  sockaddr_in    sockaddr_in     准备地址结构    2
     3    绑定地址      bind           ————           ————          ————
     4    启动侦听      listen         ————           ————          ————
     5    等待连接      accept         connect         请求连接       3
     6    接收请求      recv           send            发送请求       4
     7    发送响应      send           recv            接收响应       5
     8    关闭套接字    close          close            关闭套接字      6

 */
#if 0
/*
 一个服务器与多个客户机进行多次进行通信：
    父进程只负责接请求和建立连接，子进程负责通信
    for(){
        accept(); //父进程等客户端发请求，并建立连接
        fork();
        if(pid == 0){ //子进程进行通信
            //业务处理
        }
    }
 */
//TCP服务器
#include<stdio.h>
#include<ctype.h> //toupper
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<signal.h>
#include<sys/wait.h>
#include<errno.h>

//信号处理函数,负责收尸
void sigchild(int signum){
    printf("父进程:捕获到%d号信号\n",signum);
    for(;;){
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        if(pid == -1){
            if(errno == ECHILD){
                printf("服务器:没有子进程\n");
                break;
            }else{
                perror("waitpid");
                return;
            }
        }else if(pid == 0){
            printf("服务器:子进程都在运行\n");
            break;
        }else{
            printf("服务器:回收了%d进程的僵尸\n",pid);
        }
    }
}

int main(void){
    //捕获17号信号
    if(signal(SIGCHLD,sigchild) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //创建套接字
    printf("服务器:创建套接字\n");
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    //准备地址结构,代表服务器身份
    printf("服务器:组织地址结构\n");
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(8989);//字节序转换保证协议栈拿到正确的端口号
    //ser.sin_addr.s_addr = inet_addr("192.168.222.128");
    ser.sin_addr.s_addr = INADDR_ANY;//接受任意IP地址到来的数据
    
    //绑定套接字和地址结构
    printf("服务器:绑定地址结构\n");
    if(bind(sockfd,(struct sockaddr*)&ser,sizeof(ser)) == -1){
        perror("bind");
        return -1;
    }
    //开启侦听 
    printf("服务器:启动侦听\n");
    if(listen(sockfd,1024) == -1){
        perror("listen");
        return -1;
    }
    //等待并接受客户端的连接请求
    //accept 返回后续用来和客户端通信的套接字
    //accept 函数结束,意味着三次握手完成
    for(;;){
        //父进程等待客户端的连接
        printf("服务器:等待客户端的连接\n");
        struct sockaddr_in cli;//用来输出客户端的地址结构
        socklen_t len = sizeof(cli);//用来输出客户端地址结构字节数
        int conn = accept(sockfd,(struct sockaddr*)&cli,&len);
        if(conn == -1){
            perror("accept");
            return -1;
        }
        printf("服务器:接受到%s:%hu的客户端连接\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
        //创建子进程,负责和客户端进行通信
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        //子进程代码
        if(pid == 0){
            //业务处理
            //接受客户端发来的小写的串
            close(sockfd); //子进程继承父进程2个套接字（sockfd，conn），其中sockfd子进程不用，先关闭sockfd
            printf("服务器:业务处理\n");
            for(;;){
                char buf[128] = {};
                ssize_t size = read(conn,buf,sizeof(buf)-1);
                if(size == -1){
                    perror("read");
                    return -1;
                }
                if(size == 0){
                    printf("服务器:客户端关闭套接字\n");
                    break;
                }
                //转换成大写
                for(int i = 0;i < size;i++){
                    buf[i] = toupper(buf[i]);
                }
                //发送回给客户端
                if(write(conn,buf,size) == -1){
                    perror("write");
                    return -1;
                }
            }
            //子进程,通信结束,关闭通信套接字
            printf("服务器:子进程关闭通信套接字\n");
            close(conn);
            return 0;
        }
        //父进程代码,关闭套接字
        printf("服务器:父进程关闭通信套接字\n");
        close(conn); //父进程不用conn套接字，先关闭
    }
    close(sockfd);
    return 0;
}

#endif
/*
(base) 176x212x32x15:day22 wyl$ gcc 02_tcpser.c -o ser
(base) 176x212x32x15:day22 wyl$ ./ser
服务器:创建套接字
服务器:组织地址结构
服务器:绑定地址结构
服务器:启动侦听
服务器:等待客户端的连接
服务器:接受到176.212.32.15:51155的客户端连接            //开多个客户机窗口
服务器:父进程关闭通信套接字
服务器:等待客户端的连接
服务器:业务处理
服务器:客户端关闭套接字
服务器:子进程关闭通信套接字
父进程:捕获到20号信号                        // 备注：linux的17号信号是SIGCHLD，macos系统的17号信号是SIGSTOP
服务器:回收了10432进程的僵尸
服务器:没有子进程
服务器:接受到176.212.32.15:51245的客户端连接        //开多个客户机窗口
服务器:父进程关闭通信套接字
服务器:等待客户端的连接
服务器:业务处理
服务器:客户端关闭套接字
服务器:子进程关闭通信套接字
父进程:捕获到20号信号
服务器:回收了11065进程的僵尸
服务器:没有子进程
服务器:接受到176.212.32.15:51253的客户端连接        //开多个客户机窗口
服务器:父进程关闭通信套接字
服务器:等待客户端的连接
服务器:业务处理
服务器:客户端关闭套接字
服务器:子进程关闭通信套接字
父进程:捕获到20号信号
服务器:回收了11147进程的僵尸
服务器:没有子进程
*/

//开多个./cli窗口
/*
 (base) 176x212x32x15:day22 wyl$ ./cli
 客户端:创建套接字
 客户端:组织服务器的地址结构
 客户端:向服务器发起连接请求
 客户端:业务处理
 hello
 >>HELLO
 world
 >>WORLD
 wangyuling
 >>WANGYULING
 !
 客户端:关闭套接字
 */
/*
(base) 176x212x32x15:day22 wyl$ ./cli
客户端:创建套接字
客户端:组织服务器的地址结构
客户端:向服务器发起连接请求
客户端:业务处理
inag;ngag
>>INAG;NGAG
!
客户端:关闭套接字
*/
/*
 (base) 176x212x32x15:day22 wyl$ ./cli
 客户端:创建套接字
 客户端:组织服务器的地址结构
 客户端:向服务器发起连接请求
 客户端:业务处理
 ingneagnag
 >>INGNEAGNAG
 !
 客户端:关闭套接
 */


/*备注：linux的17号信号是SIGCHLD，macos系统的17号信号是SIGSTOP
macos系统下查看信号：
 (base) 176x212x32x15:day22 wyl$ kill -l
  1) SIGHUP     2) SIGINT     3) SIGQUIT     4) SIGILL
  5) SIGTRAP     6) SIGABRT     7) SIGEMT     8) SIGFPE
  9) SIGKILL    10) SIGBUS    11) SIGSEGV    12) SIGSYS
 13) SIGPIPE    14) SIGALRM    15) SIGTERM    16) SIGURG
 17) SIGSTOP    18) SIGTSTP    19) SIGCONT    20) SIGCHLD
 21) SIGTTIN    22) SIGTTOU    23) SIGIO    24) SIGXCPU
 25) SIGXFSZ    26) SIGVTALRM    27) SIGPROF    28) SIGWINCH
 29) SIGINFO    30) SIGUSR1    31) SIGUSR2
 */
