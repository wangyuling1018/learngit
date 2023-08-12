#if 0
//该代码扮演客户端，与百度服务器建立TCP连接
//http协议
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

int main(int argc,char* argv[]){
    // ./a.out IP地址  域名  [资源路径]
    if(argc < 3){
        fprintf(stderr,"用法:./a.out <IP地址> <域名> [<资源路径>]\n");
        return -1;
    }
    
    char* IP = argv[1];
    char* name = argv[2];
    char* path = argc < 4 ? "" : argv[3];

    //客户端角色,连接百度服务器
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    // 百度服务器的地址结构
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(80);
    ser.sin_addr.s_addr = inet_addr(IP);

    //向百度服务器发起连接请求
    if(connect(sockfd,(struct sockaddr*)&ser,sizeof(ser)) == -1){
        perror("connect");
        return -1;
    }
    //在建立TCP连接的基础上,给百度的服务器发送请求
    //组织http请求
    char request[1024];
    sprintf(request,"GET /%s HTTP/1.1\r\n"
                    "Host: %s\r\n"
                    "Accept: */*\r\n"
                    "Connection: Close\r\n"
                    "User-Agent: Mozilla/5.0\r\n"
                    "Referer:n %s\r\n\r\n",path,name,name);
    //发送给百度服务器
    if(send(sockfd,request,strlen(request),0) == -1){
        perror("send");
        return -1;
    }
    //接受百度的响应
    for(;;){
        char respond[1024] = {};
        ssize_t size = recv(sockfd,respond,sizeof(respond)-1,0);
        if(size == -1){
            perror("recv");
            return -1;
        }
        if(size == 0){
            break;
        }

        printf("%s",respond);
    }
    printf("\n");
    //关闭套接字
    close(sockfd);
    return 0;
}

#endif

