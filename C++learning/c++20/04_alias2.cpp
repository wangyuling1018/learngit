//
//  04_alias2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

/*
 注意：有没有常右值引用呢？
    其实是有的，只是没有必要，因为常右值引用，完全可以被常左值引用替代
    因为常左值引用 会丧失修改修改目标的权限，右值引用的目的就是为了修改目标，而常右值引用 和 常左值引用 一样也会丧失修改目标的权限。
 */

#if 0
// 左值引用 和 右值引用  的差别
#include <iostream>
using namespace std;

int main( void ) {
    // 左值引用 只能引用 左值，不能引用 右值
    int a, c; //左值
    int& b = a;        // ok
//  int& d = a + c;    // error，a+c的结果放在无名内存中，是右值

    // 右值引用 只能引用 右值，不能引用 左值
    int&& e = a + c;  // ok
    e = 8888; //ok,通过右值引用 引用 右值时，不会丧失修改目标的权限
//  int&& f = a;      // error

    // 常左值引用 既可以引用左值，也可以引用右值
    const int& g = a + c; // ok
//    g = 8888; // error,但是当常左值引用 引用右值时，通过常左值引用丧失修改目标的权限

    const int& h = a;     // ok


    return 0;
}
#endif

