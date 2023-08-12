//
//  06_netstalias.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/17.
//
/*
 名字空间嵌套  netstalias.cpp
     - 内层标识符与外层同名标识符为隐藏关系
     - 嵌套的名字空间需要逐层分解
 名字空间别名  netstalias.cpp
     - 可通过名字空间别名简化书写
     namespace ns_four = ns1::ns2::ns3::ns4;
 */

#if 0
//名字空间嵌套
#include <iostream>
using namespace std;

namespace ns1{
    int g_value = 100;
    namespace ns2{
        int g_value = 200;
        namespace ns3{
            int g_value = 300;
            namespace ns4{
                int g_value = 400;

            }
        }
    }
}

int main( void ){
    //cout << ns1::ns2::ns3::ns4::g_value << endl;
    namespace ns_four = ns1::ns2::ns3::ns4;
    cout << ns_four::g_value <<endl;
    return  0;
}
//运行结果：400
#endif
