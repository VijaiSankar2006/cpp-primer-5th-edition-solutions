/************************************************************************************************************************************************************
 * @file Ex_10_34.cpp
 * @brief Exercise 10.34: Use reverse_iterators to print a vector in reverse order.
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>

int main(){
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9,10};

    auto riter = ivec.crbegin();        // const reverse  iterator pointing the last element
    while(riter != ivec.crend()){       // const reverse end iterator pointing to one before the first element
        std::cout << *riter++ << " ";   // increment operator moves the riter to the next element in reverse order
    }

    return 0;
}