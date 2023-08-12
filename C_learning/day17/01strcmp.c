//
//  01strcmp.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
#include <stdio.h>

//              123456...
//char* str1 = "hello\0";
//char* str2 = "hello\0";
int my_strcmp(const char* str1, const char* str2){
    unsigned char s1, s2;
    while(1){
        s1 = *str1++;//取出来一个字符, *str1, str1++ -> 指向了下一个字符的地址
        s2 = *str2++;//取出来一个字符
        if(s1 != s2)
            return s1 < s2 ? -1 : 1;
        if(!s1)//字符串的结束, !0 - true - 执行
            break;//跳出循环
    }
    return 0;
}

int main(void){
    int ret = 0;
    ret = my_strcmp("abc", "abc");
    printf("abc:abc=%d\n", ret);
    ret = my_strcmp("abc", "abcdef");
    printf("abc:abcdef=%d\n", ret);
    return 0;
}
#endif