/*
 (base) 176x212x32x15:day23 wyl$ ./http 14.119.104.189 www.baidu.com
 HTTP/1.1 200 OK
 Accept-Ranges: bytes
 Cache-Control: max-age=1
 Content-Length: 7382
 Content-Type: text/html
 Date: Fri, 02 Jun 2023 07:43:41 GMT
 Etag: "1cd6-5480030886bc0"
 Expires: Fri, 02 Jun 2023 07:43:42 GMT
 Last-Modified: Wed, 08 Feb 2017 07:55:35 GMT
 P3p: CP=" OTI DSP COR IVA OUR IND COM "
 P3p: CP=" OTI DSP COR IVA OUR IND COM "
 Server: Apache
 Set-Cookie: BAIDUID=CF2E1711152E3CFDD894833C1116ADE6:FG=1; expires=Sat, 01-Jun-24 07:43:41 GMT; max-age=31536000; path=/; domain=.baidu.com; version=1
 Set-Cookie: BAIDUID=CF2E1711152E3CFDA8AF905E51ECE11C:FG=1; expires=Sat, 01-Jun-24 07:43:41 GMT; max-age=31536000; path=/; domain=.baidu.com; version=1
 Vary: Accept-Encoding,User-Agent
 Connection: close

 <!doctype html><html><head><meta http-equiv="Content-Type" content="text/html;charset=gb2312"><title>?ٶ?һ?£????֪??      </title><style>html{overflow-y:auto}body{font:12px arial;text-align:center;background:#fff}body,p,form,ul{margin:0;padding:0}body,form,#fm{position:relative}td{text-align:left}img{border:0}a{color:#00c}a:active{color:#f60}#u{padding:7px 10px 3px 0;text-align:right}#m{width:680px;margin:0 auto}#nv{font-size:16px;margin:0 0 4px;text-align:left;text-indent:117px}#nv a,#nv b,.btn,#lk{font-size:14px}#fm{padding-left:90px;text-align:left}#kw{width:404px;height:22px;padding:4px 7px;padding:6px 7px 2px\9;font:16px arial;background:url(http://www.baidu.com/img/i-1.0.0.png) no-repeat -304px 0;_background-attachment:fixed;border:1px solid #cdcdcd;border-color:#9a9a9a #cdcdcd #cdcdcd #9a9a9a;vertical-align:top}.btn{width:95px;height:32px;padding:0;padding-top:2px\9;border:0;background:#ddd url(http://www.baidu.com/img/i-1.0.0.png) no-repeat;cursor:pointer}.btn_h{background-position:-100px 0}#kw,.btn_wr{margin:0 5px 0 0}.btn_wr{width:97px;height:34px;display:inline-block;background:url(http://www.baidu.com/img/i-1.0.0.png) no-repeat -202px 0;_top:1px;*position:relative}#lk{margin:33px 0}#lk span{font:14px "????"}#lm{height:60px}#lh{margin:16px 0 5px;word-spacing:3px}#mCon{height:18px;line-height:18px;position:absolute;right:7px;top:8px;top:10px\9;cursor:pointer;padding:0 18px 0 0;background:url(http://www.baidu.com/img/bg-1.0.0.gif) no-repeat right -134px;background-position:right -136px\9}#mCon span{color:#00c;cursor:default;display:block}#mCon .hw{text-decoration:underline;cursor:pointer}#mMenu{width:56px;border:1px solid #9a99ff;list-style:none;position:absolute;right:7px;top:28px;display:none;background:#fff}#mMenu a{width:100%;height:100%;display:block;line-height:22px;text-indent:6px;text-decoration:none}#mMenu a:hover{background:#d9e1f6}#mMenu .ln{height:1px;background:#ccf;overflow:hidden;margin:2px;font-size:1px;line-height:1px}#cp,#cp a{color:#77c}#sh{display:none;behavior:url(#default#homepage)}</style></head>
 <body><p id="u"><a href="/gaoji/preferences.html">????????</a>&nbsp;|&nbsp;<a href="http://passport.baidu.com/?login&tpl=mn">??¼</a></p><div id="m"><p id="lg"><img src="http://www.baidu.com/img/baidu_sylogo1.gif" width="270" height="129" usemap="#mp"></p><p id="nv"><a href="http://news.baidu.com">??&nbsp;??</a>??<b>??&nbsp;ҳ</b>??<a href="http://tieba.baidu.com">??&nbsp;??</a>??<a href="http://zhidao.baidu.com">֪&nbsp;??</a>??<a href="http://mp3.baidu.com">MP3</a>??<a href="http://image.baidu.com">ͼ&nbsp;Ƭ</a>??<a href="http://video.baidu.com">??&nbsp;Ƶ</a>??<a href="http://map.baidu.com">??&nbsp;ͼ</a></p><div id="fm"><form name="f" action="/s"><input type="text" name="wd" id="kw" maxlength="100"><input type="hidden" name="rsv_bp" value="0"><span class="btn_wr"><input type="submit" value="?ٶ?һ??" id="su" class="btn" onmousedown="this.className='btn btn_h'" onmouseout="this.className='btn'"></span></form><div id="mCon"><span>???뷨</span></div><ul id="mMenu"><li><a href="#" name="ime_hw">??д</a></li><li><a href="#" name="ime_py">ƴ??</a></li><li class="ln"></li><li><a href="#" name="ime_cl">?ر?</a></li></ul></div>
 <p id="lk"><a href="http://hi.baidu.com">?ռ?</a>??<a href="http://baike.baidu.com">?ٿ?</a>??<a href="http://www.hao123.com">hao123</a><span> | <a href="/more/">????&gt;&gt;</a></span></p><p id="lm"></p><p><a id="sh" onClick="this.setHomePage('http://www.baidu.com/')" href="http://utility.baidu.com/traf/click.php?id=215&url=http://www.baidu.com" onmousedown="return ns_c({'fm':'behs','tab':'homepage','pos':0})">?Ѱٶ???Ϊ??ҳ</a></p><p id="lh"><a href="http://e.baidu.com/?refer=888">????ٶ??ƹ?</a> | <a href="http://top.baidu.com">???????ư?</a> | <a href="http://home.baidu.com">???ڰٶ?</a> | <a href="http://ir.baidu.com">About Baidu</a></p><p id="cp">&copy;2015 Baidu <a href="/duty/">ʹ?ðٶ?ǰ?ض?</a> <a href="http://www.miibeian.gov.cn" target="_blank">??ICP֤030173??</a> <img src="http://gimg.baidu.com/img/gs.gif"></p></div><map name="mp"><area shape="rect" coords="40,25,230,95"  href="http://hi.baidu.com/baidu/" target="_blank" title="??˽??? ?ٶȵĿռ?" ></map></body>
 <script>var

 */
