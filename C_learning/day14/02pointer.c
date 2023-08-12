//
//  02pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//

#if 0

#include <stdio.h>

int main(void){
    /*
    int *p = NULL;//定义初始化指针变量p保存空指针(0地址)
    printf("%#x\n", *p);//程序崩溃
    *p = 521;//崩溃
    */

    int *p1;//之定义指针变量p1, 随机的地址 - 野指针
            //老版本gcc编译器 - 随机地址
            //新版本gcc编译器 - 给NULL
    printf("%p\n", p1);//nil - NULL
    printf("%#x\n", *p1);//崩溃
    *p1 = 522;//崩溃
    return 0;
}

#endif

