/************************************************************************************************************************************************************
 * @file Ex_11_16.cpp
 * @brief Exercise 11.16: Using a map iterator write an expression that assigns a value to an element.
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>

int main(){
    std::map<int, std::vector<int>> i_ivec{{23, {2,3}},{32, {3,2}}};
    auto iter = i_ivec.begin();
    iter->second.push_back(5);
    std::cout << iter->first << " {";
    for(auto n : iter->second){
        std::cout << " " << n; 
    }
    std::cout << "}" << std::endl;
    
}