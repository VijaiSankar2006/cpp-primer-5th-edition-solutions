/************************************************************************************************************************************************************
 * @file Ex_9_38.cpp
 * @brief Exercise 9.38: Write a program to explore how vectors grow in the library you use.
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec;
    std::cout << "size : " << ivec.size() << "  capacity : " << ivec.capacity() << std::endl;

    for(auto i = 0; i < 50 ; ++i){
        ivec.push_back(0);
        std::cout << "size : " << ivec.size() << "  capacity : " << ivec.capacity() << std::endl;

    }

    return 0;
}

//  vector's capacity gets doubled whenever we added a new element beyond its size.