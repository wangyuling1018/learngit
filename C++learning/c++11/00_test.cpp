//
//  00_test.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
/*
Human h; // 定义h,利用 h.Human()
h[i];  // 触发 h.operator[](i) --> 中括号操作符( 下标操作符 ) 函数
h(i,j,k); // 触发 h.operator()(i,j,k) -->小括号操作符( 函数操作符 )函数
*/
 
//小括号操作符函数
#include <iostream>
using namespace std;
class Compare{
public:
    int operator()(int x,int y){ //1 小括号操作符函数
        return x > y ? x : y;
    }
    
    int operator()(int x,int y,int z){//2 小括号操作符函数
        return x+y;
    }
    void operator()(){// 3 小括号操作符函数
        cout << "无聊" << endl;
    }
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Compare c;
    int a = 10, b = 20;
    cout << c(a,b) << endl; //c.operator()(a,b)--触发小括号操作符函数1
    
    cout << c(a,b,1) << endl;//c.operator()(a,b,1)--触发小括号操作符函数2
    
    c();//c.operator()()--触发小括号操作符函数3
    
    return 0;
}
#endif










