//
//  05any_pointer.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0

#include <stdio.h>

int main(void){
    int a = 0x12345678;
    //1.通过有类型指针访问其中任意1字节内存数据
    char* p1 = (char *)&a;//将int类型的指针&a转为char类型的指针给p1,p1保存a的首地址
    printf("%#x\n", *p1);//0x78
    p1++;
    printf("%#x\n", *p1);//0x56
    p1++;
    printf("%#x\n", *p1);//0x34
    p1++;
    printf("%#x\n", *p1);//0x12
    //2.通过有类型指针访问其中任意2字节内存数据
    short* p2 = (short *)&a;//将int类型的指针&a转换为short类型的指针给p2, p2保存a的首地址
    printf("%#x\n", *p2);//0x5678
    p2++;
    printf("%#x\n", *p2);//0x1234
    //3.一次性访问4字节
    int* p3 = &a;//int*
    printf("%#x\n", *p3);//0x12345678

    //访问中间2字节
    printf("%#x\n", *(short *)((char *)&a + 1));
    return 0;
}
#endif

