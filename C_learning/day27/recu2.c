//
//  recu2.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/15.
//

#if 0

//利用递归打印:1 2 3
#include <stdio.h>

//main
//  print(max=3)
//      print(max=2)
//          print(max=1)
//              printf:打印１
//              return;
//          printf:打印２
//          return;
//      printf:打印3
//      return
//  printf:\n
//  return 0;
//
void print(int max){
    //3.最后在递归函数设置退出条件
    if(max == 1){
        printf("1 ");
        return;//递归函数的返回
    }
    //2.打印3, 打印2, 打印1 - 一样的, 重复的, 调用自己重复打印即可
    //1 2 3 -　将调用自身的代码放在前面
    print(max-1);
    //1.首先想要这个函数就是打印一个数字, 只是将这个打印一个数字的动作重复下去
    //先打印一个数字的代码
    printf("%d ", max);//这个代码就是重复的代码
    return;
}

int main(void){
    int max = 3;
    print(max);//打印输出1  2  3
    printf("\n");
    return 0;
}

#endif

