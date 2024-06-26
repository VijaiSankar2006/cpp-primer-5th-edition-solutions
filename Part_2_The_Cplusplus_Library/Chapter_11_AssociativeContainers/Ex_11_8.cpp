/************************************************************************************************************************************************************
 * @file Ex_11_8.cpp
 * @brief Exercise 11.8: Write a program that stores the excluded words in a vector instead of in a set. What are the advantages
 * to using a set? 
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

int main(){
    std::ifstream ifile("text.txt");
    if(!ifile){
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    }

    std::map<std::string, size_t> word_count;
    std::vector<std::string> excluded{"the","a","is","there","on","an"};
    size_t excluded_count = 0;

    std::cout << "Enter the words : \n";
    std::string word;
    while(ifile >> word ){
        if(std::find(excluded.cbegin(), excluded.cend(), word) == excluded.cend()){
            ++word_count[word];
        }else{
            ++excluded_count;
        }
    }

    for( auto p : word_count){
        std::cout << p.first << " occurs " << p.second << " times" << std::endl;
    }

    std::cout << "excluded count : " << excluded_count << std::endl;

    return 0;
}

/**
 * set is ordered by default, so it provides a quicker search for a key
 * set provides its own find member to search for a key which is less verbose than using a generic algorithm for vector
 * a vector can have duplicate elements, where as in a set keys are unique
*/

