/*  Exercise 3.6: Use a range for to change all the characters in a string to X*/

#include <iostream>
#include <string>

int main(){
    std::string word;
    std::cout << "Enter the word : ";
    std::cin >> word;
    
    std::cout << "before conversion : " << word << std::endl;
    //  range for changes every character in the word to 'X';
    for( auto &ch : word ){
        ch = 'X';
    }

    std::cout << "after converting : " << word << std::endl;
}