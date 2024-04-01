/************************************************************************************************************************************************************
 * @file Ex_10_2.cpp
 * @brief Exercise 10.2: Repeat the previous program, but read values into a list of strings.
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

int main(){
    std::cout << "Enter a word to search : ";
    std::string srch_word;
    std::cin >> srch_word;

    std::cout << "Enter a list of words : ";
    std::list<std::string> strlst;
    std::string word;
    while( std::cin >> word){
        strlst.push_back(word);
    }

    int count = std::count(strlst.cbegin(), strlst.cend(), srch_word);
    std::cout << "\n[" << srch_word << "] appears " << count << " times in the list." << std::endl;

    return 0;
}