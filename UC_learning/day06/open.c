#if 0
//文件的打开和关闭
#include<stdio.h>
#include<fcntl.h> // open
#include<unistd.h> // close

int main(void){
    //打开文件
    int fd = open("/Users/wyl/C++_Projects/UC_learning/day06/open.txt",O_RDWR | O_CREAT | O_TRUNC,0777);
    if(fd == -1){
        perror("open");
        return -1;
    }
    /*
     生成的open.txt的权限为-rwxrwxr-x :0775
     拥有者用户：rwx、同组用户：rwx是我的朋友，都可以写，没问题，但是其它用户可以写就有问题了，不安全
     0002是默认权限掩码，可以使用umask 0005命令修改掩码
     0777 - 0002 = 0775,对陌生其他用户对写权限掩掉，最终生成的open.txt的权限为0775
     如果不小心为陌生其他用户给了写权限，不用担心，系统会去掉写权限的。
     */
    printf("fd = %d\n",fd);

    if(close(fd) == -1){
        perror("close");
        return -1;
    }

    return 0;
}
#endif

