//
//  08_numparam.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板扩展-数值形式的模板参数
 1.类模板的模板形参并不限于类型参数，普通数值也可以作为模板参数
 
 */
#if 0
#include <iostream>
using namespace std;
// 数值类型的模板参数: 必须是整型：
//template<typename T, string S>class Array{ //error，必须是整型
//template<typename T, double S>class Array{ //error ，必须是整型
//template<typename T, size_t S>class Array{ // ok ,size_t 就是int
template<typename T, size_t S = 15>class Array{ //ok, 可以加默认值
public:
    T& operator[](size_t i){
        return m_arr[i];
    }
    size_t size(){//桥梁函数
        return S;
    }
private:
    T m_arr[S];//数组的个数，由用户决定
};

int main(){
    Array<int/*,20*/> a;
    for(int i=0;i<a.size();i++)
        a[i] = i+1;
    for(int i=0;i<a.size();i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
#endif
