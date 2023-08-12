//
//  06_deduction.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//

//<>中的是 类型形参，函数名后面的是 调用形参
//相关：类型 或 个数等 是否一致

/*
 隐式推断类型实参
 如果函数模板的 调用形参 和 类型形参 相关。
    例如：template<class T>T Max(T x,T y){....}
 那么在实例化函数模板时，即使不显式指明函数模板的类型实参，编译器也有能力根据 调用实参的类型 隐式推断出正确的 类型实参的类型
 获得和普通调用函数一致的语法表现形式
 
 三种情况不能做隐式推断
 1.调用参数 和 类型参数 不完全相关
    例如： template<class T,class D>T Max(T x,T y){...}
 2.隐式推断不支持 隐式类型转换
    例如：template<class T>T Max(T x,T y){...}
    使用时：Max(123,45.6);
 3.返回值类型不支持隐式推断
 */

#if 0
#include <iostream>
using namespace std;
//函数模板
template<class T>
T Max(T x,T y){
    return x > y ? x : y;
}

template<typename T,typename D>void Func(D x){//调用参数 和 类型参数 不完全相关
    
}

template<typename R,typename T>R Hum(T x){//返回值类型不支持隐式推断
    R r;
    //....
    return r;
}
int main(){

    int nx = 10, ny = 20;
    cout << Max(nx,ny) << endl;
    //      Max<>(nx,ny) ==> Max<int>(nx,ny)
    double dx = 1.23, dy = 4.56;
    cout << Max(dx,dy) << endl;
    //      Max<double>(dx,dy)
    string sx = "world", sy = "hello";
    cout << Max(sx,sy) << endl;
    //      Max<string>(sx,sy)
    
    //Func(nx);              //error,无法推断模板参数“T” //调用参数 和 类型参数 不完全相关
    Func<double>(nx);        //ok ===> Func<double,int>(nx)
    //Max(nx,dy);              //error 参数类型推断冲突（int or double） //隐式推断不支持 隐式类型转换
    Max(nx,(int)dy);           //ok, Max<int>(nx,(int)dy)
    //Hum(nx);                  //error,不能推断模板参数“R” //返回值类型不支持隐式推断
    Hum<double>(nx);           //ok ,Hum<double,int>(nx)
    return 0;
}
#endif
