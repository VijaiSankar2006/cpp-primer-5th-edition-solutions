/************************************************************************************************************************************************************
 * @file Ex_10_1.cpp
 * @brief Exercise 10.1: The algorithm header defines a function named count that, like find, takes a pair of iterators and a 
 *        value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the 
 *        count of how many elements have a given value.
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::cout << "Enter a value to count : ";
    int srch_val;
    std::cin >> srch_val;

    std::vector<int> ivec;
    std::cout << "Enter the set of numbers : \n";
    int n;
    while(std::cin >> n){
        ivec.push_back(n);
    }

    int count = std::count(ivec.cbegin(), ivec.cend(), srch_val);
    std::cout << std::endl;
    std::cout << srch_val << " appears " << count << " times in the set" << std::endl;

    return 0;
}