/*  Exercise 5.20: Write a program to read a sequence of strings from the standard input until either the same word 
 *  occurs twice in succession or all the words have been read. Use a while loop to read the text one word at a time. 
 *  Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs
 *  twice in succession, or else print a message saying that no word was repeated. 
 * */

#include <iostream>
#include <string>

int main(){
    std::string prevWord, currWord;
    bool found = false;
    std::cout << "Enter a sequence of words : ";
    std::cin >> prevWord;
    while( std::cin >> currWord ){
        if( prevWord == currWord ){
            found = true;
            break;
        }else{
            prevWord = currWord;
        }
    }

    std::cout << std::endl;
    if(found){
        std::cout << prevWord << " occurs twice"<< std::endl;
    }else{
        std::cout << "no word appears twice" << std::endl;
    }
}