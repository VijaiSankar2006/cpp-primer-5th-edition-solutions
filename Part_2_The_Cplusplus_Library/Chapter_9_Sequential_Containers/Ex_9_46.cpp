/************************************************************************************************************************************************************
 * @file Ex_9_46.cpp
 * @brief Exercise 9.46: Rewrite the previous exercise using a position and length to manage the strings. This time use only 
 *        the insert function
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

std::string addTitle(const std::string &s, const std::string &prefix, const std::string &suffix = std::string()){
    std::string res(s);
    std::string space(" ");
    if(!prefix.empty()){
        res.insert(0,prefix + space);      
    }

    if(!suffix.empty()){
        res.insert(res.size(), space + suffix);
    }

    return res;
}

int main(){
    std::string name1("Sherlock"), name2("Tony"), name3("Charles");
    std::vector<std::string> prefix{"Mr","Mrs"};
    std::vector<std::string> suffix{"Jr","III"}; 
    std::cout << addTitle(name1, prefix[1], suffix[1]) << std::endl;
    std::cout << addTitle(name2, "", suffix[0]) << std::endl;
    std::cout << addTitle(name3, prefix[0], "") << std::endl;

}