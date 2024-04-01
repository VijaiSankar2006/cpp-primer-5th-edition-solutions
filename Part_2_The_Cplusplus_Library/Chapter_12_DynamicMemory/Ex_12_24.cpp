/************************************************************************************************************************************************************
 * @file Ex_12_24.cpp
 * @brief Exercise 12.24: Write a program that reads a string from the standard input into a dynamically allocated character 
 * array. Describe how your program handles varying size inputs. Test your program by giving it a string of data that is longer
 * than the array size you’ve allocated.
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <cstring>

int main(){

    char *chptr = new char[5];
    std::cout << "Enter the string : " << std::endl;
    char ch;
    char *iter = chptr;
    while(std::cin >> ch){
        *iter++ = ch;
    }
    *iter = '\0';      // null value to mark the end of the string
    std::cout << std::endl;
    std::cout << chptr << std::endl;
}

//   works in g++-12 by writing in out of bounds (ie) beyond the memory allocated and not every time works like the sameN