/************************************************************************************************************************************************************
 * @file Ex_16_5.cpp
 * @brief Exercise 16.5: Write a template version of the print function from § 6.2.4 (p. 217) that takes a reference
 * to an array and can handle arrays of any size and any element type.
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <array>
#include <vector>

template <typename T, unsigned N>
inline void print(const T (&arr)[N]) {
    for (unsigned i = 0; i != N; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    double num[] = {1,2,3,4,5};
    std::string sarr[] = {"alpha","beta", "gamma"};

    print(num);
    print(sarr);
    return 0;
}