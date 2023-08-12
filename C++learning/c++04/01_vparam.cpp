//
//  01_vparam.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//
#if 0
//引用的应用
//引用型参数，函数的形参是实参的别名，避免对象复制的开销
//C++语言 因为有了引用这个语法特性，所以C++程序可以不做值传递
//经验之谈：在设计一个函数的时，只要能够保证函数内部不需要修改实参，那就大胆的在形参中加上const

/*
 1.在C语言中，只要涉及到数据传递（例如：初始化、赋值、传参、返回值）都是值传递（将数据复制一份给别人）
    void foo(int x){....}
    int bar(){
        int m = 800;
        return m;
    }
    int main(void){
        int a = 10;//初始化，将无名内存中的值10 复制一份 保存到a中
        a = 20;//赋值，将无名内存中的数据20 复制一份 保存到a中
        foo(a);//传参，将a中的数据复制一份给x
        |将m中的数据800复制一份保存到这块无名内存中|bar();//bar函数在main函数中开一块无名内存，用来存放bar函数的返回值
        
    }
 */
#include <iostream>
using namespace std;
/*
//C语言代码
void Swap(int x,int y){
    int z = x;
    x = y;
    y = z;
}
*/

//C语言中使用指针
void Swap(int* x,int* y){
    int z = *x;
    *x = *y;
    *y = z;
}

//C++中使用引用，提出引用就是引用指针太麻烦，尽量C++代码少用指针
//x、y是a、b的别名，操作x、y就是操作a、b
void Swap(int& x,int& y){//非常引用型参数：可以在函数内部修改实参
    int z = x;
    x = y;
    y = z;
}
//void Print(int& x,int& y){//打印机函数 //非常引用型参数：可以在函数内部修改实参
void Print(const int& x,const int& y){//常引用型参数：可以防止函数内部意外修改实参
    //x = 8888;//形参不加const，可以修改实参。//形参加了const，就会报错
    cout << "打印机函数：" << x << " " << y << endl;
}
//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    int a = 10; int b = 20;
    //Swap(a,b);
    //Swap(&a, &b);
    Swap(a,b);
    cout << "a=" << a << " ,b=" << b <<endl;
    
    Print(a,b);
    
    return 0;
}

#endif

