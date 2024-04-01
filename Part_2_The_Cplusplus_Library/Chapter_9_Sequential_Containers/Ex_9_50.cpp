/************************************************************************************************************************************************************
 * @file Ex_9_50.cpp
 * @brief Exercise 9.50: Write a program to process a vector<string>s whose elements represent integral values. Produce the sum
 *        of all the elements in that vector. Change the program so that it sums of strings that represent floating-point values.
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> intStrVec{"87.43", "first-1s","out5+6x", "89", "88", "s10e-19"};
    int num;
    float fval;

    //  code to find and convert string representing integrals in the vector
    for( auto iter = intStrVec.cbegin(); iter != intStrVec.cend(); ++iter){
        std::string s(*iter);
        num = stoi(s.substr(s.find_first_of("+-0123456789")));
        std::cout << num << std::endl;    
    }

    //  code to find and convert string representing real numbers in the vector
    for( auto iter = intStrVec.cbegin(); iter != intStrVec.cend(); ++iter){
        std::string s(*iter);
        fval = stof(s.substr(s.find_first_of("+-.Ee0123456789")));
        std::cout << fval << std::endl;    
    }
    return 0;
}