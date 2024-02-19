/************************************************************************************************************************************************************
 * @file Ex_16_55.cpp
 * @brief Exercise 16.55: Explain how the variadic version of print would execute if we declared the nonvariadic version
 * of print after the definition of the variadic version.
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * If we declared the non-variadic version after the definition of the variadic version, then our recursive calls to 
 * print would have instantiated another function instance from variadic version with an empty template parameter pack
 * and empty function parameter pack which again will call print with empty argument pack which again repeats the 
 * instantiation from the variadic version with empty template parameter pack, so resulting in to recursive loop.
 *      To prevent this recursive loop we need a non-varidic print() function declaration before the variadic version
 * so when a call to print(os, rest...) with an explicit argument to outstream, and an argument pack with only one argument
 * it expands in to print(os, val) which calls the non-variadic version print(std::ostream &, const T &val) with deduced as
 * the type of val.
 * 
 *************************************************************************************************************************************************************/