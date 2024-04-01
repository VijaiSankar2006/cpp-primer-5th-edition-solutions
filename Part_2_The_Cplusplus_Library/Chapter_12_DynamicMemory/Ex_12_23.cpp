/************************************************************************************************************************************************************
 * @file Ex_12_23.cpp
 * @brief Exercise 12.23: Write a program to concatenate two string literals, putting the result in a dynamically allocated 
 * array of char. Write a program to concatenate two library strings that have the same value as the literals used in the 
 * first program.
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <new>
#include <memory>
#include <cstring>

int main(){

    // using string_literals and dynamic array
    const char *first = "hello ", *second = "world";
    char *res = new char[sizeof(first) + sizeof(second)];     // sizeof() returns the size of the string literal
    std::strcpy(res,first);
    std::strcat(res, second);
    std::cout << res << std::endl;
    delete [] res;

    // using strings 
    std::string str1("hello "), str2("world");
    std::string r_str = str1 + str2;
    std::cout << r_str << std::endl;
    
    return 0;
}