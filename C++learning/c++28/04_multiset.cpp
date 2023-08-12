//
//  04_multiset.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

//多重集合底层使用红黑树，具有关联容器的基本特征：有序的（升序）
/*多重集合
 1.没有值 只有键的映射
 2.定义形式：multiset<T> 多重集合对象；
 3.头文件：set
 */
#if 0
#include<iostream>
#include<set>
using namespace std;
//多重集合-multiset
int main(){
    multiset<int> s;
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
