/************************************************************************************************************************************************************
 * @file Ex_1_2.cpp
 * @brief Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that
 * the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.
 * @date 2024-03-13

 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

int main() {
    return -1;  // -1 is converted to 255 (ie) the system treats the failure indicator to contain only a positive value
}