//
//  04_throw3.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 匹配顺序：
  根据异常对象的类型自上而下顺序匹配，而非最优匹配，因此对子类类型异常的捕获不要放在对基类类型异常的捕获后面
 */

#if 0
#include <iostream>
using namespace std;
class A{};
class B : public A{};

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
/*
 //有警告，但是可以编译成功
 //使用第一个catch捕获，即使第二个catch更适合，但是编译器是自上而下选择，不会选最优的
 //编译器找一个能捕获的就立马捕获了
void foo(){
    throw B();
}
int main( void ) {
    try{
        foo();
    }
    catch(A& e){
        cout << "A& 捕获到异常" << endl;
    }
    catch(B& e){
        cout << "B& 捕获到异常" << endl;
    }

    return 0;
}
 */

//摆放位置换一下，就不会有警告了
//子类类型的捕获放在最前面
void foo(){
    throw B();
    //throw A(); //编译器不会找catch(B& e)，因为子类类型引用 转 基类类型引用 是有风险的，这个不行，所以编译器会往下找catch(A& e)
    //所以对子类类型的捕获要放最前面
}
int main( void ) {
    try{
        foo();
    }
    catch(B& e){
        cout << "B& 捕获到异常" << endl;
    }
    catch(A& e){
        cout << "A& 捕获到异常" << endl;
    }

    return 0;
}
#endif
