/*  Exercise 5.21: Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks only for duplicated words 
 *  that start with an uppercase letter.*/

#include <iostream>
#include <string>

int main(){
    std::string prevWord, currWord;
    bool found = false;
    std::cout << "Enter a sequence of words : ";
    std::cin >> prevWord;
    while( std::cin >> currWord ){
        if(!isupper(currWord[0])){
            continue;
        }
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