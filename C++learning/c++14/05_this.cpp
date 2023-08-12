//
//  05_this.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

/*
 多态需要具备的条件：
 1.基类必须要有虚函数，子类必须提供覆盖版本
 2.必须利用 基类类型指针（必须指向子类对象）调用 虚函数
   必须利用 基类类型引用（必须引用子类对象）调用 虚函数
 
 多态的结果：
    最终 调用的为 子类覆盖版本的虚函数，而非基类原始版本的虚函数
 */
 
/*
 this指针和多态：
 调用虚函数的指针也可以是基类中的this指针，同样能满足多态的条件，但是构造和析构函数中除外
 */

//this 和 虚函数

#if 0

#include <iostream>
using namespace std;
class Base{
public:
    Base(/* Base* this */  ){
        cout << "构造函数中调用：";
        this->vfun();
    }
    ~Base(/* Base* this */  ){
        cout << "析构函数中调用：";
        this->vfun();
    }
    void foo(/* Base* this */  ){
        cout << "foo函数中调用: ";
        this->vfun();
    }
    virtual void vfun(){cout << "Base::vfun()"<< endl;} //原始版本虚函数
};
class Derived : public Base{
public:
    Derived(){
        //定义 基类子对象，利用 基类子对象.Base()  //this 指向 基类子对象 ---构造函数除外
    }
    ~Derived(){
        //针对 基类子对象，利用 基类子对象.~Base() //this 指向 基类子对象 -----析构函数除外
    }
    void vfun(){cout << "Derived::vfun()"<< endl;} //覆盖版本虚函数
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Derived d;// 定义d,利用d.Derived()
    d.foo();//foo(&d)，this指向d
    return 0;
}// d.~Derived()

#endif

/*运行结果：
 构造函数中调用：Base::vfun()
 foo函数中调用: Derived::vfun()
 析构函数中调用：Base::vfun()
 */
