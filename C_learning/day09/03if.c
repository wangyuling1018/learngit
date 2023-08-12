//
//  03if.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    printf("请输入一个整数:");
    int a;
    scanf("%d", &a);
    //1.if结构演示
    if(a >= 0){
        printf("a是一个非负数.\n");
    }
    printf("a = %d.\n", a);
    printf("---------------\n");
    //2.if...else结构
    if(a >= 0){
        printf("a是一个非负数.\n");
    }else{
        printf("a是一个负数.\n");
    }
    printf("---------------\n");
    //3.if...else if...else if...可以写多个else if
    //如果所有条件都为假,一句都不执行
    if(a > 0){
        printf("a是一个正数.\n");
    }else if(a == 0){
        printf("a是0.\n");
    }else if(a < 0){
        printf("a是一个负数.\n");
    }
    printf("---------------\n");
    //4.if...else if...else
    //分支结构中必定会执行其中一个
    if(a > 0){
        printf("a是一个正数.\n");
    }else if(a == 0){
        printf("a是0\n");
    }else{
        printf("a是一个负数.\n");
    }
    printf("---------------\n");

    return 0;
}

#endif







