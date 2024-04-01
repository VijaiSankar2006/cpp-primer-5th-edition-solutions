/************************************************************************************************************************************************************
 * @file Ex_10_36.cpp
 * @brief Exercise 10.36: Use find to find the last element in a list of ints with value 0.
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> ivec{10,2,0,56,7,8,0,3,2,10,0,7,8};

    auto iter = std::find(ivec.crbegin(), ivec.crend(), 0);
    std::cout << "size of list : " << ivec.size() << std::endl;
    std::cout << "found 0 at " << ivec.crend() - iter - 1 << "th position from first" << std::endl;  // -1 is required as crend is one before the first, which will be counted as 0th ele
    std::cout << iter - ivec.crbegin() << "th position from reverse" << std::endl;

    return 0;

}