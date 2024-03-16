/************************************************************************************************************************************************************
 * @file Ex_1_23.cpp
 * @brief Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for
 * each ISBN .
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item, curr;
    size_t count = 0;

    std::cout << "Enter a set of transactions : " << std::endl;
    if (std::cin >> item) {  // checks the first transaction read is successful
        ++count;
        while (std::cin >> curr) {   //  keep executing the block untill unable to read
            if (item.isbn() == curr.isbn()) {   //  checks whether previous and current transaction are same
                ++count;    //  if same increases the count by 1 
            } else {        //  if not same writes the previous transaction and its count
                std::cout << item << " ocurrs " << count << " times" << std::endl;
                item = curr;        
                count = 1;      //  count is reset to 1
            }
        }
        std::cout << item << " occurs " << count << " times" << std::endl;
    }

    return 0;
}
