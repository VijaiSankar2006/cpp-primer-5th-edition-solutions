/************************************************************************************************************************************************************
 * @file debug.cpp
 * @brief debug function template that prints the value and address of an object.
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#ifndef DEBUG_CPP
#define DEBUG_CPP

#include <iostream>

void debug(char &ch);

void debug(const char *ch);

template <typename T>
void debug(const T &obj) {
    std::cout << &obj << " : " << obj << std::endl;
}

template <typename T>  //  template overload to print details of the obj pointed by ptr as primary template prints address of pointer and address it points not the value of the object
void debug(T *p) {
    std::cout << p << " : " << *p << std::endl;
}

#endif

