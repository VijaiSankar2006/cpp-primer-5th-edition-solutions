/************************************************************************************************************************************************************
 * @file Ex_12_16.cpp
 * @brief Exercise 12.16: Compilers don’t always give easy-to-understand error messages if we attempt to copy or assign a 
 * unique_ptr. Write a program that contains these errors to see how your compiler diagnoses them.
 * @date 2024-01-16
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>

int main(){
    std::unique_ptr<int> u_ptr1(std::make_unique<int>(341));
    std::cout << "u_ptr1 : " << *u_ptr1 << std::endl;
    std::unique_ptr<int> u_ptr2(u_ptr1);      //    use of deleted function [ unique_ptr(const unique_ptr&) = delete; ]
    std::unique_ptr<int> u_ptr3;
    u_ptr3 = u_ptr1;    //  use of deleted function [ unique_ptr& operator=(const unique_ptr&) = delete; ]
    return 0;
}

