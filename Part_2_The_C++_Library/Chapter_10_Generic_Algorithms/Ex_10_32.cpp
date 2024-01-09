/************************************************************************************************************************************************************
 * @file Ex_10_33.cpp
 * @brief Exercise 10.32: Rewrite the bookstore problem from § 1.6 (p. 24) using a vector to hold the transactions and various
 *        algorithms to do the processing. Use sort with your compareIsbn function from § 10.3.1 (p. 387) to arrange the 
 *        transactions in order, and then use find and accumulate to do the sum.
 * @date 2024-01-06
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>

#include "Sales_item.h"
#include <iostream>
#include <iterator>
int main()
{
    std::istream_iterator<Sales_item> iter(std::cin), end;   //  iter reads transactions from cin
    std::ostream_iterator<Sales_item> out(std::cout, "\n");  //  out writes transactions to cout

    Sales_item total;
    total = *iter++;    // reads next transaction and returns old iter to deference first transaction read
    if (iter != end) {
        Sales_item trans;
        while ( iter != end) {
            trans = *iter++;   //   increments iter to read next transaction and returns the old iter to dereference previous read transaction
            if (total.isbn() == trans.isbn())
                total += trans;
             else
            {
                *out++ = total ;        //  *out/ out++ does nothing, it is just writen to mimic other iter operations
                total = trans;
            }
        }
        *out++ = total;     // writes total to cout 
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
