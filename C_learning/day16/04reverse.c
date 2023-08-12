//
//  04reverse.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/10.
//
#if 0
#include <stdio.h>
#include <string.h>//声明
//pstr = "abcd efgh"
//        0123 4567
//        i       8-i-1
//         i     8-i-1
//          i   8-i-1
//           i 8-i-1
void reverse(char* pstr){
    int len = strlen(pstr);//获取字符串有效字符个数
    for(int i = 0; i < len/2; i++){
        char c = pstr[i];//c = i
        pstr[i] = pstr[len-i-1];//i = len-i-1
        pstr[len-i-1] = c;//len-i-1 = c = i
    }
}

int main(void){
    char str[1024] = {0};

    for(;;){
        gets(str);
        reverse(str);
        puts(str);
    }
    return 0;
}
#endif

