//
//  01string.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
//将来给一个函数传递字符串, 本质上传递的是字符串的首地址
#include <stdio.h>

int main(void){
    printf("%s\n", "abcd\0");//字符串的占位符:%s
    printf("%s\n", "abcd");//字符串的占位符:%s

    //只会输出1234, 而不会输出abcd
    //一旦看到了\0字符, gcc编译器 - 字符串结束 - 不会去看\0后面的内容
    printf("%s\n", "1234\0abcd");
    printf("abcd""12345\n");//"abcd12345\n"
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
    //数据库
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");

    char* pstr = "abc";
    printf("%s\n", pstr);//打印字符串abc
    //printf("%s\n", pstr+1);//打印字符串bc
    printf("%c %c %c\n", *(pstr+0), *(pstr+1), *(pstr+2));
    printf("%c %c %c\n", pstr[0], pstr[1], pstr[2]);
    printf("%hhd %hhd %hhd\n", pstr[0], pstr[1], pstr[2]);
    //*(pstr + 1) = 'B';//不允许修改
    
    char str[] = {'a', 'b','c', '\0'};
    printf("%s\n", str);//str就是abc字符串的首地址
    printf("%c %c %c\n", str[0], str[1], str[2]);
    str[1] = 'B';
    printf("%s\n", str);//str就是abc字符串的首地址

    char str1[] = "hello";
    printf("%s\n", str1);
    str1[2] = 'L';
    printf("%s\n", str1);
    printf("%lu\n", sizeof(str1));//hello\0 - 6
    //tom - 字符串
    
    //字符指针和字符数组的区别：字符指针所指向的内容不能修改，字符数组的内容可以修改。
    
    return 0;
}

#endif

