/************************************************************************************************************************************************************
 * @file Ex_1_21.cpp
 * @brief Exercise 1.21: Write a program that reads two Sales_item objects that have the same ISBN and produces their
 * sum.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "Sales_item.h"   //  header file of Sales_item
#include <iostream> 
 
int main() {
    Sales_item item1, item2;
    std::cout << "Enter two sales transactions with same ISBN :\n";
    std::cin >> item1 >> item2;

    std::cout << "The sum of the two sales transactions is : \n";
    std::cout << item1 + item2 << std::endl;

    return 0;
}