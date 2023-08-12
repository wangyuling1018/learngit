//
//  05struct.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//结构体作为函数的参数和返回值

/*
 结构体作为函数的参数
     如果修改实参 - 传递指针变量
 */
#include <stdio.h>
#include <string.h>

struct student {
    char name[32];
    int age;
};

//给struct student数据类型起别名为stu_t
typedef struct student stu_t;

void show(stu_t st){//stu_t st = s1;
    printf("%s:%d\n", st.name, st.age);
}
void grow(stu_t st){//stu_t st = s1;
    st.age++;//修改的是st的age成员
}
void show_p(stu_t* pst){//stu_t* pst = &s1;
    printf("%s:%d\n", pst->name, pst->age);
}
void grow_p(stu_t* pst){//pst = &s1;
    pst->age++;
}

stu_t get_stu_info(void){
    stu_t s1 = {"xiaoming", 29};
    return s1;//返回局部结构体变量的值
}

stu_t* get_stu_info_p(void){
    stu_t s1 = {"xiaoliang", 29};
    return &s1;//返回局部结构体变量地址的值, 不可以 //error，不能返回局部变量的地址
}
int main(void){
    stu_t s1 = {"liming", 19};
    show(s1);
    grow(s1);
    show(s1);
    printf("-------\n");
    grow_p(&s1);
    show(s1);
    printf("-------\n");
    stu_t stu = get_stu_info();//使用stu保存函数的返回值
    printf("%s:%d\n", stu.name, stu.age);
    //stu_t* pstu = get_stu_info_p(); //error
    //printf("%s:%d\n", pstu->name, pstu->age);
    return 0;
}

#endif

