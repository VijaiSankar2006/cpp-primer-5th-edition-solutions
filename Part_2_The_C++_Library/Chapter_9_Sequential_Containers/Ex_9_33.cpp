/************************************************************************************************************************************************************
 * @file Ex_9_33.cpp
 * @brief Exercise 9.33: In the final example in this section what would happen if we did not assign the result of insert to
 *        begin? Write a program that omits this assignment to see if your expectation was correct.
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    auto begin = v.begin();

    while(begin != v.end()) {
        std::cout << *begin << std::endl;
        ++begin; 
        v.insert(begin, 42);                //  invalidates iterators after the insertion point, so the code is undefined
        ++begin; 
    }

    return 0;
}    

