/************************************************************************************************************************************************************
 * @file Ex_11_32.cpp
 * @brief Exercise 11.32: Using the multimap from the previous exercise, write a program to print the list of authors
 *        and their works alphabetically.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <set>

int main(){    
    std::multimap<std::string, std::string> authors;
    std::cout << "Enter the list of authors and titles : " << std::endl;
    std::string name, title;
    while(std::cin >> name >> title){
        authors.insert({name, title});
    }
    
    std::cout << "\nlist of authors and their works : " << std::endl;
    
    auto iter = authors.cbegin();
    while(iter != authors.cend()){      //  iterates through the map
        size_t count = authors.count(iter->first);  // count() returns number of elements with same author name as the first
        std::set<std::string> tset;
        std::cout << "\n" << iter->first << std::endl;
        while(count){       // loop adds all the titles with the same author in to a set 
            tset.insert(iter->second);
            --count;
            ++iter;
        }   
        for(auto t : tset){     // set containes titles of a author in sorted order
            std::cout << " " << t << " ";
        } 
    }

    return 0;
}