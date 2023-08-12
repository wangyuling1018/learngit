//
//  03struct.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//玩法3:先声明一个结构体数据类型, 然后其别名定义结构体变量
#include <stdio.h>
#include <string.h>

//声明结构体数据类型并且起别名
typedef struct student {
    char name[32];
    int age;
}stu_t;//struct student就是一个结构体数据类型,使用typedef给struct student类型区别名为stu_t

int main(void){
    //定义结构体类型变量s1存储学生信息
    stu_t s1 = {.age = 18, .name = "小明"};//类比:int s1; //标记初始化，可以不按照顺序初始化
    //定义结构体类型的指针变量ps1指向s1
    //ps1存储s1的首地址, ps1指向s1
    stu_t* ps1 = &s1;//ps1存储s1的地址 //是s1是变量，不是地址，stu_t* ps1 = s1，error
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

