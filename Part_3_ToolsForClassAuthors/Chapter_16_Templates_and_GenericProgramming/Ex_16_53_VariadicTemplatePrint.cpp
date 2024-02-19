/************************************************************************************************************************************************************
 * @file Ex_16_53.cpp
 * @brief Exercise 16.53: Write your own version of the print functions and test them by printing one, two, and five
 * arguments, each of which should have different types.
 * @date 2024-02-16
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

/**
 * @brief non-variadic template function that print the last argument, without which variadic template function will recursively instantiate with empty parameter pack
 * @tparam T 
 * @param os 
 * @param const T & val 
 */
template <typename T>
void print(std::ostream &os, const T &val) {
    os << "non-variadic template print() : " << val << std::endl;
}

/************************************************************************************************************************************************************
 * @brief variadic template that can take variying number or types in a call
 * @tparam T 
 * @tparam Args , typename... tells the compiler Args denotes a parater pack
 * @param os 
 * @param val 
 * @param rest, is of type const Args&... , ... tells the compiler rest is a name of parameter pack 
 *************************************************************************************************************************************************************/
template <typename T, typename... Args>
void print(std::ostream &os, const T &val, const Args&... rest) {
    os << "variadic template print() : " << val << std::endl;
    return print(os, rest...);  //  recursive call : 1st argument in rest bounds to T and remaining arguments in rest forms the parameter pack
}

