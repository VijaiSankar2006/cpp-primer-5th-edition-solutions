/*  Exercise 3.4: Write a program to read two strings and report whether the strings are equal. If not, report which of 
    the two is larger. Now, change the program to report whether the strings have the same length, and if not, report 
    which is longer. */

#include <iostream>
#include <string>

int main(){
    std::cout << "Enter two words to compare : \n";
    std::string word1, word2;
    std::cin >> word1 >> word2;

    //  compares the words based on dictionary order
    if( word1 == word2 ){
        std::cout << word1 << " and " << word2 << " are equal";
    }else if( word1 < word2 ){
        std::cout << word2 << " is smaller than " << word1; 
    }else{
        std::cout << word1 << " is larger than " << word2;
    }
    std::cout << std::endl;

    //  compares the words based on length
    if( word1.size() == word2.size() ){
        std::cout << word1 << " and " << word2 << " are equal in length";
    }else if( word1.size() < word2.size() ){
        std::cout << word2 << " is longer than " << word1;
    }else{
        std::cout << word1 << " is longer than " << word2; 
    }
    std::cout << std::endl;

    return 0;
}