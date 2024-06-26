/************************************************************************************************************************************************************
 * @file Ex_14_44.cpp
 * @brief Exercise 14.44: Write your own version of a simple desk calculator that can handle binary operations.
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include <iostream>
#include <functional>
#include <utility>
#include <map>

class Multiply{
    public :
        int operator()(int a, int b){
            return a * b;
        }
};

class Greater{
    public :
        int operator()(int a, int b){
            return a > b ? a : b;
        }
};

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int main(){
    auto smaller = [](int a, int b){ return a < b ? a : b;};
    auto divide = [](int a, int b){ return a / b ;};

    std::map<std::string, std::function<int(int, int)>> binops = { {"+", add},
                                                                 {"-", sub},
                                                                 {"*", Multiply()},
                                                                 {"/", divide},
                                                                 {"%", [](int a, int b){ return a % b; }},
                                                                 {">", Greater()},
                                                                 {"<", smaller}, 
                                                                 {"=", std::equal_to<int>()}, 
                                                                 {"!=", std::not_equal_to<int>()} };
                                                                  
    int val1 = 10, val2 = 3;
    std::cout << "add[" << val1 << "," << val2 << "] : " << binops["+"](val1, val2) << std::endl;
    std::cout << "sub[" << val1 << "," << val2 << "] : " << binops["-"](val1, val2) << std::endl;
    std::cout << "mul[" << val1 << "," << val2 << "] : " << binops["*"](val1, val2) << std::endl;
    std::cout << "div[" << val1 << "," << val2 << "] : " << binops["/"](val1, val2) << std::endl;
    std::cout << "mod[" << val1 << "," << val2 << "] : " << binops["%"](val1, val2) << std::endl;
    std::cout << "max[" << val1 << "," << val2 << "] : " << binops[">"](val1, val2) << std::endl;
    std::cout << "min[" << val1 << "," << val2 << "] : " << binops["<"](val1, val2) << std::endl;
    std::cout << "equal[" << val1 << "," << val2 << "] : " << binops["="](val1, val2) << std::endl;
    std::cout << "not_equal[" << val1 << "," << val2 << "] : " << binops["!="](val1, val2) << std::endl;

    return 0;
}

