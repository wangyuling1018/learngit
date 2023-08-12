//
//  05_copytime.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
#include <iostream>
using namespace std;
// 拷贝构造函数 被调用的 时间
class Human {
public:
    Human( int age=0, const char* name="无名" ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        m_age = age;
        m_name = name;
    }
    Human( const Human& that ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,并利用m_name.string()
        cout << "Human类拷贝构造函数被调用" << endl;
        m_age = that.m_age;
        m_name = that.m_name;
    }
    void getinfo( /* Human* this */ ) {
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
void foo( Human v ) {
    // ...
}
Human bar( ) {
    Human m;
    return m;
}
int main( void ) {
    Human h(22,"张飞");

    Human h2(h); // 定义h2,利用h2.Human(h) --> 触发拷贝构造函数

    foo( h2 ); // --> 触发拷贝构造函数

    Human h3 = /*|...|*/ bar( ); // --> 触发2次拷贝构造函数(被编译器优化了)
    //第一次：利用m克隆一个匿名对象  第二次：利用匿名对象克隆h3
    //实际是克隆了2次，但是编译器优化后没有克隆了，编译器为了效率故意优化的，是好事

    // -fno-elide-constructors 加该选项可以不让编译器优化
    //编译的时候可以使用：g++ xxx.cpp -fno-elide-constructors
    return 0;
}
#endif


