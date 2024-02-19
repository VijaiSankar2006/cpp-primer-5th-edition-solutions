/************************************************************************************************************************************************************
 * @file Ex_16_37.cpp
 * @brief Exercise 16.37: The library max function has two function parameters and returns the larger of its arguments.
 * This function has one template type parameter. Could you call max passing it an int and a double? If so, how? If 
 * not, why not?
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int i = 56;
    double d = 56.1;

    std::cout << max<double>(i, d) << std::endl;

    return 0;
}

/************************************************************************************************************************************************************
 * It is passible to call max with two different types by calling with explicit template argument as double. So when max is
 * called with explicit template argument double, then normal argument conversions happens, so int will be promoted to double.
 * double max<double>(double, double) will be instantiated.
 * 
 *************************************************************************************************************************************************************/