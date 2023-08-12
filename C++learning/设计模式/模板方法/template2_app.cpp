//
//  template2_app.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/7/17.
//

#if 0
#include <iostream>
#include "templ"
#include <ApplicationServices/ApplicationServices.h>

//应用程序开发人员
class Application:public Library{
protected:
    virtual bool step2(){
        //.... 子类重写实现
    }
    virtual void step4(){
        //.... 子类重写实现
    }
};


int main(){
    Library* pLib = new Application(); //多态
    lib->run();
    
    delete pLib;
}

#endif

