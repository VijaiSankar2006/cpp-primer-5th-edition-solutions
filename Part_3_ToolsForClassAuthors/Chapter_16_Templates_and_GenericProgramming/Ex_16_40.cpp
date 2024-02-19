/************************************************************************************************************************************************************
 * @file Ex_16_40.cpp
 * @brief Exercise 16.40: Is the following function legal? If not, why not? If it is legal, what, if any, are the 
 * restrictions on the argument type(s) that can be passed, and what is the return type?
 * template <typename It>
 * auto fcn3(It beg, It end) -> decltype(*beg + 0)
 * {
 *      // process the range
 *      return *beg; // return a copy of an element from the range
 * }
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * template <typename It>
 * auto fcn3(It beg, It end) -> decltype(*beg + 0)  //  legal : dereferencing iter or pointer returns lvalue, to convert the return type from lvalue reference to rvalue 
 * {                                                //          we are adding 0 to it, as operator+ returns an rvalue. But it imposes a restriction that the type returned 
 *      // process the range                        //          by dereferencing should have operator+ overloaded which should take an right operand, to which int is convertible.
 *      return *beg;                                //          Orelse the call is in error.
 * }                                                //          if *beg is string, string + 0 is error                     
 * 
 *************************************************************************************************************************************************************/
#include <iostream>
#include <vector>


template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)  //  error : no operator+ for string and int
{
    // process the range
    return *beg; // return a copy of an element from the range
}

int main() {
    std::vector<std::string> ivec{"m","n"};
    std::cout << fcn3(ivec.begin(), ivec.end()) << std::endl;    //  error 
}