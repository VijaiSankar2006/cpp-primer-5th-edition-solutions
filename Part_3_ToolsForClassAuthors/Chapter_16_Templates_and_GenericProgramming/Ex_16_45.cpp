/************************************************************************************************************************************************************
 * @file Ex_16_45.cpp
 * @brief Exercise 16.45: Given the following template, explain what happens if we call g on a literal value such as 42.
 * What if we call g on a variable of type int? 
 * template <typename T> void g(T&& val) { vector<T> v; }
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * g(42)  //  T is int, void g(int &&val) {vector<int> v; } is instantiated
 * g(i)   // illegal : T is int &, void g(int &val) {vector<int &> v; } is instantiated, but we cannot have vector or array of references
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

template <typename T>
void g(T &&val) { std::vector<T> v; }

int main() {
    int i;
    g(i);   //  call is in error, as we cannot have vector of references
}