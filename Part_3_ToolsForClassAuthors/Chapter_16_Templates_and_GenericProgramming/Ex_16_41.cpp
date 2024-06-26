/************************************************************************************************************************************************************
 * @file Ex_16_41.cpp
 * @brief Exercise 16.41: Write a version of sum with a return type that is guaranteed to be large enough to hold the
 * result of the addition.
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <type_traits>

template <typename T>
auto sum(T lhs, T rhs)-> decltype(lhs + rhs) {  //  didn't work as expected, lhs + rhs returns -2, decltype(-2) is the type of return, which in return gives -2 
   return (lhs + rhs) ;                         //  as return val, so unable to declare a return type bigh enough to hold the result                                    
}

int main() {
    unsigned i = -1;
    int lhs = i/2, rhs = i/2;
    auto res = sum(lhs,rhs);
    std::cout << res << " ";
    std::cout << lhs << " " << rhs << std::endl;

}
    