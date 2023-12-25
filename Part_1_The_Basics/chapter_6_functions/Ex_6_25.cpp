/*  Exercise 6.25: Write a main function that takes two arguments. Concatenate the sup-
plied arguments and print the resulting string. */

#include <iostream>

int main(int argc, char **argv){
    for(int i = 0; i < argc; ++i){
        std::cout << *(argv + i) << std::endl;
    }

    std::cout << "the concatenated string : "<< std::endl;
    std::string result = *(argv + 1) + std::string(*(argv + 2));
    std::cout << result << std::endl;

    return 0;
}
