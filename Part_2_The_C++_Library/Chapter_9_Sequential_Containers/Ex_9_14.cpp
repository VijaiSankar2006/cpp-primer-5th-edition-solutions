/************************************************************************************************************************************************************
 * @file Ex_9_14.cpp
 * @brief Exercise 9.14: Write a program to assign the elements from a list of char* pointers to C-style character strings
 *        to a vector of strings.
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <list>
#include <vector>

int main(){
    std::list<const char *> cstrlst{"one","two","three","four","five"};
    std::vector<std::string> strvec;
    
    strvec.assign(cstrlst.cbegin(), cstrlst.cend());
    for( auto s : strvec){
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0; 
}