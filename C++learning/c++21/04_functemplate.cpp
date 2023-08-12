//
//  04_functemplate.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/2.
//
// 函数模板并不是函数，只是有办法让它产生函数
//<>中为类型参数，函数名后()中的为调用参数
//class 和 typename 都可以，随便选哪一个

/*
 函数模板的定义
 template<{class|typename} 类型参数1，{class|typename} 类型参数2,....>
 返回值类型 函数模板名（调用参数1，调用参数2，....）{
     ....
 }
 例如：template<class T> T Max(T x,T y){
        return x > y ? x : y;
    }
 可以使用任何标识符作为类型形参的名称，但使用“T”已经成为一种惯例，“T”表示的是 调用者在使用这个函数模板时指定的任意数据类型
 
 
 函数模板的使用
 1.使用函数模板必须对函数模板进行实例化
 2.形式：函数模板名<类型实参1，类型实参2，...>(调用实参1，调用实参2，...);
    例如：   Max<int>(123,456);
            Max<double>(12.3,45.6);
            Max<string>("hello","world");
 */

#if 0
#include <iostream>
using namespace std;
class Integer{
public:
    Integer(int i) : m_i(i){}
    bool operator>(const Integer& that) const {
        return this->m_i > that.m_i ;
    }
private:
    int m_i;
    friend ostream& operator<<(ostream& os,const Integer& that);
};
ostream& operator<<(ostream& os,const Integer& that){
    os << that.m_i;
    return os;
}
//函数模板
template<class T>
T Max(T x,T y){
    return x > y ? x : y;
}

// int Max(int x, int y){ ... }
// double Max(double x, double y){ ... }
// string Max(string x, string y){ ... }
// Integer Max(Integer x, Integer y) { return x>y?x:y;}
int main(){
    Integer ix = 100, iy = 200;
    cout << Max<Integer>(ix,iy) << endl;
    
    
    int nx = 10, ny = 20;
    cout << Max<int>(nx,ny) << endl;
    //      Max(nx,ny)
    
    double dx = 1.23, dy = 4.56;
    cout << Max<double>(dx,dy) << endl;
    //      Max(dx,dy)
    
    string sx = "world", sy = "hello";
    cout << Max<string>(sx,sy) << endl;
    //      Max(sx,sy)

    return 0;
}
#endif
