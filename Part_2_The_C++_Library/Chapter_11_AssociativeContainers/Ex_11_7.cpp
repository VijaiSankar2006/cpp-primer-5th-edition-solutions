/************************************************************************************************************************************************************
 * @file Ex_11_7.cpp
 * @brief Exercise 11.7: Define a map for which the key is the family’s last name and the value is a vector of the children’s
 *        names. Write code to add new families and to add new children to an existing family.
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>

int main(){
    std::map<std::string, std::vector<std::string>> family;  // each element is a pair of string and a vector of strings

    std::string last_name;
    std::string first_name;
    std::cout << "Enter the family details [last_name first_name] : " << std::endl;
    while(std::cin >> last_name){
        std::cin >> first_name;
        family[last_name].push_back(first_name);   //  the value fetched is a vector, so we use vector's push_back() member to add children name
    }

    for( auto p : family){
        std::cout << "family's last name : " << p.first << std::endl;
        for( auto s : p.second){
            std::cout << "\t" << s << std::endl;
        }
    }

    return 0;
}