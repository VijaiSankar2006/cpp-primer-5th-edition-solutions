/************************************************************************************************************************************************************
 * @file Ex_9_42.cpp
 * @brief Exercise 9.42: Given that you want to read a character at a time into a string, and you know that you need to read at
 *        least 100 characters, how might you improve the performance of your program?
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 * reserve the capacity of 100 characters after defining the string
 * string s;
 * s.reserve(100);      //  gives the s, the capacity to store 100 characters.
 * as the no of characters is known to read atleast 100 characters, increasing the capacity of the string s with reserve mem fun
 * we avoid many inbetween reallocations of the s to increase size, as normaly compilers implement a strategy of growing the capacity
 * from 15 to n, by increasing the capacity by curr to double the size of curr.
 * ex:- 15,30,60,120,. . .,n,2n   g++-12 implementation string
*/