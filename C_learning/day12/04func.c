//
//  04func.c
//  C_learning
//
//  Created by 王育玲 on 2023/5/9.
//
#if 0
#include <stdio.h>

//函数玩法步骤三:函数声明, 不会分配内存的
extern void foo(void);
extern void foo1(void);
extern int bar(void);
extern int bar1(void);
extern int bar2(void);
extern char bar3(void);
extern void add(int, int);//声明:形参变量名字可以省略
extern int sub(int x, int y);

int main(void){
    
    //函数玩法步骤二:使用函数 调用函数
    foo();//调用foo函数 没有形参,没有返回值
    foo1();//调用foo1函数 没有形参,没有返回值
    int ret = 0;//定义ret变量存储函数的返回值
    //没有返回值,有形参的函数调用
    int a = 20, b = 10;
    add(a,b);//调用add函数, a和b是给add函数传递的两个参数a和b(实参)的值20,10
    ret = sub(a,b);//调用有参数有返回值的函数sub,实参a和b的值20,10给sub的x和y
                    //使用ret包含sub函数的返回值
    printf("sub:x-y=%d\n", ret);

    //没有参数,有返回值
    ret = bar();//调用bar函数, 且使用ret变量保存bar函数的返回值
    printf("bar() = %d\n", ret);
    ret = bar1();//调用bar1函数, 且使用ret变量保存bar1函数的返回值
    printf("bar1() = %d\n", ret);
    ret = bar2();//调用bar2函数, 且使用ret变量保存bar2函数的返回值
    printf("bar2() = %d\n", ret);
    ret = bar3();//调用bar3函数, 且使用ret变量保存bar3函数的返回值
    printf("bar3() = %d\n", ret);

    return 0;
}

//函数玩法步骤一:函数定义
//形式1:定义无返回值无参数的函数
void foo(void){//函数名foo符合表示符规则
    printf("void foo(void)\n");
    //return;//省略return
}

void foo1(void){
    printf("void foo1(void)\n");
    return;//函数就从这里结束, 不需要返回一个值, 所以后面什么不加
    printf("我会被执行吗.\n");
}
//形式2:定义无形参有返回值类型
//没有参数, 函数执行完毕返回一个数据,该数据为int类型
int bar(void){
    return 520;//返回常量, 默认int类型
}

int bar1(void){
    int a = 520;
    a++;
    return a;//返回的是变量a的值为521
}

int bar2(void){
    printf("bar3函数.\n");
    //忘记添加return语句了,返回随机的值
}

char bar3(void){
    int a = 555;
    return a;//返回的是int类型的值, 返回值类型是char
            //gcc编译器会强制将int类型->char类型 - 然后再返回
}
//形式3:定义没有返回值有参数的函数
void add(int x, int y){//x,y 形参变量, 用来保存调用函数给这个函数传递的值
                        //此时是将数据a的值20给变量x, 将数据b的值10给变量y
                        //result:x=a=20, y=b=10
    printf("add:x+y=%d\n", x+y);
}

//形式4:定义有返回值有参数的函数
int sub(int x, int y){
    return x - y;
}

#endif

