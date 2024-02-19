/************************************************************************************************************************************************************
 * @file Ex_16_39.cpp
 * @brief Exercise 16.39: Use an explicit template argument to make it sensible to pass two string literals to the 
 * original version of compare from § 16.1.1 (p. 652).
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

template <typename T>
bool compare(const T &v1, const T &v2) {
    return std::size(v1) < std::size(v2);
};

int main() {
    std::cout << compare<std::string>("bye bye", "hello") << std::endl;
}

/************************************************************************************************************************************************************
 * Passing string as explicit parameter, will result in to normal argument conversion from arguments in the call to the 
 * string type, so we can pass string literals of two different sizes at the same time..
 *      compare<string>(const string &v1, const string &v2) will be instantiated.
 * 
 *************************************************************************************************************************************************************/