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
int connect(int sockfd, struct sockaddr const* addr, socklen_t addrlen);
    功能:将套接字和对方的地址结构连接在一起
    参数:sockfd:套接字描述符
        addr:对方的地址结构。
        addrlen:地址结构的字节数
    返回值:成功返回0，失败返回-1。

#include <sys/socket.h>
ssize t recv(int sockfd, void* buf, size t count, int flags);
    功能:接收数据
    参数:若flags取0则与read函数完全等价，另外也可取以下值:
        MSG_DONTWAIT -以非阻塞方式接收数据.
        MSG_OOB -接收带外数据。
        MSG_WAITALL -等待所有数据，即不接收到count字节就不返回。
    返回值:成功返回实际接收到的字节数，失败返回-1。
    //返回值=0，表示客户端关闭通信套接字连接。

#include <sys/socket.h>
ssize_t send(int sockfd, void const* buf, size_t count, int flags);
    功能:发送数据
    参数:若flags取0则与write函数完全等价，另外也可取以下值:
            MSG_DONTWAIT-以非阻塞方式接收数据。
            MSG_OOB - 接收带外数据。
            MSG_DONTROUTE-不查路由表，直接在本地网络中寻找目的主机
    返回值:成功返回实际发送的字节数，失败返回-1。
 
 编程模型
     步骤    服务器    服务器           客户机           客户机       步骤
     1    创建套接字    socket         socket          创建套接字     1
     2    准备地址结构  sockaddr_in    sockaddr_in     准备地址结构    2
     3    绑定地址      bind           ————           ————          ————
     4    启动侦听      listen         ————           ————          ————
     5    等待连接      accept         connect         请求连接       3
     6    接收请求      recv           send            发送请求       4
     7    发送响应      send           recv            接收响应       5
     8    关闭套接字    close           close           关闭套接字      6

 */

//客户机的端口是随机的，服务器的端口是固定的
#if 0

//tcp客户端
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

int main(void){
    //创建套接字
    printf("客户端:创建套接字\n");
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    //组织服务器的地址结构
    printf("客户端:组织服务器的地址结构\n");
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(8989); //8989:服务器端口
    ser.sin_addr.s_addr = inet_addr("176.212.32.15"); //服务器的ip地址
    //向服务器发起连接请求
    printf("客户端:向服务器发起连接请求\n");
    if(connect(sockfd,(struct sockaddr*)&ser,sizeof(ser)) == -1){ //3次握手，第一次起始客户端的connect，结束于服务器的accept
        perror("connect");
        return -1;
    }
    //业务处理
    printf("客户端:业务处理\n");
    for(;;){
        //发送小写的串
        char buf[128] = {};
        fgets(buf,sizeof(buf),stdin);
        if(send(sockfd,buf,strlen(buf),0) == -1){
            perror("send");
            return -1;
        }
        if(strcmp(buf,"!\n") == 0){
            break;
        }
        //接受大写串
        ssize_t size = recv(sockfd,buf,sizeof(buf)-1,0);
        if(size == -1){
            perror("recv");
            return -1;
        }
        printf(">>%s",buf);
    }
    //关闭套接字
    printf("客户端:关闭套接字\n");
    close(sockfd);//4次分手，第一次起始于客户端的close，结束于服务器的close
    return 0;
}
#endif


/*
 (base) 176x212x32x15:day22 wyl$ ./ser
 服务器:创建套接字
 服务器:组织地址结构
 服务器:绑定地址结构
 服务器:启动侦听
 服务器:等待客户端的连接
 服务器:接受到176.212.32.15:50814的客户端连接
 服务器:关闭通信套接字父
 服务器:等待客户端的连接
 服务器:业务处理
 服务器:客户端关闭套接字
 服务器:关闭通信套接字子
 父进程:捕获到20号信号
 服务器:回收了7994进程的僵尸
 服务器:没有子进程
 */
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
