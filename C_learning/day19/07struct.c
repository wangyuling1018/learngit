//
//  07struct.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//结构体作为函数的参数和返回值
#include <stdio.h>
#include <string.h>
struct A{};
//声明描述学生出生日期的结构体类型s
typedef struct birthday {
    int year;
    int month;
    int day;
}bir_t;

//声明描述学生信息的结构体类型
typedef struct student{
    char name[32];
    int age;
    bir_t* pbirth;//嵌套bir_t结构体指针变量, 将来指向存储学生出生日期的地址
}stu_t;

int main(void){
    printf("%lu\n", sizeof(struct A));
    stu_t s1 = {"张飞", 18, NULL};
    stu_t* ps1 = &s1;

    bir_t birth = {2004, 7, 31};
    //给张飞关联对应的出生日期, 此时pbirth就会指向一个有效内存
    s1.pbirth = &birth;

    printf("%s:%d %d-%d-%d\n", s1.name, s1.age,
                s1.pbirth->year, s1.pbirth->month, s1.pbirth->day);
    printf("%s:%d %d-%d-%d\n", ps1->name, ps1->age,
                ps1->pbirth->year, ps1->pbirth->month, ps1->pbirth->day);
    //修改
    s1.age++;
    ps1->pbirth->year = 2003;

    printf("%s:%d %d-%d-%d\n", s1.name, s1.age,
                s1.pbirth->year, s1.pbirth->month, s1.pbirth->day);
    printf("%s:%d %d-%d-%d\n", ps1->name, ps1->age,
                ps1->pbirth->year, ps1->pbirth->month, ps1->pbirth->day);
    return 0;
}

#endif



