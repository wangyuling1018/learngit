//
//  union经典使用.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//


//经典使用场景1:数据传输时使用
/*
union msg{
    unsigned char buf[48];
    struct cmd{
        unsigned char head[4];
        unsigned char data[40];
        unsigned char tail[4];
    }cmd_info;
};
//A给B发送数据，B使用联合来解析数据
msg.cmd_info.head
msg.cmd_info.data
msg.cmd_info.tail
 
// 联合里面嵌套结构体
 
*/

#if 0
//经典使用场景2
//job为s，就使用int class;
//job为t，就使用char position[10];
#include <stdio.h>
//声明联合体数据类型　不占内存空间
struct person{
    char name[20];
    char sex;
    char job;
    union{
        int class; //班级, 学生才会拥有
        char position[10];//位置　讲师　教授
    }category; //定义了联合体类型变量category
};
//结构体体里面嵌套联合

int main(void){
    struct person persons[2] ={
        {.name="小明", .sex='m', .job='s', .category.class = 2206},
        {.name="老张", .sex='f', .job='t', .category.position="教授"},
    };
    for(int i=0; i<sizeof(persons)/sizeof(persons[0]); i++){
        if(persons[i].job == 's'){
            printf("姓名: %s  性别:%c  班级:%d\n", persons[i].name,
                    persons[i].sex, persons[i].category.class);
        }
        else{
            printf("姓名: %s  性别:%c  职称:%s\n", persons[i].name,
                    persons[i].sex, persons[i].category.position);
        }
    }
    return 0;
}

#endif

