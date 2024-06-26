/************************************************************************************************************************************************************
 * @file Ex_1_13.cpp
 * @brief Exercise 1.13: Rewrite the first two exercises from § 1.4.1 (p. 13) using for loops.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

// Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to 100.
/*
#include <iostream>

int main() {
    int sum = 0;
    for (int i = 50; i <= 100; ++i) {   // initialises i to 50, checks whether i is lesser than or equal to 100, then executes the block and increments i by 1 
                                        // repeats condition cheking, execution of block, incrementation of i untill i is greater than 100.    
        sum += i;       // sum = sum + i 
    }
    std::cout << "The sum of numbers 50 to 100 inclusive is " << sum << std::endl;

    return 0;
}
*/
/* Exercise 1.10: In addition to the ++ operator that adds 1 to its operand, there is a
decrement operator (--) that subtracts 1. Use the decrement operator to write a while
that prints the numbers from ten down to zero. */

#include <iostream>

int main() {

    for (int i = 10; i >= 0; --i) {     //  initialises i to 10, repeats the block untill i is lesser than 0, decrements i by 1
        std::cout << i << " ";
    }

    std::cout << std::endl;
}