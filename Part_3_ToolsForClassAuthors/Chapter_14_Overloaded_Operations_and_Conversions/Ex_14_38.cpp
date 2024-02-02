/************************************************************************************************************************************************************
 * @file Ex_14_38.cpp
 * @brief Exercise 14.38: Write a class that tests whether the length of a given string matches a given bound. Use that 
 * object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Offlength{
    private :
        std::string::size_type min, max;
    public :
        Offlength(size_t min_, size_t max_) : min(min_), max(max_) {}
        bool operator()(const std::string &str){
            if((str.size() >= min) && (str.size() <= max))
                return 1;
            return 0;    
        }
};

int main(){
    std::ifstream ifile("test.txt");
    std::string word;
    if(!ifile){
        std::cerr << "unable to open file" << std::endl;
        return -1;
    }

    Offlength check(3,5);

    size_t count = 0;
    while(ifile >> word){
       if(check(word)){
            std::cout << word << " ";
            ++count;
       }    
    }

    std::cout << "There are totaly " << count << " words in the input file" << std::endl;
}