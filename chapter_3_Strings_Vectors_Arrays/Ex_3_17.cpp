/*  Exercise 3.17: Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process
 *  the vector and change each word to uppercase.Print the transformed elements, eight words to a line  */

#include <iostream>
#include <vector>
#include <string>

int main(){

    std::cout << "Enter the list of words : \n";
    std::vector<std::string> strvec;
    std::string word;
    while( std::cin >> word ){
        strvec.push_back(word);
    }

    std::cout << "\nthe list has " << strvec.size() << " elements.\n";
    size_t counter = 0;
    const size_t MAX_WORDS = 8;
    for( auto str : strvec){            //  range for assigns next element in strvec to str everytime it iterates
        for( auto &ch : str ){          //  this range for assigns reference of one single character at a time from the word assigned to str
            ch = toupper(ch);           //  writes the uppercase of the character
        }
        if( counter == 8 ){             //  if we have printed eight words it will add a newline
            counter = 0;
            std::cout << std::endl;
        }
        std::cout << str << " ";
        ++counter;
    }
    std::cout << std::endl;
    
    return 0;
}