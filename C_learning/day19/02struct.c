//
//  02struct.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//玩法2:先声明一个结构体数据类型, 使用该数据类型定义变量
#include <stdio.h>
#include <string.h>

//声明结构体数据类型
struct student {
    char name[32];
    int age;
};//struct student就是一个结构体数据类型, 后续的时候将其类比做int来使用

int main(void){
    //定义结构体类型变量s1存储学生信息
    struct student s1 = {"小明", 18};//类比:int s1; //传统初始化，必须按照定义的顺序初始化
    //定义结构体类型的指针变量ps1指向s1
    //ps1存储s1的首地址, ps1指向s1
    struct student* ps1 = &s1;//ps1存储s1的地址
    //打印学生信息
    printf("%s, %d\n", s1.name, s1.age);
    //通过指针变量变量访问成员语法:指针变量->成员
    printf("%s, %d\n", ps1->name, ps1->age);

    ps1->age++;
    strcpy(ps1->name, "小两");

    //打印学生信息
    printf("%s, %d\n", s1.name, s1.age);
    //通过指针变量变量访问成员语法:指针变量->成员
    printf("%s, %d\n", ps1->name, ps1->age);
    return 0;
}
#endif

