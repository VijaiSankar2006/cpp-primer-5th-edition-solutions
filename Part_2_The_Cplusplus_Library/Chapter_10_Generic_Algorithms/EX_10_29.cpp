/************************************************************************************************************************************************************
 * @file EX_10_29.cpp
 * @brief Exercise 10.29: Write a program using stream iterators to read a text file into a vector of strings
 * @date 2024-01-06
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>

int main(){
    // opens a file name "text.txt"
    std::ifstream filestrm("text.txt");
    if(!filestrm){
        std::cout << "unabel to open file" ;
        return -1;
    }

    //  defines a istream_iterator to iterate through filestream, eof is default initialised to indicate end of stream
    std::istream_iterator<std::string> striter(filestrm), eof;
    
    // initialises a vector with istream_iterator and eof indicating the range
    std::vector<std::string> strvec(striter, eof);

    // defines a ostream_iterator to print a word in a newline to the cout
    std::ostream_iterator<std::string> outiter(std::cout , "\n");
    for(auto s : strvec){
        *outiter++ = s ;
    }

    return 0;
}