/************************************************************************************************************************************************************
 * @file Ex_16_50.cpp
 * @brief Exercise 16.50: Define the functions from the previous exercise so that they print an identifying message. 
 * Run the code from that exercise. If the calls behave differently from what you expected, make sure you understand 
 * why.
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include <type_traits>
#include <iostream>

/************************************************************************************************************************************************************
 * std::is_const<T>() returns bool indicating whether T is const qualified or not
 * type_id(T).name() returns type of T as a string, but const is a type qualifier not a type so it will be droped by type_id(), 
 * 
 * so use std::is_const<T>() to check for constness 
 *************************************************************************************************************************************************************/
template <typename T> void f(T) {
    std::cout << "void f(T) : T deduced as " << (std::is_const<T>() ? "const " : "") << " " << typeid(T).name() << std::endl;
}

template <typename T> void f(const T*) {
    std::cout << "void f(const T *) : T deduced as " << (std::is_const<T>() ? "const " : "") << " " << typeid(T).name() << std::endl;
}

template <typename T> void g(T) {
    std::cout << "void g(T) : T deduced as " << (std::is_const<T>() ? "const " : "") << " " << typeid(T).name() << std::endl;
}

template <typename T> void g(T*) {
    std::cout << "void g(T *) : T deduced as " << (std::is_const<T>() ? "const " : "") << " " << typeid(T).name() << std::endl;
}

int main() {

    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    std::cout << "g(42) : " ; g(42); 
    std::cout << "g(p)  : " ; g(p); 
    std::cout << "g(ci) : " ; g(ci); 
    std::cout << "g(p2) : " ; g(p2);
    std::cout << "f(42) : " ; f(42); 
    std::cout << "f(p)  : " ; f(p); 
    std::cout << "f(ci) : " ; f(ci); 
    std::cout << "f(p2) : " ; f(p2);
}    