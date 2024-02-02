/************************************************************************************************************************************************************
 * @file Ex_14_51.cpp
 * @brief Exercise 14.51: Show the conversion sequences (if any) needed to call each version of calc and explain
 *  why the best viable function is selected.
 * void calc(int);
 * void calc(LongDouble);
 * double dval;
 * calc(dval); // which calc?
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * calc(dval)  //  calc(int) is selected as the best match, based on ranking overloaded functions
 * https://github.com/Mooophy/Cpp-Primer/tree/master/ch14#exercise-1451
 * 
 *************************************************************************************************************************************************************/