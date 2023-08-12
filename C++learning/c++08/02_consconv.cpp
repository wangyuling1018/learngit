//
//  02_consconv.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//
#if 0
/*类型转换构造：
 只有一个参数
 唯一的参数类型与类名不同
 */

//单参构造只有2个：拷贝构造（唯一的参数类型与类名一样）、类型转换构造（唯一的参数类型与类名不同）

/*类型转换构造的作用：
 利用一个已定义的对象，来定义另一个不同类型的对象
 实现从源类型到目标类型的隐士类型转换的目的
 */

/*自定义转换：
 程序员自己定制转换规则（利用类型转换构造函数来定制自定义转换规则）
 */

//explicit的作用：类型转换构造函数前加explicit，意味着不能隐士转换了，只能强转（静态类型转换）。
//静态类型转换的第二个应用场景：自定义转换

/*所有类型转换，都不会更改源数据本身，都是产生一个匿名对象（变量）
   double a = 3.14;
   int b = (int)a;//a的数据和类型并没有改变，只是产生了一个匿名对象给b赋值了
 */

#include <iostream>
using namespace std;
// 类型转换构造函数
class Cat {
public:
     explicit Cat( const char* name ) : m_name(name) { // 也是类型转换构造函数
        //【string m_name(name);】
        cout << "Cat类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 喵喵~~~" << endl;
    }
private:
    string m_name;
    friend class Dog;
};
class Dog {
public:
    Dog( const char* name ) : m_name(name) { // 也是类型转换构造函数
        //【string m_name(name);】
    }
    explicit Dog( const Cat& that ) : m_name(that.m_name) { // 类型转换构造函数 //加explicit意味着隐式转换不让调用
        //【string m_name=that.m_name;】
        cout << "Dog类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 汪汪~~~" << endl;
    }
private:
    string m_name;
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
  //Cat smallwhite("小白"); // 定义smallwhite,利用smallwhite.Cat("小白")-->类型转换构造函数 //隐士转换
   //Cat smallwhite = "小白"; // 定义 匿名Cat类对象,利用 匿名Cat类对象.Cat("小白") //隐士转换
                             // Cat smallwhite=匿名Cat类对象
    Cat smallwhite = static_cast<Cat>("小白");//强转（静态类型转换）
    smallwhite.talk( );

    //利用一个已定义的对象，来定义另一个不同类型的对象
 // Dog bigyellow( smallwhite ); // 定义bigyellow,利用bigyellow.Dog(smallwhite)-->触发类型转换构造

  //  Dog bigyellow = smallwhite; // 定义 匿名Dog类对象, 利用 匿名Dog类对象.Dog(smallwhite)-->触发类型转换构造，隐式转换
                                // Dog bigyellow = 匿名Dog类对象 ---->触发拷贝构造函数（克隆）
    Dog bigyellow = static_cast<Dog>(smallwhite); //加了explicit后，必须用强转（静态类型转换）
                    // 定义 匿名Dog类对象, 利用 匿名Dog类对象.Dog(smallwhite)
                    // Dog bigyellow = 匿名Dog类对象
    bigyellow.talk( );
    return 0;
}

#endif








