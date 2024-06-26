/************************************************************************************************************************************************************
 * @file Ex_11_23.cpp
 * @brief Exercise 11.23: Rewrite the map that stored vectors of children’s names with a key that is the family last 
 *        name for the exercises in § 11.2.1 (p. 424) to use a multimap.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <map>
#include <iostream>
#include <vector>

int main(){
    std::multimap<std::string, std::vector<std::string>> families;
    std::string last_name, first_name;
    while(std::cin >> last_name >> first_name){
        families.insert({last_name,{first_name}});
    }

    for(auto f : families){
        std::cout << "family name : " << f.first << "\n";
        for(auto s : f.second){
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}