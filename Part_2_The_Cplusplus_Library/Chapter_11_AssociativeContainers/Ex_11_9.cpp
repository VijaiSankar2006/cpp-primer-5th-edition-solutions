/************************************************************************************************************************************************************
 * @file Ex_11_9.cpp
 * @brief Exercise 11.9: Define a map that associates words with a list of line numbers on which the word might occur.
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>


int main(){
    std::map<std::string, std::vector<size_t>> wordsIndex;
    std::ifstream ifile("text.txt");
    if(!ifile){
        std::cerr << "Unable to open file " << std::endl;
        return -1;
    }

    std::string line;
    std::istringstream linestrm;
    size_t line_no = 0;
    std::string word;
    while(getline(ifile, line)){
        ++line_no;
        linestrm.str(line);
        while(linestrm >> word){
            wordsIndex[word].push_back(line_no);
        }
        linestrm.clear();
    }

    for(auto &p : wordsIndex){
        std::cout << p.first << " occurs in lines : ";
        for(auto n : p.second){
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}