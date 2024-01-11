/************************************************************************************************************************************************************
 * @file Ex_11_18.cpp
 * @brief Exercise 11.18: Write the type of map_it from the loop on page 430 without using auto or decltype
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>

int main(){
    std::map<std::string, size_t> wordCount;
    std::map<std::string, size_t>::iterator beg = wordCount.begin(), end = wordCount.end();
    if(beg == end){
        std::cout << "map is empty";
    }else{
        std::cerr << "didn't work as excpected";
        return -1;
    }


    return 0;
}