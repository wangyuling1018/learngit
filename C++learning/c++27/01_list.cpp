//
//  01_list.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

/*
 线型容器：
 向量：尾端高效增删     push_back/pop_back
      可以使用下标 -- 随机迭代器
 双端队列：首尾两端都可以实现高效增删     push_front/pop_front       push_back/pop_back
         可以使用下标   -- 随机迭代器
 列表：  任意位置都可以实现高效增删     push_front/pop_front       push_back/pop_back
        不可以使用下标  -- 没有随机迭代器
 */
/*列表
 常用函数
    front()         获取首元素     /      push_back()   添加尾元素
    back()          获取尾元素     /      pop_back()    删除尾元素
    insert()        插入元素       /      empty()        判空
    erase()         删除元素       /      clear()        清空
    push_front()    添加首元素     /      size()         向量维护元素个数
    pop_front()     删除首元素     /      resize()       设置向量元素个数
 
 唯一化
    void unique(void);将连续重复出现的元素唯一化
 排序（都是全局排序）注意sort是成员函数
    void sort(void)；通过<比大小
    template<class LESS>void sort(LESS less);通过比较器比大小
 拆分：将 参数列表 中的部分或全部元素剪切到 调用列表 中
    template<class IT>void splice(IT pos,list& lst);
    template<class IT>void splice(IT pos,list& lst,IT del);
    template<class IT>void splice(IT pos,list& lst,IT begin,IT end);
 
 */

#if 0
#include<iostream>
#include<list>
using namespace std;
//列表--list
void print(string const& str,list<int>& l){
    cout << str << endl;
    for(int i : l)
        cout << i << " ";
    cout << endl << "---------------------------" << endl;
    
}

int main(){
    list<int> ls;
    for(int i = 0; i < 5; i++)
        ls.push_front(10+i);
    for(int i = 0; i < 5; i++)
        ls.push_back(10+i);
    print("添加首尾节点元素后：",ls);
    
    //唯一化后
    ls.unique();
    print("唯一化后：",ls);
    
    ls.remove(11);
    print("删除所有的11后：",ls);
    
    //排序
    //ls.sort(); //从小到大
    ls.sort(greater<int>());//从大到小
    print("排序后：",ls);
    
    
    list<int> lst{1000,2000,3000};//使用初始化表 添加元素
    print("添加元素：",lst);
    
    //拆分
    //ls.splice(++ls.begin(), lst);//将lst中所有元素 全部剪切到ls的指定位置
    //ls.splice(++ls.begin(),lst,lst.begin()); //将lst中的第一个元素 剪切到ls的指定位置
    ls.splice(++ls.begin(),lst,++lst.begin(),--lst.end());//将lst从第二个 与 倒数第一个之间的元素 剪切到ls的指定位置 ，[第二个，倒数第一个)，左闭右开区间
    print("ls：",ls);
    print("lst：",lst);
    
    
    
    return 0;
}
#endif
