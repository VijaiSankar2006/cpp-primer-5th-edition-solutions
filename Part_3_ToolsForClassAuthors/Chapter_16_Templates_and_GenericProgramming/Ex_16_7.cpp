/************************************************************************************************************************************************************
 * @file Ex_16_7.cpp
 * @brief Exercise 16.7: Write a constexpr template that returns the size of a given array.
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

template <typename T, unsigned N>
inline constexpr size_t size(const T (&arr)[N]) {
    return N;
}

int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,4,3,2,1};
    std::cout << size(nums) << std::endl;

    int digits[size(nums)] = {67,78,90};
    std::cout << size(digits) << std::endl;

    for (auto n : digits) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}