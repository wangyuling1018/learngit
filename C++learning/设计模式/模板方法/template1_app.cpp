//
//  template1_app.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/7/17.
//

#if 0
#include <iostream>
#include <ApplicationServices/ApplicationServices.h>

//应用程序开发人员
class Application{
public:
    bool step2(){
        //...
    }
    void step4(){
        //....
    }
};


int main(){
    
    //程序主流程
    Library lib();
    Application app();
    
    lib.step1();
    
    if(app.step2()){
        lib.step2();
    }
    
    for(int i = 0; i < 4; i++)
        app.step4();
    
    lib.step5();
}

#endif
