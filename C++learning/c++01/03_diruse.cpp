//
//  03_diruse.cpp
//  C++11
//
//  Created by 王育玲 on 2023/2/17.
//
//名字空间指令

/* 笔记
编译器（gcc/g++/...）有一个共同的工作原理：当编译器在编译函数的时候，编译器会根据这个函数弄2张表，
 编译器编译完成后，就会销毁这2张表。一张定义表，一张可见表。编译器优先从定义表中找，再从可见表中找。
 
 */
/*
#include <iostream>
namespace ns{
    int g_value = 0;
}

//int g_value = 0;//【3】编译器报错，全局变量，全局可见，在main函数的可见表中
//using namespace ns;//【4】编译器报错，全局变量，全局可见，在main函数中的可见表中
int main(void){
    //int g_value = 0;//【2】加了这行代码后，名字空间指令就会变得不可靠了，g_value的值会更改掉。在main函数的定义表中
    using namespace ns;//【1】名字空间指令，从这行代码开始，ns中的内容在当前作用域中 可见
    //ns::g_value = 8888;//【1】作用域限定符号"::"
    g_value = 8888;//在main函数中的可见表中
    std::cout << "ns::g_value = " << ns::g_value << std::endl;
    return 0;
}
*/
