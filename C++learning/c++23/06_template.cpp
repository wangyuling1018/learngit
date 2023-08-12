//
//  06_template.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/3.
//
/*依赖模板参数访问成员函数模板
 问题：
    利用未知类定义的对象 来访问成员函数模板时，编译器在第一次编译时无法解析成员函数模板的类型参数列表的<>而报告编译错误
 解决方法：
    在成员函数模板之前增加template关键字，意在告诉编译器其后是一个函数模板实例，编译器就可以正确理解<>了。
 
 */

#if 0
#include <iostream>
using namespace std;
//依赖模板参数访问成员函数模板
class A{
public:
    template<typename T>void foo(){
        cout << "A::foo<T>()" << endl;
    }
};
template<typename D>void Func(){
    //未知类型 调用成员函数模板，写法中有<>，写法中必须加template
    D d;
    d.foo(); //第一次编译OK，第二次编译error
    //d.foo<int>();//第一次编译error, 依赖模板参数访问成员函数模板，编译器认为命名不符合规则 不应该有<>这种写法
    
    d.template foo<int>(); //"template"告诉编译器有<>这样写可以
    //d.template bar<int>();//第一次编译OK，第二次编译error,编译器第一次编译只检查标识符，不检查到底有没有函数功能
}
int main(){
    //Func<A>(); //第二次编译
}
#endif
