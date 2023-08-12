//
//  04_usethis.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//
#if 0

// 常对象 和 常函数
//常对象：被const关键字修饰的对象、对象指针或对象引用
//常函数：在类成员函数的形参表之后，函数体之前加上const关键字，表示成员函数的this指针具有常属性。

/*
 当非常函数 与 常函数 互为重载关系的时候：
 1.非常对象优先选择非常函数，也可选择常函数
 2.常对象只能选择常函数
 */

//在常函数的内部无法修改成员变量的值，除非该成员变量被mutable关键字修饰

#include <iostream>
using namespace std;

class Integer {
public:
    void setinfo( /* Integer* this */ int i ) { // 非常函数
        m_i = i;
    }
    void getinfo( /* Integer* this */ ) { // 非常函数
        cout << "非常函数getinfo: " << m_i << endl;
    }
    void getinfo( /* const Integer* this */ ) const { // 常函数，互为重载关系
        //this->m_i = 88888;//常函数不能修改成员变量，除非加了mutable，加mutable关键字，编译器就会把 常函数 中m_i的常属性去掉
        const_cast<Integer*>(this)->m_i = 8888;//人为去掉常，也可以，用 常转换 去 常 即可
        cout << "常函数getinfo: " << m_i << endl;
    }
private:
    /*mutable*/ int m_i;//加mutable关键字，编译器就会把 常函数 中m_i的常属性去掉
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    Integer ix; // ix是 非常对象(不挑食)
    ix.setinfo( 1000 );
    ix.getinfo( ); // getinfo( &ix );-->实参Integer*,非常对象优先选择非常函数，也可选择常函数

    const Integer cix=ix; // cix是 常对象(很挑食)   //常数据成员必须初始化（初始化时必须赋值）
    cix.getinfo( ); // getinfo( &cix );-->实参const Integer*,常对象只能选择常函数
    return 0;
    
}

#endif

