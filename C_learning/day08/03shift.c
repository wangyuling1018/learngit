//
//  03shift.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//

/*
 如果后续的char类型数据 - 十六进制方式显示
     正数 - %#x %#hhx
     负数 - %#hhx
 
 GPIOCOUT &= ~(1<<n);//GPIOCOUT[n]=0
 
 */

#if 0
#include <stdio.h>

int main(void){
    char a = 0x5a; //01011010
    char b = a << 2;//a<<2, b = 0110 1000 = 0x68, 高位溢出
    short c = a << 2;//a左移2位, c = 01 0110 1000, 高位没有溢出
    printf("a = %#x, b = %#x, c = %#x\n", a, b, c);
    printf("a = %#hhx, b = %#hhx, c = %#hhx\n", a, b, c);
    //      76543210
    //a     01011010
    //a>>2  00010110 10
    b = a >> 2;//01011010 >> 2
    printf("a = %#x, b = %#x\n", a, b);
    //      76543210
    //a     10100101
    //a>>2  11101001 01
    a = 0xa5;//10100101 -> 0xa5
    b = a >> 2;//11101001 -> 0xe9
    printf("a = %#x, b = %#x\n", a, b);
    printf("a = %#hhx, b = %#hhx\n", a, b);
    return 0;
}
#endif

