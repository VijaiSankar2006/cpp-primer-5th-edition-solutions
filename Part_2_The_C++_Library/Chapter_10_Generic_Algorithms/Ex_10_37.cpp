/************************************************************************************************************************************************************
 * @file Ex_10_37.cpp
 * @brief Exercise 10.37: Given a vector that has ten elements, copy the elements from positions 3 through 7 in reverse order
 *        to a list.
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>

int main(){
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
    std::list<int> ilst;

    auto rbeg = ivec.crbegin() + 3;
    auto rend = ivec.crbegin() + 8;

    while( rbeg != rend){
        ilst.push_back(*rbeg++);
    }

    for (auto n : ilst) {
        std::cout << n << " ";
    }


    return 0;
}