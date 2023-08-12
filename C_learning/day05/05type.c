//
//  05type.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/6.
//

#if 0
#include <stdio.h>

int main(void){
    //int和long的区别
    int a = 520;
    printf("%d\n", a);
    printf("%ld\n", a);//理论上应该是安全的, 可以正常显示
                        //编译添加-Werror选项, 将警告当做错误
                        //
    long b = 520;
    printf("%ld\n", b);
    printf("%d\n", b);//危险, 32位系统安全, 64位系统危险
                        //有可能产生数据丢失, 数据过大的时候容易造成这种情况

    float f = 4.5;
    printf("f = %f, %g\n", f, f);
    double d = 5.6;
    printf("d = %lf, %lg\n", d, d);

    return 0;
}
#endif

