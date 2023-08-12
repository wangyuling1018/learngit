//
//  05_singleoperator1.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

/*运算类单目操作符：-、～、！等
 1.操作数为非常左值、常左值或右值
 2.表达式的结果为右值
 */

/*
int a=10, b=20;       // 非常左值
const int c=30, d=40; // 常左值

|-10| -a;

|-30| -c;

|-5| -5;
 
*/
#if 0
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
   // Human operator-(/* Human* this */) const {
   //     return Human(-this->m_age,("-" + this->m_name).c_str());
   // }
    
    
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
    friend Human operator-(const Human &l);
    
};

//定义成员操作符函数（函数内部定义运算规则）
Human operator-(const Human &l){
    return Human(-l.m_age,("-" + l.m_name).c_str());
}

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human a(22,"张飞"),b(23,"赵云");
    const Human c(25,"关羽"),d(34,"马超");
    Human res = -a; // a.operator-()
    res.getinfo( );

    res = -c; // c.operator-()
    res.getinfo( );

    res = -Human(45,"黄忠"); // Human(45,"黄忠").operator-()
    res.getinfo( );
    
    return 0;
}

#endif
