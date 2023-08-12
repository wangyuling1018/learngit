//
//  03_typeinfo.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//


//操作符：+、-、*、/、sizeof等
/*
 typeid操作符：
 1.#include<typeinfo>
 2.返回type_info类型对象的常引用
   type_info类的成员函数name()，返回类型名字符常
   type_info类支持“==”和“！=”操作符，可直接用于类型相同与否的判断
 3.当其作用于基类类型的指针或引用的目标对象时
    若基类不包含虚函数typeid所返回类型信息由该指针或引用本身的类型决定
    若基类包含至少一个虚函数，即存在多态继承，typeid所返回类型信息由该指针或引用的实际目标对象的类型决定
 */
#if 0

//typid无法获取对象本身的常属性信息
//typeid操作符：获取对象的类型信息
#include <iostream>
#include <typeinfo>
using namespace std;
class A{// 编译器根据A类信息,将制作一张虚函数表  "A"...|A::foo的地址
    virtual void foo() {}
};
class B : public A { // 编译器根据B类信息,将制作一张虚函数表  "B"...|A::foo的地址
    
};

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    B b;//b对象只有在运行期间才会占内存 // |虚表指针|-->编译器根据B类信息制作的虚函数表
    A* pa = &b;
    A& ra = b;
    cout << typeid(*pa).name() << endl;//A中无虚函数，返回A，在编译时查看对象本身类型  //A中有虚函数，返回B，有虚函数后在运行时查看 b对象所占内空间，查看虚函数表
    //  pa-->b对象所占内存空间-->虚表指针-->编译器根据B类信息制作的虚函数表-->"B"
    
    cout << typeid(ra).name() << endl;//A中无虚函数，返回A  //A中有虚函数，返回B
    //  ra-->b对象所占内存空间-->虚表指针-->编译器根据B类信息制作的虚函数表-->"B"
    
    
    int m;
    const type_info& rty = typeid(m);
    //1.获取m的类型信息
    //2.创建一个type_info类 的对象
    //3.将 获取的m的类型信息 保存到 type_info这个类对象的 各个“私有”成员变量中
    //4.返回这个type_info类对象的 常引用
    string rn = rty.name();
    cout << "m的类型："<< rn << endl;//i，i是int类型
    
    const int n = m;
    cout << "n的类型：" << typeid(n).name() << endl; //i，无法获取对象本身的常属性
    
    cout << (typeid(m) == typeid(n)) << endl;
    cout << (typeid(m) != typeid(n)) << endl;
    
    
    return 0;
}

#endif

