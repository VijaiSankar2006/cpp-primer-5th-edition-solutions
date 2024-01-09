/************************************************************************************************************************************************************
 * @file Ex_10.35.cpp
 * @brief Exercise 10.35: Now print the elements in reverse order using ordinary iterators.
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9,10};

    auto last = ivec.cend() - 1;
    auto before_first = ivec.cbegin() - 1;
    while( last != before_first){
        std::cout << *last-- <<  " ";
    }

    return 0;
}