/************************************************************************************************************************************************************
 * @file Ex_14_36.cpp
 * @brief Exercise 14.36: Use the class from the previous exercise to read the standard input, storing each line as an 
 * element in a vector.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "Ex_14_35.cpp"

int main(){
    std::vector<std::string> svec;
    std::cout << "Enter a list of sentences : " << std::endl;
    PrintString line;
    std::string str;
    while((str = line()).size()){
        svec.push_back(str);
    }

    std::cout << std::endl << "###################################" << std::endl;
    for( auto s : svec){
        std::cout << s << std::endl;
    }
    std::cout << "##############################" << std::endl;
}