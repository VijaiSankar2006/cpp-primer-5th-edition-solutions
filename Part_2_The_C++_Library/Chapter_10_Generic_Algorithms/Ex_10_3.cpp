/************************************************************************************************************************************************************
 * @file Ex_10_3.cpp
 * @brief Exercise 10.3: Use accumulate to sum the elements in a vector<int>
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <numeric>
#include <vector>

int main(){
    
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9};
    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << std::endl;

    return 0;
}