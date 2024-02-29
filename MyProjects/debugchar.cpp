/************************************************************************************************************************************************************
 * @file debugchar.cpp
 * @brief overloaded definitions of debug
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include <iostream>

void debug(char &ch) {  //  function overload to print address of a char
    std::cout << static_cast<void *>(&ch) << " : " << ch << std::endl;
}

void debug(const char *ch) {  // function overload for const char * as template overload with T *p will be used, and normally cin won't print the address of char and char*
    std::cout << static_cast<void *>(const_cast<char *>(ch)) << " : " << ch << std::endl;
}