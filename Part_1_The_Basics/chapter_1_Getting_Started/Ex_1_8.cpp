/************************************************************************************************************************************************************
 * @file Ex_1_8.cpp
 * @brief Exercise 1.8: Indicate which, if any, of the following output statements are legal:
 * After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.
 *************************************************************************************************************************************************************/

#include <iostream>
int main() {
    std::cout << "/*";               //  ok : anything with in double quotes is considered to be string literal
    std::cout << "*/";               //  ok : same as above   
    std::cout << /* "*/" */;         //  error : requires double quote at the end, a character after / is escape character, so ; doesn't terminate; 
    std::cout << /* "*/" /* "/*" */; //  ok : on correction of above statement, this statement is absolutely legal
} 


// fix
// std::cout << /* "*/" */"; 
