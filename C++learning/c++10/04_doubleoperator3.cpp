//
//  04_doubleoperator3.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
/*比较类双目操作符：>、<、==、<=、>=等
 1.左右操作数为非常左值、常左值或右值
 2.表达式结果为bool
 */

/*
 int a = 10,b = 20;
 const int c = 30,d = 40;
 a == b;
 a == c;
 a == 5;
 5 == b;
 */


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
    
    //定义成员操作符函数（函数内部定义运算规则）
   // bool operator==(/* Human* this */  const Human& r) const {
   //     return this->m_age == r.m_age && this->m_name == r.m_name;
   // }
    
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
    friend bool operator==(const Human& l, const Human& r);
    
};

//定义成员操作符函数（函数内部定义运算规则）
bool operator==(const Human& l, const Human& r){
    return l.m_age == r.m_age && l.m_name == r.m_name;
}
//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human a(22,"张飞"),b(23,"赵云");
    const Human c(25,"关羽"),d(34,"马超");
    cout << (a == b) << endl;
    cout << (c == d) << endl;
    cout << (Human(45,"黄忠") == Human(54,"刘备")) << endl;
    
    return 0;
}

#endif

