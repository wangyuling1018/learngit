/*
 访问测试
     #include <unistd.h>
     int access(char const* pathname, int mode);
         功能:判断当前进程是否可以对某个给定的文件执行某种访问。
         参数:pathname文件路径
             mode 被测试权限，可以以下取值
                 R_OK -可读否
                 W_OK -可写否
                 X_OK -可执行否
                 F_OK -存在否
         返回值:成功返回0，失败返回-1。
 */

#if 0
//访问测试
#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    // ./a.out hello.c
    if(argc < 2){
        fprintf(stderr,"用法:./a.out <文件名>\n");//perror最近一次函数调用的错误信息，输出错误原因，stderr是打印错误提示信息
        return -1;
    }
    
    // 文件hello.c:不存在
    // 文件hello.c:可读,可写,不可执行.
    printf("文件%s:",argv[1]);
    if(access(argv[1],F_OK) == -1){//不存在
        printf("不存在\n");
    }else{//存在
        //能读否
        if(access(argv[1],R_OK) == -1){
            printf("不可读,");
        }else{
            printf("可读,");
        }
    
        //能写否
        if(access(argv[1],W_OK) == -1){
            printf("不可写,");
        }else{
            printf("可写,");
        }

        //能执行否
        if(access(argv[1],X_OK) == -1){
            printf("不可执行\n");
        }else{
            printf("可执行\n");
        }
    }

    return 0;
}
#endif

/*
 (base) 176x212x32x5:day09 wyl$ gcc 01_access.c -o access
 (base) 176x212x32x5:day09 wyl$ ./access access
 文件access:可读,可写,可执行 
 (base) 176x212x32x5:day09 wyl$ ./access hello
 文件hello:不存在
 */
