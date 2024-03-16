/************************************************************************************************************************************************************
 * @file Ex_1_10.cpp
 * @brief Exercise 1.10: In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--)
 * that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main() {
    int i = 10;

    while (i >= 0) {     //  execute the block until i is lesser than 0
        std::cout << i << " ";
        --i;       //  i = i - 1
    }

    std::cout << std::endl;
}