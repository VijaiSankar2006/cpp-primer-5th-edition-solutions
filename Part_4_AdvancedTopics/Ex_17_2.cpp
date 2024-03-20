/************************************************************************************************************************************************************
 * @file Ex_17_2.cpp
 * @brief Exercise 17.2: Define a tuple that holds a string, a vector<string>, and a pair<string, int>
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <tuple>
#include <vector>

int main() {
    std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> employees("john", {"no 56", "porur", "chennai"}, {"profit", 50});
    std::cout << std::get<0>(employees) << " ";
    
    for(size_t i = 0; i != std::get<1>(employees).size(); ++i) {
        std::cout << std::get<1>(employees)[i] << " ";
    }

    std::cout << std::get<2>(employees).first << " " << std::get<2>(employees).second << std::endl;
    
    return 0;
}