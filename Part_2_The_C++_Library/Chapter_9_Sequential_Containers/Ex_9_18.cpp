/************************************************************************************************************************************************************
 * @file Ex_9_18.cpp
 * @brief Exercise 9.18: Write a program to read a sequence of strings from the standard input into a deque. Use iterators to
 *        write a loop to print the elements in the deque.
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <deque>

int main(){
    
    std::deque<std::string> strdq;
    std::cout << "Enter the list of words : \n";
    std::string word;
    while(std::cin >> word){
        strdq.push_back(word);
    }

    for(auto iter = strdq.cbegin(); iter != strdq.cend(); ++iter){
        std::cout << *iter << " ";
    }

    return 0;
}