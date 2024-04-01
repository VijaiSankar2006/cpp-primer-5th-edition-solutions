/************************************************************************************************************************************************************
 * @file Ex_9_5.cpp
 * @brief Exercise 9.5: Rewrite the previous program to return an iterator to the requested element. Note that the program must
 *        handle the case where the element is not found.
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

auto search(std::vector<int>::const_iterator cbegin, std::vector<int>::const_iterator cend, int value) -> decltype(cbegin){
    while(cbegin != cend){
        if(*cbegin == value){
            return cbegin;
        }
        ++cbegin;
    }

    return cend;
}

int main(){
    std::vector<int> ivec{1,3,5,7,9,11,13,15};
    if(search(ivec.cbegin(), ivec.cend(), 5) != ivec.cend()){
        std::cout << "5 found" << std::endl;
    }else{
        std::cout << "not found" << std::endl;
    }

    if(search(ivec.cbegin(), ivec.cend(), 8) != ivec.cend()){
        std::cout << "8 found" << std::endl;
    }else{
        std::cout << "8 not found" << std::endl;
    } 
    if(search(ivec.cbegin() + 3, ivec.end(), 7) != ivec.cend()){
        std::cout << "7 found" << std::endl;
    }else{
        std::cout << "7 not found" << std::endl;
    }
    return 0;
}