/************************************************************************************************************************************************************
 * @file Ex_16_2.cpp
 * @brief Exercise 16.2: Write and test your own versions of the compare functions.
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <functional>
#include <utility>

template <typename T> inline
int compare(const T &v1, const T &v2) {
    //std::cout << "compare(" << v1 << ", " << v2 << ")" << std::endl;
    if (std::less<T>()(v1,v2)) return -1;
    if (std::less<T>()(v2,v1)) return 1;
    return 0;
}

int main() {
    std::cout << compare(45,65) << std::endl;   //  -1
    std::cout << compare(std::string("hello"), std::string("handmaiden")) << std::endl;   //  1
    std::cout << compare(std::vector<int>{1,2,3,4}, std::vector<int>{1,2,3,4}) << std::endl;   //  0

    return 0;
}