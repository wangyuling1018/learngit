//
//  08_binaryIO2.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

//seekg:设置读指针的位置
//seekp：设置写指针的位置

#if 0
#include <iostream>
#include <fstream>
using namespace std;

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    ofstream ofs("./wyl",ios::out);
    if( !ofs ){
        cerr << "ofs流对象状态错误----打开文件失败" << endl;
    }
    
    ifstream ifs("./getline",ios::in);
    if( !ifs ){
        cerr << "ifs流对象状态错误----打开文件失败" << endl;
    }
    long long int  size = ifs.tellg();
    char buf[size] = {0};
    ifs.seekg(0,ios::beg);
    ifs.read(buf, size);
    ofs.write(buf, size);
    ifs.close();
    ofs.close();
    return 0;
}

#endif
