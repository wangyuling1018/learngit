//
//  03_stack.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/19.
//

#if 0
/*下标操作符：[]
 1.常用于在容器类型中以下方式获取数据元素
 2.非常容器的元素为非常左值，常容器的元素为常左值
 */

/*C++语言的一个思想：一个对象 内部 包含了什么，我们就拿 对象 当什么来用
 例如：Stack类中包含了一个数组m_a，那么我们就拿Stack当数组来使用。但首如果想拿对象当数组用，首先要在类中定义操作符函数。
 */

//设计一个简易的栈容器
//想要拿Stack当数组使用
#include <iostream>
using namespace std;
class Stack{
public:
    Stack() : m_size(0){
        //【int m_a[20];】
        //【int m_size=0;】
    }
    void push(int data){// 判满操作，自己课下写
        m_a[m_size++] = data;
    }
    int pop(){// 判空操作，自己课下写
        return m_a[--m_size];
    }
    int size(){
        return m_size;
    }
    int& operator[](/* Stack* this */int i){ //常函数
        return this->m_a[i];
    }
    const int& operator[](/* const Stack* this */int i) const {//非常函数
        return this->m_a[i];  //this带const，那么返回值带const，则函数返回值类型也必须带const
    }
private:
    int m_a[20];//真正数组（存数据）
    int m_size;//保存已存数据的个数
};



//以上代码模块库
//..............................
//以下代码模拟用户
int main(void){
    Stack s;
    for(int i = 0; i < 20; i++){
        s.push(100+i);
    }
    cout << "压栈后s容器中的数据个数：" << s.size() << endl;
    
    //s[5];// s.operator[](5) ---操作符函数的返回值如果是int，可以读取数据，但是无法赋值（ s[5] = 888;）
           // ｜匿名内存｜s[5] = 888; 888存入到了匿名内存中，并没有存入s[5]中，如果想让存入s[5],操作符函数的返回值必须int&引用，这样一来，s[5]就是s[5]的别名，888才存入容器s[5]中。
    //cout << s[5] << endl;
    
    //数组真正使用的方式
    s[5] = 888;// s.operator[](5) -- 非常容器的元素 是 非常左值 //非常对象 既可以选择非常版本，也可以选择常版本 //调用常函数操作符函数
    for(int i = 0; i < 20; i++){
        cout << s[i] << " ";
    }
    cout << endl;
    cout << "读取数据后s容器中的数据个数：" << s.size() << endl;
    
    const Stack cs = s; //常容器的元素 是 常左值  //常对象只能选择常版本函数
    cs[5] = 9999; // cs.operator[](5)=9999;  应该让编译器报readonly的错误,才是正确的。 //调用非常版本操作符函数

        /*
        int a[20]; // 非常容器
        a[5] = 8888; // 非常左值

        const int ca[20]; // 常容器
        ca[5] = 9999; // error-只读错误， 常左值
        */

        /*
        for( int i=0; i<20; i++ ) {
            cout << s.pop() << ' ';
        }
        cout << endl;
        cout << "读取数据后s容器中数据的个数: " << s.size() << endl;
        */
    return 0;
}

#endif


