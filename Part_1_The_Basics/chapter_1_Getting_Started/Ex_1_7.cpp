/************************************************************************************************************************************************************
 * @file Ex_1_7.cpp
 * @brief Exercise 1.7: Compile a program that has incorrectly nested comments.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main() {
    // /* multiline comment is nested   //  error : every thing after // is commented out
    with in single line comment */ // error : this line is not commented out

    /*  // single line comment is nested   // ok 
    with in multiline comment */
}