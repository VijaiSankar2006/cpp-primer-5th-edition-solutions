/*  Exercise 5.19: Write a program that uses a do while loop to repetitively request two strings from the user and report
    which string is less than the other. */

#include <iostream>
#include <string>

int main(){
    do{
        std::cout << " Enter two words to compare : ";
        std::string word1, word2;
        if( std::cin >> word1 >> word2 ){
            if(word1 < word2 ){
                std::cout << "\n" <<  word1 << " is smaller than " << word2;
            }else{
                std::cout << "\n" << word2 << " is smaller than " << word1;
            }
        }
    }while(std::cin);

    return 0;   
}