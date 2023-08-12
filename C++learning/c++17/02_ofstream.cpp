//
//  02_ofstream.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//



#if 0
#include <iostream>
#include <fstream>
using namespace std;

//C++标准库中 设计的类 ofstream类

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    ofstream ofs1("./file",ios::out);
    if(!ofs1){// ! ofs1.operator bool()
        cerr << "ofs1流对象状态错误 ----打开文件失败" << endl;
    }
    ofs1 << 1234 << " " << 355.356 << ' ' << "hello ang" << '\n' << endl;
    if(!ofs1){// ! ofs1.operator bool()
        cerr << "ofs1流对象状态错误 ----写文件失败" << endl;
    }
    ofs1.close();
    
    ofstream ofs2("./file",ios::app);
    if(!ofs2){// ! ofs2.operator bool()
        cerr << "ofs2流对象状态错误 ----打开文件失败" << endl;
    }
    ofs2 << " world" << endl;
    if(!ofs2){// ! ofs2.operator bool()
        cerr << "ofs2流对象状态错误 ----写文件失败" << endl;
    }
    ofs2.close();
    return 0;
}

#endif
