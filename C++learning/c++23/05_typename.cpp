//
//  05_typename.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//
/*嵌套依赖
 问题：
    由于模板要经过两次编译，在第一次编译模板的代码时，类型形参的具体类型尚不明确，编译器将把类型形参的嵌套类型理解为 某个未知类型的静态成员变量，因此编译器看到使用这样的标识符声明变量时 会报告错误，这就叫嵌套依赖。
 解决方法：
    在类型形参的前面增加一个typename标识符，意在告诉编译器其后是一个类模板的嵌套使用。
 */
#if 0
#include <iostream>
using namespace std;
class A{
public:
    class B{
    public:
        void foo(){
            cout<< "A::B::foo()" << endl;
        }
    };
};

template<typename T>void Func(){
    //已知类型 调用嵌套类型 //A是已知类型
    A::B bb;
    bb.foo();
    
    //未知类型 调用嵌套类型，写法中有::的，必须加typename //T是未知类型
    //T::B b; //error 嵌套依赖，编译器认为T::B 这种写法，B是静态成员函数，但是后面加了b，编译器又认为调用静态成员函数的写法 不应该在后面加一个b，所以第一次编译就报错
    typename T::B b; //“typename”告诉编译器 T::B是嵌套类型
    b.foo();
}

int main(){
    Func<A>();
}
#endif
