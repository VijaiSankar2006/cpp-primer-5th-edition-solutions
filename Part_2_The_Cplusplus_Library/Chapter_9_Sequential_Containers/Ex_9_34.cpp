/************************************************************************************************************************************************************
 * @file Ex_9_34.cpp
 * @brief Exercise 9.34: Assuming vi is a container of ints that includes even and odd values,predict the behavior of the 
 *        following loop. After you’ve analyzed this loop, write a program to test whether your expectations were correct.
            iter = vi.begin();
            while (iter != vi.end())
            if (*iter % 2)
                iter = vi.insert(iter, *iter);
            ++iter;
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
    auto iter = ivec.begin();
    while( iter != ivec.end()){
        std::cout << *iter << " ";
        if(*iter % 2)
            iter = ivec.insert( iter, *iter);           //  inserts before curr, so iter should be incremented twice
        iter ++;                                         //  and an else should be added to process if the num is even or else loop while skip elements
                                                        //  and endup dereferencing out of bounds
    }

    for(auto n : ivec){
        std::cout << n << " ";
    }

    return 0;
}