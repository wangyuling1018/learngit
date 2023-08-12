//
//  03_selfconst.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
/*
 非虚的世界：
 1.对象的自洽性
   对同样的函数调用，各个类的对象都会做出恰当的响应。---哪个类的对象，优先调哪个类的成员函数
 2.通过 基类类型指针 调用普通成员函数 只能调用基类的成员函数
   即便这个基类类型的指针指向了子类对象，调用的也为基类的成员函数
   一旦调用子类所持有的成员函数，将引发编译错误
   编译器仅根据指针的类型确定调用哪个类的普通成员函数
 
 */

//没有虚函数的程序
#include <iostream>
using namespace std;
class Shape{
public:
    void Draw() { cout << "Shape::Draw" << endl;}
    int m_x;
    int m_y;
};

class Rect : public Shape{
public:
    void Draw() { cout << "Rect::Draw" << endl;}
    int m_rx;
    int m_ry;
};

class Circle : public Shape{
public:
    void Draw() { cout << "Circle::Draw" << endl;}
    void foo(){}
    int m_radius;
};

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    cout << "----------利用 对象 调用 非虚的成员函数----------" << endl;
    // 哪个类对象 就调用 哪个类的 普通成员函数(对象自恰性)
    Shape s;
    s.Draw( ); // Shape::Draw
    Rect r;
    r.Draw( ); // Rect::Draw
    Circle c;
    c.Draw( ); // Circle::Draw
    
    cout << "----------利用 指针 调用 非虚的成员函数----------" << endl;
    // 利用 基类类型指针 只能调用 基类的普通成员函数
    Shape* ps = &s;
    ps->Draw( ); // Shape::Draw
    // 即便 基类类型指针 指向的是 子类对象，调用的也为基类的普通成员函数
    ps = &r;
    ps->Draw( ); // Shape::Draw
    ps = &c;
    ps->Draw( ); // Shape::Draw
    // 如果调用 子类所特有的成员函数，将引发编译错误
//  ps->foo( ); // error,ps的指针类型是Shape类型的，只到Shape中找foo函数，即便ps指向Circle类

    // 编译器 简单而且粗暴的根据 指针的类型 来确定 到底调用哪个类的普通成员函数
    
    return 0;
}

#endif

