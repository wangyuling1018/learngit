//
//  03enum.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
#if 0

//枚举演示-提高代码可读性
#include <stdio.h>
//OK=0, FAILED=1
enum RETURN {OK, FAILED};
typedef enum RETURN return_t;

//int check(int a){
return_t check(int a){
    if(a != 0){
        //printf("表示成功了.\n");
        //return 0;
        return OK; //没有printf提示，也知道返回成功了
    }else{
        //printf("表示失败了.\n");
        //return 1;
        return FAILED;//没有printf提示，也知道返回失败了
    }
}

int main(void){
    printf("%d\n", check(0));
    printf("%d\n", check(1));
    return 0;
}
#endif

