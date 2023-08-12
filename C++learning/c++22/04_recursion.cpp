//
//  04_recursion.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
/*
 类模板的递归实例化
 1.可以使用任何类型来实例化类模板
 2.由类模板实例化产生的类，也可以用来实例化类模板自身，这种做法称之为类模板的递归实例化
 3.通过这种方法可以构建空间上具有递归特性的数据结构（例如：多维数组）
 */
/*
 A<int>  //int实例化类模板A
 B<...>
 B<A<int>>
 A<A<int>> //A<int>实例化A，递归实例化
 */
#if 0
#include <iostream>
using namespace std;
template<typename T>class Array{
public:
    T& operator[](size_t i){
        return m_arr[i];
    }
private:
    T m_arr[10];
};
int main(){
    /*
    Array<int> a;
    for(int i = 0; i < 10; i++){
        a[i] = i+1;
    }
    for(int i = 0; i < 10; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
     */
    
    Array<Array<int>> m; //递归实例化
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            m[i][j] = i*10+j;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
#endif


