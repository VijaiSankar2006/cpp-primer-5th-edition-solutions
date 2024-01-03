/************************************************************************************************************************************************************
 * @file Ex_9_13.cpp
 * @brief Exercise 9.13: How would you initialize a vector<double> from a list<int>? From a vector<int>? Write code to check
 *        your answers
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>

int main(){
    std::list<int> ilst{1,2,3,4,5,6};
    std::vector<int> ivec{9,8,7,6,5};

    // since container type is different we have to initialise using range
    std::vector<double> dvec1(ilst.cbegin(), ilst.cend());  
    
    // since element type is different we have to initialise using range
    std::vector<double> dvec2(ivec.cbegin(), ivec.cend());

    for(auto beg = dvec1.cbegin(); beg != dvec1.cend(); ++beg){
        std::cout << *beg << " ";
    }

    for(auto beg = dvec2.cbegin(); beg != dvec2.cend(); ++beg){
        std::cout << *beg << " ";
    }

    return 0;
}