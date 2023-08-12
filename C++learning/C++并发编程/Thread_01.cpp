//
//  Thread_01.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/7/24.
//


#include <iostream>
#include <thread>
using namespace std;
void myprint(){
    cout << "22222222" << endl;
    cout << "3333333333" << endl;
}

int main(void){
    
    thread mytobj(myprint);
    mytobj.join();
    
    cout << "chain" << endl;
    return 0;
}
