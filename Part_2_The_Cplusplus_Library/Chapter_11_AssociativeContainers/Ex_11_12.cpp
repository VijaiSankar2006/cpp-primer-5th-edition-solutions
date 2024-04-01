/************************************************************************************************************************************************************
 * @file Ex_11_12.cpp
 * @brief Exercise 11.12: Write a program to read a sequence of strings and ints, storing each into a pair. Store the pairs in
 * a vector.
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <utility>


int main(){
    std::vector<std::pair<std::string, int>> agevec;
    std::cout << "Enter the name and age : ";
    std::string name;
    int age;
    while(std::cin >> name >> age){
        agevec.push_back({name, age});
    }

    std::cout << "\nthis is the list of people with age : " << std::endl;
    for(auto p : agevec){
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}