//
//  04_consconvtime.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0
/*类型转换构造函数被调用的时机：
 1.用已定义对象作为不同类型对象的构造实参
 2.用已定义对象给不同类型的对象初始化 或 赋值
 3.以对象的形式向函数传递不同类型参数
 4.从函数中返回不同类型的对象
 */

//只要是不同类型，编译器都会用到类型转换构造函数

#include <iostream>
using namespace std;
// 类型转换构造函数被调用的时间
class Cat {
public:
    Cat( const char* name ) : m_name(name) { // 类型转换构造函数
        //【string m_name(name);】
        cout << "Cat类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 喵喵~~~" << endl;
    }
private:
    string m_name;
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
void foo( Cat c ) {
    // ...
}
Cat bar( ) {
    return "小灰"; // 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小灰")-->触发类型转换构造函数
                   // return 匿名Cat类对象
}
int main( void ) {
    //1.用已定义对象作为不同类型对象的构造实参
    //“小白”是已定义的对象
    Cat s1("小白"); // 定义s1,利用s1.Cat("小白")-->触发类型转换构造函数

    //2.用已定义对象给不同类型的对象 初始化
    Cat s2 = "小白"; // 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小白")-->触发类型转换构造函数

    //2.用已定义对象给不同类型的对象 赋值
    s2 = "小花"; // 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小花")-->触发类型转换构造函数

    //3.以对象的形式向函数传递不同类型参数
    foo( "小黑" ); // 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小黑")-->触发类型转换构造函数
                   // foo( 匿名Cat类对象 );
    
    //4.从函数中返回不同类型的对象
    bar( );
    return 0;
}

#endif






