//
//  01struct.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//直接定义结构体数据类型的变量实现内存的分配
//可以使用这样的数据类型区定义变量 - 本质上数据类型和int,char一样
#include <stdio.h>
#include <string.h>

int main(void){
    //直接定义结构体数据类型的变量s1并且初始化
    struct {
        char name[32];
        int age;
    }s1 = {"小明", 19};

    //打印学生的信息
    printf("%s, %d\n", s1.name, s1.age);//变量名访问成员:变量名.成员

    //修改成员的值
    s1.age++;
    strcpy(s1.name, "明明");

    //打印学生的信息
    printf("%s, %d\n", s1.name, s1.age);//变量名访问成员:变量名.成员
    return 0;
}

#endif

