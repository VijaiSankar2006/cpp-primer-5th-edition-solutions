/************************************************************************************************************************************************************
 * @file Ex_9_29.cpp
 * @brief Exercise 9.29: Given that vec holds 25 elements, what does vec.resize(100) do? 
 *        What if we next wrote vec.resize(10)?
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

void print(std::vector<int> &ivec){
    for( auto n : ivec){
        std::cout << n << " ";
    }
}
int main(){
    std::vector<int> ivec(25,4);
    print(ivec);
    std::cout << std::endl;
    ivec.resize(100);           //  adds 75 elements with value initialised to 0
    print(ivec);
    std::cout << std::endl;
    ivec.resize(10);            //  erases 90 elements 
    print(ivec);
    return 0;
}