/************************************************************************************************************************************************************
 * @file Ex_13_15.cpp
 * @brief Exercise 13.15: Assume numbered has a copy constructor that generates a new serial number. Does that change the
 * output of the calls in the previous exercise? If so, why? What output gets generated?
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * let the serial no start from 1
 * a = 1;
 * b = a  // uses copy_constructor, so b = 2;
 * c = b // uses copy_constructor, so c = 3
 * 
 * but when ever we call f(), a new numbered object is created from the argument with copy_constructor, so the param s gets a
 * new serial number whenever we call.
 * output :
 * 4
 * 5
 * 6
 * output is not as expected, as the sno of a, b, and c is printed rather a new serial no is printed
 *************************************************************************************************************************************************************/