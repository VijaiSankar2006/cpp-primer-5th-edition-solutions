/************************************************************************************************************************************************************
 * @file Ex_1_24.cpp
 * @brief Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBN s. The
 * records for each ISBN should be grouped together.
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item sum, item;

    std::cout << "Enter a set of transactions : " << std::endl;
    if (std::cin >> sum) {  // checks the first transaction successfully read
        while (std::cin >> item) {   //  keep executing the block untill unable to read a transaction
            if (sum.isbn() == item.isbn()) {   //  checks whether previous and current transaction are same
                sum += item;    //  if same adds the transaction to the group 
            } else {        //  if not same writes the transactions grouped so for
                std::cout << "sum is " << sum << std::endl;
                sum = item;        
            }
        }
        std::cout << "sum is " << sum << std::endl;
    }

    return 0;
}