//
//  03_ifstream.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/2/25.
//

#if 0
#include <iostream>
#include <fstream>
using namespace std;

//C++标准库中 设计的类 ifstream类

// 以上的代码模拟类的设计者(例如:类库、别人设计的类、自己设计的类)
// --------------------------------------
// 以下的代码模拟类的使用者
int main( void ) {
    ifstream ifs1("./file",ios::in);
    if( !ifs1 ){// ! ifs1.operator bool()
        cerr << "ifs1流对象状态错误---打开文件失败" << endl;
    }
    int i; double d; string s1,s2;
    ifs1 >> i >> d >> s1 >> s2;
    if( !ifs1 ){// ! ifs1.operator bool()
        cerr << "ifs1流对象状态错误---读文件失败" << endl;
    }
    cout << i << " " << d << ' ' << s1 << ' ' << s2 << endl;
    ifs1.close();
    
    
    
    ifstream ifs2("./file",ios::ate);
    if( !ifs2 ){// ! ifs2.operator bool()
        cerr << "ifs2流对象状态错误---打开文件失败" << endl;
    }
    //ifs2.seekg(0, ios::beg); //设置文件指针的位置，将文件读指针设置到文件头
    int ii; double dd; string ss1,ss2;
    ifs2 >> ii >> dd >> ss1 >> ss2;
    if( !ifs2 ){// ! ifs2.operator bool()
        cerr << "ifs2流对象状态错误---读文件失败" << endl;
    }
    cout << ii << " " << dd << ' ' << ss1 << ' ' << ss2 << endl;
    ifs1.close();
    
    return 0;
}

#endif
