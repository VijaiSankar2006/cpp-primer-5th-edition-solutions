/************************************************************************************************************************************************************
 * @file Ex_9_19.cpp
 * @brief Exercise 9.19: Rewrite the program from the previous exercise to use a list. List the changes you needed to make.
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <list>                 

int main(){
    
    std::list<std::string> strlst;
    std::cout << "Enter the list of words : \n";
    std::string word;
    while(std::cin >> word){
        strlst.push_back(word);
    }

    for(auto iter = strlst.cbegin(); iter != strlst.cend(); ++iter){
        std::cout << *iter << " ";
    }

    return 0;
}

/**
 * 1. list header is used 
 * 2. container type declared to be list
*/