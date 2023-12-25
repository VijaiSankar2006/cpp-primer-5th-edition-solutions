/*  Exercise 3.5: Write a program to read strings from the standard input, concatenating what is read into one large string.
    Print the concatenated string. Next, change the program to separate adjacent input strings by a space. */

#include <iostream>
#include <string>

int main(){
    std::string word;
    std::string final_string;
    bool first = true;
    std::cout << "Enter a list of words : \n";

    //  reads word by word and concatenates in to one large string
    while( std::cin >> word ){
      // final_string += word;     //  concatenates the string that has been read

      // concatenates the adjacent strings whith a space
        if( !first ){
            word = ' ' + word;
        }else{
            first = false;
        }    

        final_string += word;
    }

    std::cout << final_string << std::endl;

    return 0;
}