/************************************************************************************************************************************************************
 * @file Ex_9_27.cpp    
 * @brief Exercise 9.27: Write a program to find and remove the odd-valued elements in a forward_list<int>
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <forward_list>

int main(){
    std::forward_list<int> iflst{1,2,3,4,5,6,7,9,7,9,2,0,4,17,6,8,10,11};
    std::forward_list<int>::iterator prev = iflst.before_begin();
    decltype(prev) curr = iflst.begin();
    while( curr != iflst.end()){
        if( *curr % 2){
           curr = iflst.erase_after(prev);
        }else{
            prev = curr;
            ++curr;
        }
    }

    for( auto n : iflst){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}