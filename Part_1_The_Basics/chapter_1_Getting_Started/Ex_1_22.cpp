/************************************************************************************************************************************************************
 * @file Ex_1_22.cpp
 * @brief Exercise 1.22: Write a program that reads several transactions for the same ISBN . Write the sum of all the
 * transactions that were read.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item, sum;

    std::cout << "Enter a set of sales transacitons for the same ISBN" << std::endl;
    std::cin >> sum;   //  sum should have a transaction in it to add with other transaction   

    while (std::cin >> item) {   //  keep executing the block untill unable to read a transaction
        sum = sum + item;
    }

    std::cout << "The sum of all transactions is : " << sum << std::endl;
    return 0;
}

