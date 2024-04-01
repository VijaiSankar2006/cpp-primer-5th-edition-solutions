/************************************************************************************************************************************************************
 * @file Ex_10_6.cpp
 * @brief Exercise 10.6: Using fill_n, write a program to set a sequence of int values to 0.
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(){
    std::vector<int> ivec1{1,2,3,4,5,6,7,8};    
    std::fill_n(ivec1.begin(), 4, 23);      // normal iterator is passed to write 4 existing elements with value 23

    std::vector<int> ivec2;         
    std::fill_n(std::back_inserter(ivec2), 10, 43); // insert_iterator is passed to add 10 elements with val 43

    for( auto n : ivec1){
        std::cout << n << " ";
    }

    std::cout << std::endl;
    for( auto n : ivec2){
        std::cout << n << " ";
    }

    return 0;
}