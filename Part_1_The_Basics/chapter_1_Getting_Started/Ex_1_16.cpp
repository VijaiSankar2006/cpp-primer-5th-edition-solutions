/************************************************************************************************************************************************************
 * @file Ex_1_16.cpp
 * @brief Exercise 1.16: Write your own version of a program that prints the sum of a set of integers read from cin
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main() {
    std::cout << "Enter a set of intgers : \n" << std::endl;
    int num;
    int sum = 0;

    while (std::cin >> num) {   //  repeat the block until unable to read a integer from std input
        sum += num;     //  sum = sum + num
    }

    std::cout << std::endl;
    std::cout << "sum : " << sum << std::endl;

    return 0;
}

