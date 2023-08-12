//
//  01_cast.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0

/*类型转换操作符：
 1.若源类型是 基本类型，目标类型是 类类型，则只能通过 类型转换构造函数 实现自定义类型转换。----->基本类型 转 类类型
 class 目标类型{
    目标类型（const 源类型& src）{....}
 };
 
 2.若目标类型是 基本类型，源类型是 类类型，则只能通过 类型转换操作符函数 实现自定义类型转换。----->类类型  转 基本类型
 class 源类型{
    operator 目标类型(void）const {....}
 };
 */

//类型转换操作符 函数

#include <iostream>
using namespace std;
class Integer{
public:
    Integer(int i = 0) : m_i(i){
        // 【 int m_i = i;】
        cout << "Integer类的 类型转换构造函数 被调用" << endl;
    }
    operator int(/* const Integer* this */) const {
        cout << "Integer类的 类型转换操作符函数 被调用" << endl;
        return this->m_i;
    }
private:
    int m_i;
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    int n = 666;
    //int ---> Integer（基本类型---> 类类型）
    Integer ix = n;//定义 匿名Integer类对象，利用 匿名Integer类对象.Integer(n) --->类型转换构造函数
                    // 真正给 Integer ix 做初始化的是 匿名Integer类对象，Integer ix = 匿名Integer类对象 （克隆）
                    // 如果用类型操作符函数：Integer ix = n.operator Integer() --->int类中肯定没有operator Integer()这个类型操作符函数，所以基本类型往类类型上转 只能 用类型转换构造函数。
    
    
    //Integer ----> int(类类型 ---> 基本类型)
    int m = ix;//定义 匿名int类对象，利用 匿名int类对象.int(ix) ---->int类中没有一个形参味Integer的类型转换构造函数
    //int m = ix.operator int()
    return 0;
}

#endif

