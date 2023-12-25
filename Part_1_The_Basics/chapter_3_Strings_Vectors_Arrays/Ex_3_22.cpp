/*  Exercise 3.22: Revise the loop that printed the first paragraph in text to instead change the elements in text that 
correspond to the first paragraph to all uppercase.After you’ve updated text, print its contents.   */

#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> text{"This is the paragraph for the ",
                                  "program to work. "
                                  "the author has asked us to print ",
                                  "each word of the first paragraph in uppercase ",
                                  "since we are yet to learn about files, we will ",
                                  "be using a vector initialised as per the exercise ",
                                  "requirements.",
                                  "",
                                  "The empty string represents a paragraph break",
                                  "so if the program will print only up to the word \"requirements\"."};
    
    for( auto beg = text.begin(); beg != text.end() &&  !beg->empty(); ++beg ){
        for( auto it = beg->begin(); it != beg->end(); ++it ){
            *it = toupper(*it);     // if it is space, toupper won't do anything just returns space
        } 
    }

    for( auto beg = text.cbegin(); beg != text.cend(); ++beg){
        if( beg->empty() ){
            std::cout << "\n\t\t";
        }    
        std::cout << *beg ;
    }

    return 0;

    return 0;
}