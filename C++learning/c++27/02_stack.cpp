//
//  02_stack.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

/*
 适配器容器：
 栈： 后进先出
        底层容器缺省值为deque，也可以使用vector/list/自定义容器

 队列：先进先出
           底层容器缺省值为deque，也可以使用list
           但是不能使用vector，vector没有提供pop_front函数
 优先队列:  优者先出 (默认大者为优)
                   底层容器缺省值为vector, 也可以使用deque
                   但是不能使用list    --  -- 没有随机迭代器（排序时使用）
                  比较器类型缺省为less<T>，大者为优。也可以使用greater<T>，小者为优
 */
/*栈
 定义形式
    stack<元素类型，[底层容易类型]>堆栈对象 (构造实参表)
 底层容器
    vector/deque(默认)/list/自己实现的容器作为栈的底层容器
 成员函数
    push ---> push_back //push内部调用了底层容器的push_back
    pop ----> pop_back //pop内部调用了底层容器的pop_back
    top ----> back     //top内部调用了底层容器的back
    size----> size     //size内部调用了底层容器的size
    empty---> empty    //empty内部调用了底层容器的empty
 栈的底层实现
    template<class T,class Sequence=deque<T> >class stack{
    public:
        void push(const T& data){ c.push_back(data); }
        void pop(){ c.pop_back(); }
        ......
    private:
        Sequence c;
    };
 实例化
    stack<int> s; 或 stack<int,vector<int> > s; 或 stack<int,list<int> > s;
 
 */


#if 0
#include<iostream>
#include<stack>
#include<vector>
#include<deque>
#include<list>
using namespace std;
//栈
int main(){
    //stack<int> s;
    //stack<int,vector<int> > s; //第二个参数是类类型，是用一个模板参数实例化后得到的一个类
    //stack<int,list<int> > s;
    stack<int,deque<int> > s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    while(!s.empty()){
        cout << s.top() << endl;//取栈顶元素
        s.pop();//删除栈顶元素
    }
    
    return 0;
}
#endif

