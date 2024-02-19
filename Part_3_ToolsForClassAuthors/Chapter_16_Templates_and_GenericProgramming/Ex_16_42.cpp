/************************************************************************************************************************************************************
 * @file Ex_16_42.cpp
 * @brief Exercise 16.42: Determine the type of T and of val in each of the following calls:
 * template <typename T> void g(T&& val);
 * int i = 0; const int ci = i;
 * (a) g(i); (b) g(ci); (c) g(i * ci);
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * template <typename T> void g(T&& val);
 * int i = 0; const int ci = i;
 * (a) g(i);        //  is a lvalue, so T will be deduced as int &, so void g(T& && val) == void g(int & val) will be instantiated
 * (b) g(ci);       //  ci is const lvalue, so T is const int &, void g(const int &val) is instantiated
 * (c) g(i * ci);   //  operator*() yields an rvalue, so T is int, void g(int &&val) is instantiated.
 *************************************************************************************************************************************************************/



