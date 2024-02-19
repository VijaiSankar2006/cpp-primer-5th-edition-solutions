/************************************************************************************************************************************************************
 * @file Ex_16_6.cpp
 * @brief Exercise 16.6: How do you think the library begin and end functions that take an array argument work? 
 * Define your own versions of these functions.
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>

template <typename T, unsigned N>
inline const T * begin(const T (&arr) [N]) {
    return arr;
}

template <typename T, unsigned N>
inline const T * end(const T (&arr) [N]) {
    return arr + N;
}

int main() {
    int nums[] = {1,2,3,4,5,9,8,7,6};

    for (auto n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << end(nums) << " - " << begin(nums) << " " << end(nums) - begin(nums) << std::endl;

    for ( auto i = 0; i != (end(nums) - begin(nums)); ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}