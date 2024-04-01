/************************************************************************************************************************************************************
 * @file Ex_9_20.cpp
 * @brief Exercise 9.20: Write a program to copy elements from a list<int> into two deques.The even-valued elements should go
 *        into one deque and the odd ones into the other.
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <list>
#include <deque>

int main(){
    std::list<int> numbers{1,2,3,4,5,6,7,8,9,10};
    std::deque<int> odd, even;

    for( auto n : numbers ){
        n % 2 ? odd.push_back(n) : even.push_back(n);
    }

    std::cout << "odd elements are :\n";
    for( std::deque<int>::const_iterator cbeg = odd.cbegin(); cbeg != odd.cend(); ++cbeg){
        std::cout << *cbeg << " ";
    }
    std::cout << std::endl;

    std::cout << "even elements are : \n";
    for( auto cbeg = even.cbegin(); cbeg != even.cend(); ++cbeg){
        std::cout << *cbeg << " ";
    }
    std::cout << std::endl;

    return 0;

}