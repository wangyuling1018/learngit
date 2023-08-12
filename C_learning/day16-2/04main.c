//
//  04main.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi函数

int main(int argc, char* argv[]){
    //argc:记录命令行参数的个数
    //例如:./hello -> argc=1
    //./hello 100 200 -> argc=3
    //argv:记录命令行终端输入的信息对应的字符串首地址
    //例如:"./hello＂ -> argv[0]存储./hello的首地址
    //./hello 100 200 -> argv[0]="./hello";argv[1]="100";argv[2]="200"
    //当运行程序的时候, 可以通过argv获取参数:
    //./hello 100 200
    //argv[1] = "100"; argv[2] = "200";

    for(int i = 0; i < argc; i++)
        printf("argc = %d, argv[%d] = %s\n", argc, i, argv[i]);
    //./04main 数字1 数字2 -计算两个数字的和
    if(argc != 3){
        printf("用法: %s 数字1 数字2\n", argv[0]);
        printf("例如: %s 100 200\n", argv[0]);
        return -1;
    }
    //将从命令行中得到的字符串转换为数字
    int a, b;
    //a-ascii i-int
    a = atoi(argv[1]);//利用C库函数atoi函数将字符串转换为整形数据"100"->100
    b = atoi(argv[2]);//利用C库函数atoi函数将字符串转换为整形数据"200"->200
    printf("a + b = %d\n", a+b);
    return 0;
}
#endif

