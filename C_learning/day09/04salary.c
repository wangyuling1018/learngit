//
//  04salary.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0

//工资出行
#include <stdio.h>

int main(void){
    printf("请输入月薪:");
    double salary;
    scanf("%lf", &salary);

    if(salary < 1000){
        printf("别出去了, 法院仲裁.\n");
        return -1;//结束程序
    }

    if(salary >= 20000)
        printf("飞机.\n");
    else if(salary >= 10000)
        printf("高铁.\n");
    else if(salary >= 5000)
        printf("高客.\n");
    else if(salary >= 3000)
        printf("自行车.\n");
    else
        printf("步行.\n");
    return 0;
}
#endif

