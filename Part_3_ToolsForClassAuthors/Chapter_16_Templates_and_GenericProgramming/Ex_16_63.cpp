/************************************************************************************************************************************************************
 * @file Ex_16_63.cpp
 * @brief Exercise 16.63: Define a function template to count the number of occurrences of a given value in a vector.
 * Test your program by passing it a vector of doubles, a vector of ints, and a vector of strings
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

template <typename T>
size_t count(const std::vector<T> &tvec, const T &val) {
    size_t cnt = 0;
    for(auto beg = tvec.begin(); beg != tvec.end(); ++beg) {
        if (*beg == val) {
            ++cnt;
        }
    }

    return cnt;
}

int main() {
    std::vector<int> ivec{2,4,6,2,7,8,2,4,7,4,8};
    std::cout << count(ivec, 4) << std::endl;
    std::cout << "==============================" << std::endl;

    std::vector<double> dvec{2.4,6.2,2.4,6.2,2.5,2.4,2.4,7.8,9,2.4};
    std::cout << count(dvec, 2.4) << std::endl;
    std::cout << "=================================" << std::endl;

    std::vector<std::string> svec{"alpha", "beta", "alpha", "gamma"};
    std::cout << count(svec, std::string("alpha")) << std::endl;
   
}