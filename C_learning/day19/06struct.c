//
//  06struct.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//

#if 0
//结构体作为函数的参数和返回值
#include <stdio.h>
#include <string.h>

//声明描述学生出生日期的结构体类型
typedef struct birthday {
    int year;
    int month;
    int day;
}bir_t;

//声明描述学生信息的结构体类型
typedef struct student{
    char name[32];
    int age;
    bir_t birth;//嵌套结构体成员变量
}stu_t;

int main(void){
    //定义结构体类型变量s1嵌套结构体成员
    stu_t s1 = {"xiaobai", 5, {2017, 7, 31} };
    stu_t* ps1 = &s1;//ps1指向s1
    //使用结构体指针变量的方式, 输出
    printf("%s:%d %d-%d-%d\n", ps1->name, ps1->age,
                ps1->birth.year, ps1->birth.month, ps1->birth.day);
    //打印输出
    printf("%s:%d  %d-%d-%d\n", s1.name, s1.age,
                s1.birth.year, s1.birth.month, s1.birth.day);
    //修改
    s1.age++;
    ps1->birth.year = 2016;
    //打印输出
    printf("%s:%d  %d-%d-%d\n", s1.name, s1.age,
                s1.birth.year, s1.birth.month, s1.birth.day);
    //使用结构体指针变量的方式, 输出
    printf("%s:%d %d-%d-%d\n", ps1->name, ps1->age,
                ps1->birth.year, ps1->birth.month, ps1->birth.day);
    return 0;
}
#endif




