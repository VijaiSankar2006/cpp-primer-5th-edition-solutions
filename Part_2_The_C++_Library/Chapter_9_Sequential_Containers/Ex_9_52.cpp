/************************************************************************************************************************************************************
 * @file Ex_9_52.cpp
 * @brief Exercise 9.52: Use a stack to process parenthesized expressions. When you see an open parenthesis, note that it was
 *        seen. When you see a close parenthesis after an open parenthesis, pop elements down to and including the open parenthesis
 *        off the stack. push a value onto the stack to indicate that a parenthesized expression was replaced.
 * @date 2024-01-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

//  Currently this program only capable of processing one expression in (), no subexpressions and no expression with out ().
#include <iostream>
#include <stack>
#include <string>
#include <vector>

void getExpression(std::stack<std::string> &cont);

int main(){
    std::stack<std::string> expr;
    getExpression(expr);
    
    std::string val;
    bool open = false;
    double res = 0;
    double num2 = 0;
    while(!expr.empty()){
        val = expr.top();
        expr.pop();
        if(val == "("){
            open = true;
            val = expr.top();
            expr.pop();
            res = stod(val);
        }else if(val == ")"){
            open = false;
            expr.push(std::to_string(res));
            if(expr.size() == 1){
                std::cout << "The result is : " << res << std::endl;
                return 0;
            }
        }else {
            char operand = val[0];
            val = expr.top();
            expr.pop();
            num2 = stod(val);
            switch(operand){
                case '+' : res += num2; break;
                case '-' : res -= num2; break;
                case '/' : res /= num2; break;
                case '*' : res *= num2; break;
            }
        }
    }

    

    return 0;
}

void getExpression(std::stack<std::string> &cont){
    std::stack<std::string> tempstack;
    std::vector<std::string> vec;
    std::cout << "Enter the expression : " << std::endl;
    std::string str;
    while(std::cin >> str){
        vec.push_back(str);
    } 

    for(auto riter = vec.crbegin(); riter != vec.crend(); ++riter){
        cont.push(*riter);
        tempstack.push(*riter);
    }

    std::cout << "the stack is : " << std::endl;
    while(!tempstack.empty()){
        std::cout << tempstack.top() << " ";
        tempstack.pop();
    }

    return;
}
