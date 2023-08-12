//
//  03_hastothis.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/18.
//

#if 0

//必须自己明显写this的 三种情况
//（1）有时为了方便，将类的成员变量与该类的成员函数的参数取相同标识符，这时在成员函数内部，可通过this指针将二者区分
//（2）返回基于this指针的自引用，以支持串联调用
//（3）将this指针作为函数的参数，以实现对象交互

#include <iostream>
using namespace std;
class Integer; // 短式声明

void Print( Integer* v ) {
    // ...
}
class Integer {
public:
    void setinfo( /* Integer* this */ int i ) {
        this->i = i; //(1) 必须明显写this
    }
    void getinfo( /* Integer* this */ ) {
        cout << /*this->*/i << endl; // 这里的this编译器帮我们补充
        Print( this ); //(3)必须明显写this
    }
    Integer& increment( /* Integer* this */ ) {
        ++/*this->*/i; // 这里的this编译器帮我们补充
        return *this; // (2)返回基于this指针的自引用
        //返回谁，就是谁的别名，返回this，this指向ix，那么就是ix的别名
    }
private:
    int i; // m_xxx
};
// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    Integer ix;
    ix.setinfo( 1000 );
    ix.getinfo( );

    ix.increment( ).increment( ).increment( ); // 串联调用
    //ix.increment( )执行完后，ix.increment( )是ix的别名，最后ix.getinfo( );ix.increment( ).increment( ).increment( )是ix的别名。
    ix.getinfo( );
    
    return 0;
}

#endif






