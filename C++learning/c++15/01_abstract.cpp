//
//  01_abstract.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

/*
 抽象类：
1.拥有纯虚函数的类称为抽象类
2.抽象类不能实例化为对象
3.抽象类的子类如果不对基类中的全部纯虚函数提供有效的覆盖，那么该子类就也是抽象类
 
 纯抽象类：
 全部由纯虚函数构成的抽象类称为纯抽象类或接口
 
 抽象类的作用：当类业务上无法定义对象，且类中的函数无法实现，使这个函数变成纯虚函数，等着子类去覆盖这个纯虚虚函数。
 */
#if 0
#include <iostream>
using namespace std;
// 纯虚函数 和 抽象类
class A { // 抽象类
public:
    virtual void foo( ) = 0; // 纯虚函数
    void bar( ) {
        // ...
    }
};
/*
class B : public A {//B是抽象类
public:
    void foo( ); //foo函数必须有花括号，才是有效的覆盖
};
 */

class B : public A {//B不是抽象类
public:
    void foo( ) {//纯虚函数的覆盖版本
        // ...
    }
};

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
//  A a; //error，不能实例化
//  new A; //error，不能实例化

    B b;
    new B;
    return 0;
}

#endif

