/************************************************************************************************************************************************************
 * @file Ex_10_27.cpp
 * @brief Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library defines function named unique_copy that takes
 *        a third iterator denoting a destination into which to copy the unique elements. Write a program that uses unique_copy
 *        to copy the unique elements from a vector into an initially empty list.
 * @date 2024-01-06
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>

void print(const std::vector<std::string> &vec){
    for( auto s : vec ){
        std::cout << s << " ";
    }
}

int main(){
    std::vector<std::string> ivec;
    std::cout << "Enter the list of words : ";
    std::string word;
    while(std::cin >> word){
        ivec.push_back(word);
    }

    std::sort(ivec.begin(), ivec.end());
    std::vector<std::string> ubcopy, uicopy;
    std::deque<std::string> ufcopy;
    std::unique_copy(ivec.begin(), ivec.end(), std::back_inserter(ubcopy));   // back_inserter() returns a iterator which calls push_back() to add elements
    std::unique_copy(ivec.begin(), ivec.end(), std::front_inserter(ufcopy));  // front_inserter() returns a iterator which calls push_front() to add elements
    std::unique_copy(ivec.begin(), ivec.end(), std::inserter(uicopy, uicopy.begin()));  // inserter() returns a iterator which calls insert() to add an element before the iter

    std::cout << "\nList of unique words inserted via back_inserter : " << std::endl;
    print(ubcopy);
    std::cout << std::endl;

    std::cout << "\nList of unique words inserted via front_inserter : " << std::endl;
    for( auto s : ufcopy){
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::cout << "\nList of unique words inserted via inserter : " << std::endl;
    print(uicopy);
    std::cout << std::endl;

    return 0;
}