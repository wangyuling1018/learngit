//
//  03pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0
//定义指针变量, 如果一开始不知道该指针变量指向谁, 赋值为NULL
//后续通过指针变量来访问内存之前, 先对指针变量进行安全检查, 将其和NULL作比较
//判断是否安全
#include <stdio.h>

int main(void){
    //1.指向有效内存的演示
    int *pa = NULL;//安全, 否则pa就是野指针,随机地址
    int a = 520;
    pa = &a;//pa指向a, pa保存一个合法的地址
    //通过pa访问之前进行安全判断检查
    if(pa == NULL){
        printf("pa没有指向有效内存.\n");
        return -1;
    }
    printf("pa指向有效内存地址:%p\n", pa);
    *pa = 521;//踏踏实实通过pa访问
    printf("%d\n", *pa);

    //2.无指向的演示
    int *pb = NULL;//安全, 否则pb就是野指针,随机地址
    //后续代码忘记了对pb赋值了, 忘记让pb指向有效内存
    //int b = 100;
    //pb = &b;
    //通过pb访问之前进行安全判断检查
    if(pb == NULL){
        printf("pb没有指向有效内存.\n");
        return -1;//main中使用return程序就结束了
    }
    printf("pb指向有效内存地址:%p\n", pb);
    *pb = 521;//踏踏实实通过pb访问
    printf("%d\n", *pb);
    return 0;
}
#endif








