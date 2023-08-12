//
//  01_complex.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0

//操作符重载（操作符重定义）
//操作符也是运算符
/*
 int a,b;
 a+b;/基本类型 编译器知道按照什么规则做加法
 
 Human c,d;
 c + d;//自己设计的类型，编译器并不知道按照什么规则做加法
 */

//操作符重载：重新定义操作符的运算规则，一旦重新定义操作符的运算规则，可以使我们自己设计的类型也和基本类型一样参与各种运算符表达式

#include <iostream>
using namespace std;
class Human {
public:

    Human( int age=0, const char* name="无名" ) : m_age(age),m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
    }
    void getinfo( /* Human* this */ ) {
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
    Human sum(/* Human* this */  Human that){
        return Human(this->m_age + that.m_age,(this->m_name + "+" + that.m_name).c_str());
    }
    Human sub(/* Human* this */ Human that){
        return Human(this->m_age - that.m_age,(this->m_name + "-" + that.m_name).c_str());
    }
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human a(22,"张飞"),b(23,"赵云"),c(25,"关羽"),d(34,"马超");
    
    Human res = a.sum(b);//a + b; ====>a.operater+(b) 或 operator+(a,b)
    res.getinfo();
    
    res = c.sub(d);// c - d; ====>c.operater-(d) 或 operator-(c,d)
    res.getinfo();
    
    res = a.sum(b).sub(c.sub(d));//a + b - ( c - d);
                                //====>a.operator+(b).operator-(c.operator-(d))
                                //====>operator-(operator+(a,b),operator-(c,d))
    return 0;
}
#endif


