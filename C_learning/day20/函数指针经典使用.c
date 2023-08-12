//
//  函数指针经典使用.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/11.
//

#if 0
//函数指针经典使用
#include <stdio.h>

//给int (*)(int, int) 指针起了个别名叫 pfunc_t
typedef int (*pfunc_t)(int, int);

int add(int a, int b){
    printf("enter %s\n", __func__);
    return a+b;
}
int sub(int a, int b){

    printf("enter %s\n", __func__);
    return a-b;
}
int mul(int a, int b){

    printf("enter %s\n", __func__);
    return a*b;
}
int div(int a, int b){

    printf("enter %s\n", __func__);
    return a/b;
}
int mod(int a, int b){

    printf("enter %s\n", __func__);
    return a%b;
}
//定义了函数指针数组，数组中每个元素都是一个函数的地址
pfunc_t arr[]={add, sub, mul, div, mod};
int main(void){

    int len = sizeof(arr)/sizeof(arr[0]);
    pfunc_t pfunc = NULL;
    int ret = 0;

    for(int i=0; i<len; i++){
        pfunc = arr[i];
        ret = pfunc(200, 20);
        printf("ret=%d\n", ret);
    }


    return 0;
}
#endif








