//
//  02_cast2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0

/*自定义类型转换：
 1.若源类型和目标类型都是类类型（而非基本类型），则既可以通过类型转换构造函数 也可以通过类型转换操作符函数实现自定义类型转换，但不要两者同时使用。---->类类型 转 类类型
 2.若源类型和目标类型都是基本类型，则无法实现自定义类型转换，基本类型间的类型转换规则完全由编译器内置。---->基本类型 转 基本类型
 */


// 类型转换构造函数 和 类型转换操作符函数
#include <iostream>
using namespace std;

class Dog;//短式声明

class Cat {
public:
    Cat( const char* name ) : m_name(name) {
        //【string m_name(name);】
        cout << "Cat类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 喵喵~~~" << endl;
    }
    operator Dog() const;//声明
private:
    string m_name;
    friend class Dog;
};
class Dog {
public:
    Dog( const char* name ) : m_name(name) {
        //【string m_name(name);】
    }
    /*
    Dog( const Cat& that ) : m_name(that.m_name) {
        //【string m_name=that.m_name;】
        cout << "Dog类的类型转换构造函数被调用" << endl;
    }
     */
    void talk( ) {
        cout << m_name << ": 汪汪~~~" << endl;
    }
private:
    string m_name;
};
Cat::operator Dog() const{
    cout << "Cat类的类型转换操作符函数被调用" << endl;
    return Dog(this->m_name.c_str());
}
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    Cat smallwhite("小白"); // 定义smallwhite,利用smallwhite.Cat("小白")-->类型转换构造函数 //隐士转换
 
    Dog bigyellow = smallwhite; // 定义 匿名Dog类对象, 利用 匿名Dog类对象.Dog(smallwhite)-->触发类型转换构造，隐士转换
                                //Dog bigyellow = smallwhite.operator Dog() ---->触发类型转换操作符函数
    //bigyellow.talk( );
    return 0;
}
#endif

