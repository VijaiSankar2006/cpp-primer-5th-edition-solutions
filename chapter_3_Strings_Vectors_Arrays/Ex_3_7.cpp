/*  Exercise 3.7: What would happen if you define the loop control variable in the previous exercise as type char? Predict
    the results and then change your program to use a char to see if you were right.    */

#include <iostream>
#include <string>

int main(){
    std::string word;
    std::cout << "Enter the word : ";
    std::cin >> word;
    
    std::cout << "before conversion : " << word << std::endl;
    //  'range for' gets every character in the word to ch;
    for( char ch : word ){  
        ch = 'X';   // if ch is a reference, then we will be able to change the characters in the word; But in this case its
    }               // just plain char type, so it doesn't change anything

    std::cout << "after converting : " << word << std::endl;
}