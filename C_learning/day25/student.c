//
//  student.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/12.
//
#if 0
//student.t - 节点之间的逻辑关系
#include <stdio.h>

//声明描述学生信息的结构体
typedef struct student{
    char name[32];
    int age;
    struct student* next;//保存下一个学生信息节点/变量的首地址
}stu_t;

int main(void){
    //定义初始化三个学生的信息
    stu_t s1 = {.name = "孙悟空", .age = 600, .next = NULL};
    stu_t s2 = {.name = "猪八戒", .age = 800, .next = NULL};
    stu_t s3 = {.name = "沙悟净", .age = 750, .next = NULL};
    stu_t head;//头节点
    stu_t tail;//尾节点
    
    head.next = &s1;
    s1.next = &s2;
    s2.next = &s3;
    s3.next = &tail;
    tail.next = NULL;
    
    //通过s1打印s1,s2,s3的name
    printf("%s %s %s\n", s1.name, s1.next->name, s1.next->next->name);

    //通过pmid指针遍历输出三个人的名字
    for(stu_t* pnode = &head; pnode != &tail; pnode = pnode->next){
        stu_t* pmid = pnode->next;
        if(pmid != &tail)
            printf("%s\n", pmid->name);
    }
    return 0;
}
#endif




