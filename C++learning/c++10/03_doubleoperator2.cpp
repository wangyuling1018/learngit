//
//  03_doubleoperator2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0

/*赋值类双目操作符：=、+=，-=，*=，/=等
 1.右操作数可以为非常左值、常左值或右值，但左操作数必须为非常左值
 2.表达式结果为左操作数本身（而非副本）
*/

/*
 int a = 10,b = 20;
 const int c = 30,d = 40;
 a = b;
 a = c;
 a = 5;
 c = b; //error
 5 = b; //error
 */

//拷贝赋值函数operator=函数，其实就是操作赋值函数的一种。
//只有operator=操作符函数，如果没有提供，编译器会提供默认的operator=操作符函数，其他的操作符函数编译器不会提供。

//如果想要拿到谁的本身，只能用引用


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
  //  Human& operator+=(/* Human* this */ const Human& r){
  //      this->m_age = this->m_age + r.m_age;
  //      this->m_name = this->m_name + "+ " + r.m_name;
  //      return *this;
  //  }
    
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
    friend Human& operator+=(Human& l,const Human& r);
};

//定义成员操作符函数（函数内部定义运算规则）
Human& operator+=(Human& l,const Human& r){
    l.m_age = l.m_age + r.m_age;
    l.m_name = l.m_name + "+ " + r.m_name;
    return l;
}

//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Human a(22,"张飞"),b(23,"赵云");
    const Human c(25,"关羽"),d(34,"马超");
    a += b; // a.operator+=(b) 或 operator+=(a,b)
    a.getinfo( );

    a += c; // a.operator+=(c) 或 operator+=(a,c)
    a.getinfo( );

    a += Human(45,"黄忠"); // a.operator+=(Human(45,"黄忠")) 或 operator+=(a,Human(45,"黄忠"))
    a.getinfo( );
    
    ((a+=b)+=c)+=Human(45,"黄忠");
    a.getinfo( );
    
    return 0;
}
#endif


