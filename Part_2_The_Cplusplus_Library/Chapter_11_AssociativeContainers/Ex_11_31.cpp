/************************************************************************************************************************************************************
 * @file Ex_11_31.cpp
 * @brief Exercise 11.31: Write a program that defines a multimap of authors and their works. Use find to find an element
 *        in the multimap and erase that element. Be sure your program works correctly if the element you look for is not
 *        in the map.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::multimap<std::string, std::string> authors;
    std::cout << "Enter the list of authors and titles : " << std::endl;
    std::string name, title;
    while(std::cin >> name >> title){
        authors.insert({name, title});
    }
    std::cin.clear();

    std::cout << "Enter the name to search : " << std::endl;
    std::cin >> name;
    std::map<std::string, std::string>::iterator p;
    while((p = authors.find(name)) != authors.end()){    // if the element is not present then returns off-the-end
        authors.erase(p);    
    }

    std::cout << "\nlist of authors and their works : " << std::endl;
    for( auto ele : authors){
        std::cout << ele.first << " " << ele.second << std::endl;
    }

    return 0;
}