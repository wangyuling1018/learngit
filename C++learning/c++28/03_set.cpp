//
//  03_set.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

//集合底层使用红黑树，具有关联容器的基本特征：有序的（升序），键唯一
/*集合
 1.没有值 只有键的映射
 2.与向量等基本容器相比，最大的优势就是 排重
 3.定义形式：set<T> 集合对象；
 4.头文件：set
 */
#if 0
#include<iostream>
#include<set>
using namespace std;
//集合--set
int main(){
    set<int> s;
    s.insert(2);
    s.insert(8);
    s.insert(1);
    s.insert(5);
    s.insert(8);
    s.insert(7);
    s.insert(9);
    s.insert(8);
    s.insert(7);
    s.insert(9);
    cout << "元素数：" << s.size() << endl;
    for(int i : s)
        cout << i << ' ';
    cout << endl;
    return 0;
}
#endif
