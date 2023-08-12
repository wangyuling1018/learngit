//
//  00_test.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 1. 任何 基本类型 都可以 隐式转换( 编译器帮我们转换 ) 为 布尔类型
     任何 复合类型（类对象） 如何转换为 布尔类型？ 答：利用 类型转换操作符函数  operator bool()

     在C++语言的程序中 经常出现 类对象 放在 bool的上下文中（例如：利用类对象给bool变量初始化、利用类对象给bool变量赋值、if语句的判定条件、
                                                                                                          while循环的判定条件、for循环的第二个判定条件、逻辑反 ）
      
      class A {....};
      A a;

      bool b = a; // 利用类对象给bool变量初始化
      bool c;
      c = a; // 利用类对象给bool变量赋值
      
      if( a ) { // if语句的判定条件
      }
      while( a ) { // while循环的判定条件
      }
      for( .. ;  a  ; ..) { // for循环的第二个判定条件

      }
      !a; //  逻辑反

    一旦出现上述这6中情况，编译器需要将 类对象 转换为布尔类型

 C++标准库封装的 流对象(cin/cout...),允许我们用户 将其放置在布尔上下文中，可以 实时判断 IO操作（打开操作/读操作/写操作）是否成功。
 */

#if 0
#include <iostream>
using namespace std;
//类对象 转换为 bool类型
class A{
public:
    A(int i) : m_i(i){
        
    }
    operator bool() const {
        cout << "A类的类型转换操作符函数被调用" << endl;
        return this->m_i;
    }
private:
    int m_i;
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    A a(8888), b(0);
    
    bool c = a;//bool c = a.operator bool() --->A类的类型转换操作符函数
    cout << "c=" << c << endl;
    
    bool d;
    d = b;//d = b.operator bool()
    cout << "d=" << d << endl;
    
    if(a){//a.operator bool()
        cout << "if语句的判定条件为true" << endl;
    }
    
    while(a){//a.operator bool()
        cout << "while语句的判定条件为true" << endl;
        break;
    }
    
    for(;a;){//a.operator bool()
        cout << "for语句的判定条件为true" << endl;
        break;
    }
    
    cout << !a << endl;// !a.operator bool()
    
    return 0;
}
#endif
