//
//  02_lambda2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
/*
 lambda表达式：
 捕获表：
 1.[] -不捕获任何外部变量  //外部是指lambda表达式的外部
 2.[variable] -捕获外部变量的值（具备只读属性）
 3.[&variable] -按引用捕获，指定的外部变量
 4.[this] -捕获this指针，访问外部对象的成员
 5.[=] -按值捕获所有的外部变量，也包括this
 6.[&] -按引用捕获所有的外部变量，也包括this
 7.[=,&variable] -按值捕获所有的外部变量包括this，但是指定的外部变量按引用捕获
 8.[&,=variable] -按引用捕获所有的外部变量，也包括this，但是指定的外部变量按值捕获

 */

#if 0
#include <iostream>
using namespace std;
int a = 10;

class Y{
public:
    Y() : e(50) {}
    void foo(/* Y* this */ int c = 30){
        cout << "-----------[]--------------" << endl;
        [](int d = 40){
            cout << "a=" << a << endl;//先找X范围->Y范围->全局范围,跳过foo范围，foo看不到
            cout << "b=" << b << endl;
            //cout << "c=" << c << endl;//error，先找X范围->Y范围->全局范围,跳过foo范围，foo看不到
            cout << "d=" << d << endl;
            //cout << "e=" << e << endl; //error,error，普通成员变量  要么 对象调用，要么 this指针调用，foo函数中补的this看不到
        }();
        /*
         class X{
         public:
                void operator()(int d = 40){
                    cout << "a=" << a << endl;
                    cout << "b=" << b << endl;
                    //cout << "c=" << c << endl;
                    cout << "d=" << d << endl;
                }
         };
         X{}(); // X{}.operator()() //匿名对象X{}调用operator()()函数
         */
        
        //捕获外部变量的"值“
        cout << "-----------[c]--------------" << endl;
        [c](int d = 40) {cout << "c=" << c/* ++ */<< endl;}();//c不能修改，具有const属性
        /*
         class XX{
         public:
                XX(int c) : c(c) {} // 构造函数的形参c，仅仅是构造函数的形参，并不是foo形参c
                                    // 初始化表中 c为XX类的成员变量，(c)为构造函数的形参
                void operator()(int d = 40){
                    cout << "c=" << c << endl;
                }
         private:
                const int c;//这里的c并不是foo函数的形参c，而是XX类成员变量
         };
         XX{c}(); // 定义XX类匿名对象，利用XX匿名对象.XX(c)  //XX(c).operator()() //这里的c为foo函数的形参c
         */
        
        cout << "-----------[&c]--------------" << endl;
        [&c](int d = 40) { cout << "c=" << ++c << endl; }();
        /*
         class XXXX{
         public:
                XXXX( int&c ) : c(c) {}
                void operator() (int d = 40){
                    cout << "c=" << ++c << endl;
                }
         private:
                int& c;
         };
         XXXX{c}(); //定义XXXX类的匿名对象，利用XXXX类的匿名对象.XXXX(c)  这里的c为foo函数的形参c
         */
        
        cout << "-----------[this]--------------" << endl;
        [this](int d = 40) {cout << "e=" << e << endl;}();
        
    }
private:
    static int b;
    int e;
};

int Y::b = 20;

int main( void ) {
    Y y;
    y.foo();

    return 0;
}

#endif
