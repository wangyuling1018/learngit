//
//  template2_lib.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/7/17.
//

/*
 template method ：模板方法，即样板
 结构化软件设计流程：1-》2-〉3-》4-〉5
     Library开发人员：
        （1）开发1、3、5三个步骤
     Appliaction开发人员：
        （1）开发2、4两个步骤
        （2）程序主流程        //方法1到5的调用流程
     调用关系：
        Appliaction开发人员 调用 Library开发人员 （向上调用） --- 早绑定
 
 面向对象软件设计流程：
     Library开发人员：
        （1）开发1、3、5三个步骤
        （2）程序主流程        //方法1到5的调用流程
     Appliaction开发人员：   //应用开发人员就比较省事了
        （1）开发2、4两个步骤
     调用关系：
        Library开发人员 调用 Appliaction开发人员 （向下调用） --- 晚绑定（早的东西调用晚的东西）
 
 模式定义：
     定义一个操作中的算法的骨架(稳定)，而将一些步骤延迟（变化)到子类中。
     Template Method使得子类中可以不改变（可复用)一个算法的结构即可重定义(override 重写）该算法的某些特定步骤。
    //假设必须有一个稳定点，才能用模板方法，否则不能模板方法。
    //假设run函数中所有方法都不稳定 或 都稳定，用设计模式没有意义
    //设计模式最大的作用就是在变化和稳定之间寻找隔离点，然后来分离他们，从而管理变化。
    

 */

#if 0
#include <iostream>
//程序库开发人员
class Library{
public:
    //稳定 template method //
    void run(){//程序主流程， run函数就是样板，稳定中有变化。假设run稳定，才能用模板方法，否则不能用。
        step1();
        
        if(step2()){ //支持变化 ==》虚函数的多态调用
            step3();
        }
        
        for(int i = 0; i < 4; i++)
            step4(); //支持变化 ==》虚函数的多态调用
        
        step5();
    }
    virtual ~Library(){}
protected:
    void step1(){  //稳定
        //...
    }
    void step3(){   //稳定
        //...
    }
    void step5(){   //稳定
        //...
    }
    virtual bool step2() = 0; //变化  //框架开发人员无法重写，留给子类进行重写
    virtual void step4() = 0; //变化  //框架开发人员无法重写，留给子类进行重写
};

#endif
