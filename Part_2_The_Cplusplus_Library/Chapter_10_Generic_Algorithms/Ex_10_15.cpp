/************************************************************************************************************************************************************
 * @file Ex_10_15.cpp
 * @brief Exercise 10.15: Write a lambda that captures an int from its enclosing function and takes an int parameter. The 
 *        lambda should return the sum of the captured int and the int parameter.
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main(){
    std::cout << "Enter two numbers : " << std::endl;
    int num1, num2;
    std::cin >> num1 >> num2;

    // lamda that captures an int and takes an int and returns their sum
    auto sum = [num1] (int a) { return num1 + a; };

    std::cout << num1 << " + " << num2 << " = " << sum(num2) << std::endl;

    return 0;
}