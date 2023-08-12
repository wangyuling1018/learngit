//
//  06_singleoperator2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

/*在C语言中，前++ 与 后++ 的区别：
  前++：先加1再使用
  后++：先使用再加1
*/

//在C++中，不管前++还是后++ 都是直接加1（内部实现和C语言并不相同），但C++语言还想让用户感觉和C语言一样


/*前自增减类单目操作符：前++，前--
 1.操作数为非常左值
 2.表达式的结果为操作数本身（而非副本）
 */

/*
int a=10, b=20;       // 非常左值
const int c=30, d=40; // 常左值

++a;
++c; // error
++5; // error
 
*/

#if 0

//前++
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
    // 定义操作符函数(函数内部定义运算规则)
    Human& operator++( /* Human* this */ ) {
        this->m_age += 1;
        return *this;
    }
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    Human a(22,"张飞"), b(20,"赵云"); // 非常左值

    (++a).getinfo( ); // a.operator++()

    return 0;
}

#endif



