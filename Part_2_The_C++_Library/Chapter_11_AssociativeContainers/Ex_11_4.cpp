/************************************************************************************************************************************************************
 * @file Ex_11_4.cpp
 * @brief Exercise 11.4: Extend your program to ignore case and punctuation. For example, “example.” “example,” and “Example” 
 * should all increment the same counter.
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <fstream>

int main(){
    std::map<std::string, size_t> wordCount;
    std::set<char> punctuations{',','.','!','?',';','"','\''};
    
    std::ifstream ifile("text.txt");
    if(!ifile){
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    }
    std::string word;
    while(ifile >> word){
        if(punctuations.find(word.back()) != punctuations.end()){
            word.pop_back();
        }
        if(punctuations.find(word.back()) != punctuations.end()){
            word.pop_back();
        }
        if(punctuations.find(word.front()) != punctuations.end()){
            word.erase(word.begin());
        }
        ++wordCount[word];
    }

    for( auto &p : wordCount){
        std::cout << p.first << " occurs " << p.second << " times" << std::endl;
    }

    return 0;
}