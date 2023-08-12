//
//  04_queue.cpp
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

/*队列
 定义形式
    queue<元素类型[,底层容器类型]> 队列对象
 底层容器
    deque(默认)/list
    不能使用vector
 成员函数
    push--->push_back
    pop---->pop_front
    back--->back
    front-->front
    size--->size
    empty--->empty
 队列的底层实现
    template<class T,class Sequence=deque<T> >class queue{
    public:
        void push(const T& data){ c.push_back(data); }
        void pop(){ c.pop_front(); }
        ......
    private:
        Sequence c;
    };
实例化
    queue<int> q; 或 queue<int,deque<int> > q; 或 queue<int,list<int> > q;

 */

#if 0
#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<list>
using namespace std;
//队列
int main(){
    //queue<int> s;
    //queue<int,vector<int> > s; //error,队列的底层容器不能使用vector ，因为vector中没有pop_front函数
    //queue<int,list<int> > s;
    queue<int,deque<int> > s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    while(!s.empty()){
        cout << s.front() << endl;//取栈顶元素
        s.pop();//删除栈顶元素 //pop中需要调用pop_front函数
    }
    
    return 0;
    
    
    return 0;
}
#endif
