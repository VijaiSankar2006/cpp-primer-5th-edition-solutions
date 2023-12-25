/*  Exercise 3.15: Repeat the previous program but read strings this time.  */

#include <iostream>
#include <vector>
#include <string>

int main(){

    std::cout << "Enter a list of words : "<< std::endl;
    std::vector<std::string> svec;
    std::string word;
    while( std::cin >> word ){
        svec.push_back(word);
    } 

    std::cout << "List of words entered are : \n";
    for( auto str : svec ){
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}