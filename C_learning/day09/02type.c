//
//  02type.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/8.
//
#if 0
#include <stdio.h>

int main(void){
    //隐式转换
    //小转大,整转浮,有转无
    //计算过程中有0.9,默认为double类型, 1为int类型
    //计算中既有double，又有int类型，将int类型的1转换为double类型,导致三目运算结果为double类型 - 8
    printf("sizeof(1?1:0.9) = %lu\n", sizeof(1?1:0.9)); //小转大
    //都是int类型, 无需转换
    printf("(-7+3)>0 结果是%d\n", (-7+3)>0);

    //3后面带有u, gcc给他的数据类型为unsigned int, -7, 0是int,
    //将gcc偷偷的将有符号类型的int转换为无符号类型的数据, 在做运算
    //-7的无符号类型
    //-7:
    //肯定成立
    printf("(-7+3u)>0 结果是%d\n", (-7+3u)>0);
    printf("-7的无符号类型是:%u\n", -7);

    //显式转换
    int c = 520;
    long d = (long)c;
    printf("c = %d, d = %ld\n", c,d);

    int e = 300;//00000000 00000000 00000001 00101100
    char f = (char)e;//00101100
    printf("e = %d, f = %hhd\n", e, f);
    return 0;
}
#endif








