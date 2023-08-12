//
//  09_hs.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
/*
 公有继承独有的特点：
 1.只有在公有继承下，子类对象在类的外部 可以访问 基类的公有成员，其他继承不可以
 2.只有在公有继承下，子类类型的指针 和 基类类型的指针 可以进行转换
                  子类类型的引用 和 基类类型的引用 可以进行转换
                  其他继承方式不可以。
 
 
 关于指针的一个原理探讨：
   指针为什么需要类型？答：指针的类型 决定了 指针的眼界（*） 和 步长（+1）
    int* pa;  *pa (站在pa指针上可以看到4个字节)   pa+1（加1，pa可以移动4个字节）
    double* pb;  *pb(站在pb指针上可以看到8个字节)    pb+1(加1，pb可以移动8个字节）
    short* pc;   *pc(站在pc指针上可以看到2个字节)    pc+1(加1，pc可以移动2个字节)
    char* pd;    *pd(站在pd指针上可以看到1个字节)    pd+1(加1，pd可以移动1个字节)
*/

/*
 向上造型：
 子类类型指针 可以隐士转换为 基类类型指针
 子类类型引用 可以隐士转换为 基类类型引用
*/

#if 0

//编译器认为访问访问缩小是安全的
#include <iostream>
using namespace std;
class Human{
public:
private:
    int m_age;
    string m_name;
    
};
class Student : public Human{
public:
private:
    int m_no;
};
//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human h; // |m_age m_name|
    cout << "基类对象h的大小: " << sizeof(h) << endl; // 36

    Student s; // |基类子对象|m_no| ==> |m_age m_name|m_no|
    cout << "子类对象s的大小: " << sizeof(s) << endl; // 40

    Human* ph = &s; // Student* --> Human* //子类类型指针 可以隐士转换为 基类类型指针
    Human& rh = s;                         //子类类型引用 可以隐士转换为 基类类型引用
    // 以上两行代码，编译器认为访问范围缩小，是安全的.(向上造型)
    
    //Student* ps = &h; //error，编译器认为访问范围扩大，是有风险的
    //Student& rs = h; //error，编译器认为访问范围扩大，是有风险的
    //以上2行代码，Human* --->Student*,Human的眼界是40个字节，Student的眼界是36个字节，40个字节转成36个字节，有风险，通过ps可以看到后面4个字节，有可能越界访问

//  Student* ps = static_cast<Student*>(&h); // Human* --> Student*
//  Student& rs = static_cast<Student&>(h);
    // 以上两行代码，编译器认为访问范围扩大，是有风险的
    // 通过强转虽然可以成功，但风险依然存在，极其不建议大家这么做.

   // Student* ps = ph; // Human* --> Student* ，ps只能看到36个字节，后面4个字节看不到
    //Student& rs = rh;//rs只能看到36个字节，后面4个字节看不到
    //结合50、51行代码，以上两代码，没有风险,但是编译器认为有风险，因为编译器 简单粗暴的根据 类型 来判断是否存在风险。可以通过强转
    
    Student* ps = static_cast<Student*>(ph); // Human* --> Student*
    Student& rs = static_cast<Student&>(rh);
    // 结合50、51行代码，以上两代码，没有风险,极其建议大家这么做
    //
    // 编译器 简单粗暴的根据 类型 来判断是否存在风险
    
    return 0;
}
#endif



