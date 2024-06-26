/************************************************************************************************************************************************************
 * @file Ex_8_10.cpp
 * @brief Exercise 8.10: Write a program to store each line from a file in a vector<string>.Now use an istringstream to read
 *        each element from the vector a word at a time.
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(){

    // code to open file
    std::ifstream ifile("notes.md");
    if(!ifile){
        std::cerr << "unable to open file";
        return -1;
    }

    // code to store each line in the file in to seperate element in vector
    std::vector<std::string> linevec;
    std::string line;
    while(getline(ifile, line)){
        linevec.push_back(line);
    }

    //  code to put each element of the vector in to istringstream to extract word by word from the line
    std::istringstream strstrm;
    std::string word;
    for(auto iter = linevec.cbegin(); iter != linevec.cend(); ++iter){
        strstrm.str(*iter);         
        while(strstrm >> word){
            std::cout << word << " ";
        }
        std::cout << std::endl;
        strstrm.clear();            //  as when strstrm hits eof in while, we have to clear the error states to reuse, or else it won't work
    }                               //  either clear the strm bfr reuse or declare the strm obj inside the loop, so it gets destroyed and created every time loop iterates    

    return 0;
}