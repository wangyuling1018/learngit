//
//  03_stack.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

//栈的用处：进行检查，撤销操作等
/*
 表达式的小括号匹配检查：
 1.如果输入左括号时，入栈
 2.如果输入右括号时，检查栈顶是否为左括号，是左括号--出栈，不是左括号--提示错误，停止
 3.当输入结束时，再次检查栈顶，如果栈顶为左括号，缺少右括号，报错
 */
#if 0
#include<iostream>
#include<stack>
using namespace std;

int main(){
    char c;
    stack<char> s;
    do{
        cin >> c;
        if(c == '(')//入栈
            s.push(c);
        else if(c == ')'){
            if(!s.empty() && s.top() == '(')
                s.pop();//出栈
            else{
                cerr << "缺少左括号" << endl;
                return 0;
            }
        }
                
    }while(c != '@');
    
    //3.当输入结束时，再次检查栈顶，如果栈顶为左括号，缺少右括号，报错
    if(s.empty()){
        cout << "表达式输入正确" << endl;
    }else{
        cerr << "缺少右括号" << endl;
    }
    
    
    return 0;
}
#endif
