/************************************************************************************************************************************************************
 * @file Ex_9_41.cpp
 * @brief Exercise 9.41: Write a program that initializes a string from a vector<char>.
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

int main(){
    std::vector<char> cvec{'H','e','l','l','o',' ','W','o','r','l','d'};
    std::string s(cvec.cbegin(), cvec.cend());
    std::cout << s << std::endl;

    return 0;
}
