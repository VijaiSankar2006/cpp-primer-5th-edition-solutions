/*  Exercise 3.2: Write a program to read the standard input a line at a time. Modify your program to read a word at a time.*/

#include <iostream>
#include <string>

int main(){
    std::string line;
    std::cout << "Enter the text : \n";

    /*
    // reads a line one by one from cin and prints untill eof is reached
    while(getline(std::cin, line)){
        std::cout << line << std::endl;
    }  */
    
    // reads word by word from cin and prints untill eof is reached
    std::string word;
    while( std::cin >> word ){
        std::cout << word << " ";         //  ostream is only flushed when cin reads a newline
    }
    
    return 0;
}