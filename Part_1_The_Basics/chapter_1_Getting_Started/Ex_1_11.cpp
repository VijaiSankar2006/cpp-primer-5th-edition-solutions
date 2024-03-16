/************************************************************************************************************************************************************
 * @file Ex_1_11.cpp
 * @brief Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range 
 * specified by those two integers.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main() {
    std::cout << "Enter two numbers : " << std::endl;
    int n1, n2;
    std::cin >> n1 >> n2;   //  reads two integers from input stream and writes to n1 and n2
    
    std::cout << "Numbers in the range " << n1 << " to " << n2 << " inclusive : \n"; 
    while (n1 <= n2) {  // repeat the block untill n1 is greater than n2
        std::cout << n1 << " ";
        ++n1;    //  increments n1 by 1
    }

    std::cout << std::endl;
}