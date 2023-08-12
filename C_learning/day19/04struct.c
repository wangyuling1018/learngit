//
//  04struct.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//玩法3:先声明一个结构体数据类型, 然后其别名定义结构体变量
#include <stdio.h>
#include <string.h>

struct student {
    char name[32];
    int age;
};

//给struct student数据类型起别名为stu_t
typedef struct student stu_t;

int main(void){
    //定义数组, 数组名为s, 数组每个元素为stu_t类型
    stu_t s[3] = {
        {.age = 20, .name = "刘备"},
        {.age = 19, .name = "关羽"},
        {.age = 18, .name = "张飞"}
    };
    
    int size = sizeof(s) / sizeof(s[0]);
    for(int i = 0; i < size; i++)
        printf("%s:%d\n", s[i].name, s[i].age);
    for(int i = 0; i < size; i++)
        s[i].age++;
    for(int i = 0; i < size; i++)
        printf("%s:%d\n", s[i].name,s[i].age);
    
    stu_t* ps = s;//ps保存结构体数组的首地址 //ps == s
    //stu_t* ps = &s; //error,s是数组，数组的首地址就是数组名
    for(int i = 0; i < size; i++)
        ps[i].age++;
    for(int i = 0; i < size; i++)
        printf("%s:%d\n", ps[i].name, ps[i].age);
    


    return 0;
}

#endif

