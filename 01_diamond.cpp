//
//  01_diamond.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
//钻石继承：一个子类继承字多个基类，而这些基类又源自共同的祖先（菱形结构）

//钻石继承问题：公共基类子对象，在汇聚子类对象中，存在多个实例

// 汇聚子类(Z类)对象中 包含2个 公共基类(A类)子对象
#include <iostream>
using namespace std;
class A{//公共基类(人类)
public:
    int m_a;
};
class X: public A{//中间子类（学生类）
public:
    int m_x;
};

class Y : public A{//中间子类（老师类）
public:
    int m_y;
};

class Z : public X ,public Y{//汇聚子类（助教类）
public:
    int m_z;
    void foo(){
        //m_a = 100;//error 产生歧义错误
        X::m_a = 100;// 虽然可以解决歧义错误的问题，但不合理
    }
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Z z;// |X中间子类子对象|Y中间子类子对象|m_z|==>|A公共基类子对象 m_x|A公共基类子对象 m_y|m_z|==>|m_a m_x|m_a m_y|m_z|
    cout << "汇聚子类对象z的大小：" << sizeof(z) << endl;
    //z.m_a = 100;//error 产生歧义错误
    z.Y::m_a = 100;// 虽然可以解决歧义错误的问题，但不合理
    
    return 0;
}

#endif

