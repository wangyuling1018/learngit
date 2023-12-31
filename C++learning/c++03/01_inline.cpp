//
//  01_inline.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//

#if 0
//内联函数是编译器的一个优化策略
//普通函数是有问题的：每个普通函数调用语句都需要发生跳转操作，这种跳转操作会带来时间开销。
//跳转工作是最耗时的

//内联函数的缺点：会使生成的可执行文件变大和进程代码的内存变大，因此只有频繁调用的简单的函数才适合内联
//inline是期望内联，是否真的内联，由编译器决定，如果编译器觉得这个函数不适合内联，编译器也不会按照内联来处理
//递归函数、复杂函数不适合内联
//如果一个复杂的foo函数执行要花费1个小时，跳转仅仅花费2秒，那么2秒可以忽略。
#include <iostream>
using namespace std;
void foo(int x){//普通函数，在代码段
    cout << "foo(int)" << x << endl;
}

inline void bar(int x){//内联函数
    cout << "bar(int)" << x << endl;
}

int main(void){
    foo(10);//程序执行到这个函数的时候，编译器将此处替换为跳转指令，往代码段跳转
    foo(20);//程序执行到这个函数的时候，编译器将此处替换为跳转指令，往代码段跳转
    foo(30);//程序执行到这个函数的时候，编译器将此处替换为跳转指令，往代码段跳转
    
    bar(10);//程序执行到这个函数的时候，编译器将此处替换为bar函数编译后产生的二进制指令集
    bar(20);//程序执行到这个函数的时候，编译器将此处替换为bar函数编译后产生的二进制指令集
    bar(30);//程序执行到这个函数的时候，编译器将此处替换为bar函数编译后产生的二进制指令集
    return 0;
}
#endif

