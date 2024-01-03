/************************************************************************************************************************************************************
 * @file Ex_9_16.cpp
 * @brief Exercise 9.16: Repeat the previous program, but compare elements in a list<int> to a vector<int>
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>

int main(){
    std::vector<int> ivec{1,1,2,3,5,8};
    std::list<int> ilst{1,2,3,5,7,11};

    // std::cout << "ivec < ilst : " << (ivec < ilst ? "true" : "false") << std::endl;  // didn't work as the types are different
    // so initialise another container type to the same type

    std::cout << "ivec > ilst : " << (ivec > std::vector<int>(ilst.cbegin(), ilst.cend()) ? "true" : "false") << std::endl;

    return 0;

}