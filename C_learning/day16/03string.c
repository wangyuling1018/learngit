//
//  03string.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
#include <stdio.h>
#include <string.h>//声明

int main(void){
    //1.strlen:string length
    char* p1 = "abcdefg";
    printf("%lu, %lu\n", strlen(p1), strlen("abc"));
    char* p2 = "ab\0c";
    printf("%lu\n", strlen(p2));
    //2.strcat:将一个字符串放到另一个字符串的后面
    char str[20] = "abc";
    strcat(str, "xyz");//将字符串xyz拼接到数组str的字符串abc后面
    printf("%s\n", str);
    strncat(str, "1234", 2);//将字符串"1234"的前两个字符拼接到str数组后面
    printf("%s\n", str);
    //3.strcpy: string copy, 将 指定的字符串拷贝到指定的内存中
    char str2[20] = "abcd";
    strcpy(str2, "123456");//将字符串123456拷贝到str2数组中
    printf("%s\n", str2);
    char* p3 = "abcd";
    strcpy(str2, p3);//将p3指向的字符串拷贝到str2数组中
    printf("%s\n", str2);
    strncpy(str2, "123456789", 2);//将字符串123456789的前2个字符拷贝到str2数组中
    printf("%s\n", str2);
    //4.strcmp : 字符串比较
    //从左边到右边一个字符一个字符的比较, 直到不相等或者字符串结束
    //不相等:哪个字符大, 哪个字符串大
    //abc\0
    //dbc\0
    int ret = 0;
    ret = strcmp("abc", "abc");
    printf("abc和abc的比较结果是:%d\n", ret);
    ret = strcmp("abc", "dbc");
    printf("abc和dbc的比较结果是:%d\n", ret);
    //abcd e\0
    //abc\0
    ret = strcmp("abcde", "abc");
    printf("abcde和abc的比较结果是:%d\n", ret);
    //ab cde\0
    //ab c\0
    char* p8 = "abcde";
    char* p9 = "abc";
    ret = strncmp(p8, p9, 2);
    printf("abcde和abc的前2个字符的比较结果是:%d\n", ret);
    
    char strp8[6] = "abcde";
    char strp9[4] = "abc";
    ret = strncmp(strp8, strp9, 2);
    printf("abcde和abc的前2个字符的比较结果是:%d\n", ret);
    return 0;
}
#endif


