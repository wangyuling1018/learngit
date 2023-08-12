//
//  07_overload.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 函数模板的重载
 1.普通函数和可实例化出该函数的函数模板 构成重载关系
    在数据类型匹配度相同的情况下，编译器优先选择普通函数
    除非函数模板可以产生具有更好的数据类型匹配度的实例
 2.函数模板的实例化不支持隐式类型转换 但普通函数支持
    在传递参数时，如果需要编译器做隐式类型转换，则编译器选择普通函数
 3.可以在实例化时，用<>强行通知编译器选择函数模板
 
 */

#if 0
#include <iostream>
using namespace std;
void Max(int x,int y){
    cout << "1.Max(int,int)" << endl;
}

template<typename T>void Max(T x,T y){
    cout << "2.Max(T,T)" << endl;
}

int main(){
    int nx = 10,ny = 20;
    Max(nx,ny); //匹配度相同，选择普通函数
    Max<>(nx,ny); //使用<>强行通知编译器使用模板
    double dx = 1.23,dy = 4.56;
    Max(dx,dy); //函数模板可以实例化出更高匹配度的函数实体，选择模板
    Max(nx,dy); //函数模板的实例化不支持隐式转转换，选择普通函数
    
}
#endif
