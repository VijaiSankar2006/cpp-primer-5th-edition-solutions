/************************************************************************************************************************************************************
 * @file Ex_14_50.cpp
 * @brief Exercise 14.50: Show the possible class-type conversion sequences for the initializations of ex1 and ex2.
 *  Explain whether the initializations are legal or not.
 * struct LongDouble {
 *      LongDouble(double = 0.0);
 *      operator double();
 *      operator float();
 * };
 * LongDouble ldObj;
 * int ex1 = ldObj;
 * float ex2 = ldObj;
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * int ex1 = ldObj;  // ambiguous call  ldObj.operator double() and ldObj.operator float() both are viable
 * float ex2 = ldObj;  //  ok :  ldObj.operator float() is a exact match
 * 
 *************************************************************************************************************************************************************/

