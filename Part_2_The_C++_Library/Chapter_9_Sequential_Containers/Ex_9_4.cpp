/************************************************************************************************************************************************************
 * @file Ex_9.4.cpp
 * @brief Exercise 9.4: Write a function that takes a pair of iterators to a vector<int> and an int value. Look for that value
 *        in the range and return a bool indicating whether it was found.
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

bool search(std::vector<int>::const_iterator cbegin, std::vector<int>::const_iterator cend, int value){
    while(cbegin != cend){
        if(*cbegin++ == value){
            return 1;
        }
    }

    return 0;
}

int main(){
    std::vector<int> ivec{1,3,5,7,9,11,13,15};
    std::cout << "5 found : " << search(ivec.cbegin(), ivec.cend(), 5) << std::endl;
    std::cout << "8 found : " << search(ivec.cbegin(), ivec.cend(), 8) << std::endl;
    std::cout << "7 found : " << search(ivec.cbegin() + 3, ivec.end(), 7) << std::endl;
    return 0;
}