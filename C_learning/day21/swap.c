//
//  swap.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//
//二级指针使用场景：常用二级指针类型的函数形参，接受一级指针地址形式的实参，
//               以修改调用者指针的目标，或为其分配资源。
/* 无法实现交换
 //s1 = pa, s2 = pb;
 void swap(char* s1, char* s2){
     char* tmp = NULL;
     tmp = s1;
     s1 = s2;
     s2 = tmp;
 }
 //只交换了s1和s2，并没有交换pa和pb
 */

#if 0
//字符串交换
//修改一级指针的指向
#include <stdio.h>

//二级指针作为形参
//ps1 = &pa; ps2 = &pb;
void swap(char** ps1, char** ps2){
    char* tmp = *ps1;//tmp = *(&pa) = pa;//tmp存储了hello字符串首地址
    *ps1 = *ps2;//*ps2=*(&pb)=pb, pa = pb;//pa指向了world字符串
    *ps2 = tmp;//pb = pa;//pb指向了hello字符串
}

int main(void){
    char* pa = "hello";
    char* pb = "world";

    swap(&pa, &pb);
    printf("pa = %s\n", pa);
    printf("pb = %s\n", pb);

    return 0;
}
#endif

