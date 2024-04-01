/************************************************************************************************************************************************************
 * @file Ex_10_21.cpp
 * @brief Exercise 10.21: Write a lambda that captures a local int variable and decrements that variable until it reaches 0. 
 *        Once the variable is 0 additional calls should no longer decrement the variable. The lambda should return a bool that
 *        indicates whether the captured variable is 0.
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>

int main(){
    int n = 10;

    // on declaring lamda mutable, we can change the 'captured' value inside, but it doen't affect the variable outside
    auto f = [n]()mutable { if(n-- == 0) return true ; else return false;};

    while(f() == false);

    std::cout << "out of while \n" 
                "n = " << n << std::endl;
    
    return 0;
}