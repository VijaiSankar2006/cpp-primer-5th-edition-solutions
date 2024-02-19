/************************************************************************************************************************************************************
 * @file Ex_16_4.cpp
 * @brief Exercise 16.4: Write a template that acts like the library find algorithm. The function will need two template
 * type parameters, one to represent the function’s iterator parameters and the other for the type of the value. Use
 * your function to find a given value in a vector<int> and in a list<string>
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename T, typename P>
inline T find(T iter1, T iter2, const P &sought) {
    while (iter1 != iter2) {
        if (*iter1 == sought) return iter1; 
        ++iter1;  
    }
    return iter1;
}

int main() {
    std::vector<int> ivec{1,2,4,5,6};
    std::list<std::string> slst{"alpha","beta","delta"};

    auto iter1 = find(ivec.begin(), ivec.end(), 4);
    if (iter1 == ivec.end()) {
        std::cout << "the value is not found" << std::endl;
    } else {
        std::cout << "the value is found : " << *iter1 << std::endl;
    }

    auto iter2 = find(slst.begin(), slst.end(), "gamma");
    if (iter2 == slst.end()) {
        std::cout << "the value is not found" << std::endl;
    } else {
        std::cout << "the value is found : " << *iter2 << std::endl;
    }

    return 0;
}