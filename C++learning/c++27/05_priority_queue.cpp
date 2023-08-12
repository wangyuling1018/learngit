//
//  05_priority_queue.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//
/*优先队列
 定义形式:
    priority_queue<元素类型,[底层容器类型】,[比较器类型]> 优先队列对象
 底层容器：
    vector(默认)/deque
    必须支持随机迭代，不能使用list
 注意事项：
    优者先出，默认以大者为优，也可以通过比较器定制（比较器必须是类）
    如果没有“比较器”默认内部使用<运算符
    并不是出队时挑，而是进队时就保证有序
 成员函数:
    push--->push_back
    pop--->pop_back
    top--->front
    empty--->empty
    size---->size
 队列的底层实现:
    template<class T,class Sequence=deque<T> >class priority_queue{
    public:
        void push(const T& data){ c.push_back(data); }
        void pop(){ c.pop_back(); }
        ......
    private:
        Sequence c;
    };
实例化:
 priority_queue<int> q; 或 priority_queue<int,deque<int> > q; 或 priority_queue<int,vector<int> > q;
 
 
 */
#if 0
#include<iostream>
#include<queue> //queue / priority_queue
//#include<vector>
#include<deque>
#include<list>
using namespace std;
//优先队列--priority_queue
int main(){
    //priority_queue<int> s;
   // priority_queue<int,vector<int> > s;
    //priority_queue<int,list<int> > s; //error,优先队列的底层容器不能使用list，因为list不支持随机迭代
    priority_queue<int,deque<int>,greater<int> > s; //greater<int>是类型，greater<int>()加小括号就是对象
    s.push(8);
    s.push(2);
    s.push(12);
    s.push(4);
    s.push(20);
    s.push(3);
    s.push(5);
    s.push(7);
    while(!s.empty()){
        cout << s.top() << endl;//取栈顶元素
        s.pop();//删除栈顶元素 //pop中需要调用pop_front函数
    }
    
    return 0;
}
#endif

