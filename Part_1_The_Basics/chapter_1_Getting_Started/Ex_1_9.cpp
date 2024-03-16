/************************************************************************************************************************************************************
 * @file Ex_1_9.cpp
 * @brief Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to 100.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main() {
    int i = 50;
    int sum = 0;

    while (i <= 100) {   // repeat the block untill i is greater than 100
        sum += i;       // sum = sum + i
        ++i;            // i = i + 1
    }
    std::cout << "The sum of numbers 50 to 100 inclusive is " << sum << std::endl;

    return 0;
}