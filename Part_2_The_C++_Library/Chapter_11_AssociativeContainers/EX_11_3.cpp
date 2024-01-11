/************************************************************************************************************************************************************
 * @file EX_11_3.cpp
 * @brief Exercise 11.3: Write your own version of the word-counting program.
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>

int main(){
    std::map<std::string, size_t> wordCount;
    std::cout << "Enter a list of words : " << std::endl;
    std::string word;
    while(std::cin >> word){
        ++wordCount[word];
    } 

    std::cout << "\nword count is as follows :" << std::endl;
    for(auto &p : wordCount){
        std::cout << p.first << " occurs " << p.second << " times" << std::endl;
    }

    return 0;
}