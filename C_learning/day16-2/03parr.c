//
//  03parr.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0

#include <stdio.h>
#include <string.h>

int main(void){
    char* pstr[3] = {"beijing", "tianjin", "shanghai"};
    //等价于
    //char* pstr[0] = "beijing";
    //char* pstr[1] = "tianjin";
    //char* pstr[2] = "shanghai";
    //打印字符串
    for(int i = 0; i < 3; i++)
        printf("%s ", pstr[i]);
    printf("\n");

    pstr[0] = "shenzhen";//将字符串shenzhen的首地址赋值给pstr[0]
    //strcpy(pstr[0], "hainan");//不能修改, 指向的字符串字面值内存不能修改

    //打印字符串
    for(int i = 0; i < 3; i++)
        printf("%s ", pstr[i]);
    printf("\n");

    return 0;
}
#endif

