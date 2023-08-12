//
//  04_bdv.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

//虚函数一定是成员函数,全局函数不会是虚函数

/*虚函数和覆盖
 虚函数：在普通成员函数前面加virtual关键字
   形如
     class 类名{
        virtual 返回类型 函数名（行参表）{....}
     };
    的成员函数，称为虚函数或方法
 
 覆盖
    如果子类的成员函数和基类的虚函数 具有相同的函数签名，那么该成员函数就也是虚函数，无论其是否带有virtual关键字，且与基类的虚函数构成覆盖关系
 
 相同原形：返回值类型、函数名、行参表 都一样才叫相同原形
 相同签名 没有 相同原形 要求高，有些地方不一样，也是相同签名
 */

/*
 通过基类类型指针调用虚函数：
 1.如果基类类型指针指向基类对象，调用基类的原始版本虚函数
 2.如果基类类型指针指向子类对象，调用子类的覆盖版本虚函数
 */

//几乎所有面向对象的编程语言都有多态，但是不同的语言实现方式不一样
//C++中的多态，利用虚函数来实现
//用基类型指针来调虚函数，或者用基类型引用来调虚函数，对基类型指针或基类型引用有要求，基类型指针必须指向子类对象，基类型引用必须引用子类对象。----这种现象就叫多态
/*
 多态需要具备的条件：
 1.基类必须要有虚函数，子类必须提供覆盖版本
 2.必须利用 基类类型指针（必须指向子类对象）调用 虚函数
   必须利用 基类类型引用（必须引用子类对象）调用 虚函数
 
 多态的结果：
    最终 调用的为 子类覆盖版本的虚函数，而非基类原始版本的虚函数
 */

#if 0

#include <iostream>
using namespace std;
class Shape{
public:
    virtual void Draw() { cout << "Shape::Draw" << endl;} //虚函数 ---原始版本虚函数
    int m_x;
    int m_y;
};

class Rect : public Shape{
public:
    void Draw() { cout << "Rect::Draw" << endl;} // 虚函数（编译器将补virtual）//与 基类的Draw函数 具有相同原形，与 基类的Draw函数 构成覆盖关系-----覆盖版本虚函数
    int m_rx;
    int m_ry;
};

class Circle : public Shape{
public:
    void Draw() { cout << "Circle::Draw" << endl;}// 虚函数（编译器将补virtual）//与 基类的Draw函数 具有相同原形，与 基类的Draw函数 构成覆盖关系-------覆盖版本虚函数
    void foo(){}
    int m_radius;
};

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    cout << "----------利用 对象 调用 虚的成员函数----------" << endl;
    // 哪个类对象 就调用 哪个类的 虚成员函数(对象自恰性)
    Shape s;
    s.Draw( ); // Shape::Draw
    Rect r;
    r.Draw( ); // Rect::Draw
    Circle c;
    c.Draw( ); // Circle::Draw
    
    cout << "----------利用 指针 调用 虚成员函数----------" << endl;
    Shape* ps = &s;
    ps->Draw( ); // Shape::Draw
    
    ps = &r;//基类型指针ps 指向 子类对象r
    ps->Draw( ); // Rect::Draw (多态)
    
    ps = &c;//基类型指针ps 指向 子类对象c
    ps->Draw( ); // Circle::Draw (多态)
    
    // 根据 指针指向的对象的类型 来确定 到底调用哪个类的虚成员函数
    
    return 0;
}

#endif


