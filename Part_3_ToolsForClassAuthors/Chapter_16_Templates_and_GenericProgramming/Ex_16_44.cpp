/************************************************************************************************************************************************************
 * @file Ex_16_44.cpp
 * @brief Exercise 16.44: Using the same three calls as in the first exercise, determine the types for T if g’s 
 * function parameter is declared as T (not T&&). What if g’s function parameter is const T&?
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * 1) template <typename T> void g(T val) {} 
 * (a) g(i);       //  T is int
 * (b) g(ci);      //  T is int, top level const is ignored
 * (c) g(i * ci);  //  T is int 
 * 
 * 2) template <typename T> void g(const T &) {}
 * (a) g(i);       //  T is int
 * (b) g(ci);      //  T is int  
 * (c) g(i * ci);  //  T is int, rvalue can be passed to const lvalue reference
 * 
 *************************************************************************************************************************************************************/

