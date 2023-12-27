/************************************************************************************************************************************************************
 * @file Ex_8_4.cpp
 * @brief Exercise 8.4: Write a function to open a file for input and read its contents into a vector of strings, storing
 *        each line as a separate element in the vector.
 * @date 2023-12-25
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){
    std::ifstream ifile("notes.md");

    if(!ifile){                                 // checks if file open is unsuccessfull
        std::cerr << "Unable to open file ";
        return -1;
    }

    std::vector<std::string> linevec;
    std::string line;
    // reads line by line and stores as a seperate element in the vector
    while(getline(ifile, line)){
        linevec.push_back(line);
    }
    ifile.close();

    std::ofstream ofile("notescopy.md");
    if(!ofile){                             //  checks is file open is unsuccessfull
        std::cerr << "unable to open file";
        return -1;
    }

    //  prints the contents of vector, each element in a seperate line
    for( auto iter = linevec.begin(); iter != linevec.end(); ++iter){
        ofile << *iter << "\n";
    }

    return 0;
     
}