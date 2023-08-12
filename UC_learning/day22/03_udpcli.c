/*
 #include <sys/socket.h>
 ssize_t recvfrom(int sockfd, void* buf, size_t count, int flags,
         struct sockaddr* src_addr, socklen_t* addrlen);
     功能:从哪里接收数据
     参数:前四个参数和函数recv相同
         src_addr:输出源主机的地址信息             //接收数据的同时，存一下对方的通信地址
         addrlen:输入输出源主机的地址信息的字节数。
     返回值:成功返回实际接收的字节数，失败返回-1

 #include <sys/socket.h>
 ssize_t sendto(int sockfd, void const* buf, size t count, int flags,
         struct sockaddr const* dest_addr, socklen_t addrlen);
     功能:发送数据到哪里
     参数:前四个参数和函数send相同                  //发送数据的时候，根据刚刚记录的通信地址发出去
         dest_addr:目的主机的地址信息。
         addrlen:目的主机的地址信息的字节数。
     返回值:成功返回实际发送的字节数，失败返回-1
 
 UDP通信模型
     步骤    服务器       服务器           客户机         客户机         步骤
     1    创建套接字      socket         socket         创建套接字      1
     2    准备地址结构    sockaddr_in    sockaddr_in    准备地址结构     2
     3    绑定地址       bind            ———           ————           ————
     4    接收请求       recvfrom       sendto          发送请求       3
     5    发送响应       sendto         recvfrom        接收响应       4  d
     6    关闭套接字     close           close          关闭套接字      5

     ➢UDP服务器的阻塞焦点不在accept函数上，而在recvfrom函数上。任何一一个UDP客户机通过sendto函数发送的请求数据都可以被recvfrom函数
     返回给UDP服务器，其输出的客户机地址结构src_addr可直接被用于向客户机返回响应时调用sendto函数的输入
 */
#if 0

//upd客户端
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

int main(void){
    //创建套接字  socket
    //组织服务器的地址结构 struct sockaddr_in ser
    //业务处理
    for(;;){
        //通过键盘获取小写的串
        //输入!退出
        //发送给服务器 sendto
        //接受服务器回传的数据 recv / recvfrom
        //显示输出    
    }
    //关闭套接字
    return 0;
}
#endif

