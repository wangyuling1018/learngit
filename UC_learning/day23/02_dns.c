/*
 域名解析 //DNS：域名解析的服务器
     ●IP地址是网络上标识站点的数字地址，为了方便记忆，采用域名来代替IP地址标识站点地址
     ●域名解析就是域名到IP地址的转换过程。域名的解析工作由DNS服务器完成
     ●当应用过程需要将一个主机域名映射为IP地址时，就调用域名解析函数，解析函数将待转换的域名放在DNS请求中，
      以UDP报文方式发给本地域名服务器。本地的域名服务器查到域名后，将对应的IP地址放在应答报文中返回
      //域名：www.baidu.com，通过域名可以找到服务器IP地址

     #incluce <netdb.h>
     struct hostent* gethostbyname(char const* host_name);
         功能:通过参数所传的主机域名，获取主机信息
         参数:host_name:主机域名
         返回值:函数执行成功返回表示主机信息的结构体指针，失败返回NULL
         注意，该函数需要在联网情况下使用
     

     struct hostent {
         char *h_name;       //主机官方名     //每台服务器有且只有一个官方名称
         char **h_aliases;   //主机别名表     //别名可能有多个 ，二级指针：指针数组，数组中每个元素存的是char* = “XXXX\n”,最后一个元素为NULL
         int h_addrtype;     //地址类型      //AF_INET -基于IPv4的网络通信 或 AF_INET6 -基于IPv6的网络通信
         int h_length;       //地址长度
         char **h_addr_list; //IP地址表     //iP地址可能有多个，二级指针：指针数组，数组中每个元素存的是struct in_addr*,最后一个元素为NULL，用时候将char**强制转换成struct in_addr**
     };
          
     ●对于WEB服务器而言，主机官方名有一一个，而主机别名可能有多个，这些别名都是为了便于用户记忆。同时IP地址也可能有多个。
         ➢h_aliases -> *  ->  "xxx\n"
                       *  ->   "xxx\n"
                      NULL;
                    
         ➢h_addr_list -> * -> in_addr
                         * -> in_addr
                         NULL
         笔记：
         struct in_addr{
             in_addr_t s_addr;
         };
 */
//#if 0

//域名解析
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netdb.h>// gethostbyname

int main(int argc,char* argv[]){
    // ./a.out www.baidu.com
    if(argc < 2){
        fprintf(stderr,"用法:./a.out <域名>\n");
        return -1;
    }

    struct hostent* host = gethostbyname(argv[1]);
    if(host == NULL){
        perror("gethostbyname");
        return -1;
    }
    printf("主机官方名\n");
    printf("%s\n",host->h_name);
    printf("主机别名表\n");
    for(char** pp = host->h_aliases;*pp;pp++){
        printf("%s\n",*pp); //*p -> 是字符串的首地址
    }
    printf("IP地址表\n");
    for(struct in_addr** pp = (struct in_addr**)host->h_addr_list;*pp;pp++){
        printf("%s\n",inet_ntoa(**pp)); //**pp -> in_addr结构
    }
    return 0;
}
//#endif

/*
 (base) 176x212x32x15:day23 wyl$ gcc 02_dns.c -o dns
 (base) 176x212x32x15:day23 wyl$ ./dns www.baidu.com
 主机官方名
 www.a.shifen.com
 主机别名表
 www.baidu.com
 IP地址表
 14.119.104.189
 14.119.104.254
 */
