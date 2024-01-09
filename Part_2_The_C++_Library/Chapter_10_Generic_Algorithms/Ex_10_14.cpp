/************************************************************************************************************************************************************
 * @file Ex_10_14.cpp
 * @brief Exercise 10.14: Write a lambda that takes two ints and returns their sum.
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main(){
    int num1, num2 ;
    std::cout << "Enter two numbers : ";
    std::cin >> num1 >> num2;

    // lambda that takes two ints and returns their sum
    auto sum = [](int a, int b){ return a + b ;};   
    std::cout << num1 << " + " << num2 << " = " << sum(num1, num2) << std::endl;

    return 0;
}