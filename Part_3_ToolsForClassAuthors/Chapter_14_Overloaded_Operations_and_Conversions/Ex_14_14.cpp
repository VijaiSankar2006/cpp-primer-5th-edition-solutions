/************************************************************************************************************************************************************
 * @file Ex_14_14.cpp
 * @brief Exercise 14.14: Why do you think it is more efficient to define operator+ to call operator+= rather than the other 
 * way around?
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * as arithmatic operations don't change the state of operands, they do the operation and store the result in a temp variable
 * it is more natural to call compound assignment operator which exactly do that, do the operation and store the result in lhs.
 *      If we make operator+= to call operator+, it adds two operands and store in a temp and return the temp, and then the temp
 * will be assigned in the lhs of operator+=, as we can see we unnessarily copying the result twice. 
 *************************************************************************************************************************************************************/

