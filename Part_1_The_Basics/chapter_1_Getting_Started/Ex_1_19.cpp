/************************************************************************************************************************************************************
 * @file Ex_1_19.cpp
 * @brief Exercise 1.19: Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of 
 * numbers so that it handles input in which the first number is smaller than the second
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
    
    if (n1 >= n2) {  // execute the block if n1 is greater than or equal to n2
        std::cout << "error : first number should be smaller than second number to print the range" << std::endl;
        return -1;   //  -1 indicates failure
    }
    
    std::cout << "Numbers in the range " << n1 << " to " << n2 << " inclusive : \n"; 
    while (n1 <= n2) {  // repeat the block untill n1 is greater than n2
        std::cout << n1 << " ";
        ++n1;    //  increments n1 by 1
    }

    std::cout << std::endl;
}