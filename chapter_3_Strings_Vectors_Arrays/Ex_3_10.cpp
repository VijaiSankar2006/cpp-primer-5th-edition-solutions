/*  Exercise 3.10: Write a program that reads a string of characters including punctuation and writes what was read but 
    with the punctuation removed.   */

#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::string word;
    std::cout << "Enter the word to remove punctuations : ";
    std::cin >> word;

    //  'range for' assigns a reference to every charater in the sequence, reference will be deleted and initialised again for every iteration
    for( auto &ch : word){
        if( ispunct(ch) ){     //   ispunct(ch), returns 'true' if the character is punctuation or else 'false', defined in 'cctype' header 
            ch = ' ';
        }
    }

    std::cout << "after removing punctuations " << word << std::endl;

    return 0;
}
