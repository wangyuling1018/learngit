//
//  07_binaryIO1.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//
//换行，在linux中是\n,在window中是\r\n
//二进制I/O：怎么读的就怎么存
#if 0
#include <iostream>
#include <fstream>
using namespace std;
//C++标准库中国 设计的类 ofstream/ifstream 类
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
    char buf[3] = {0};
    while(1){
        ifs.read(buf, 3);
        if(!ifs){
            //没有读满3个字节
            int len = ifs.gcount();
            //buf[len] = '\0';
            ofs.write(buf, len);
            cout << buf;
            break;
        }else{
            //没有读满3个字节
            //cout << buf;
            ofs.write(buf, 3);
            
        }
    }
    
    ifs.close();
    ofs.close();
    return 0;
}

#endif
