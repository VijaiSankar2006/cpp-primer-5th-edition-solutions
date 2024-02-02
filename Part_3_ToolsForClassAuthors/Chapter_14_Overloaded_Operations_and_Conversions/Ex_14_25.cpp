/************************************************************************************************************************************************************
 * @file Ex_14_25.cpp
 * @brief Exercise 14.25: Implement any other assignment operators your class should define. Explain which types should be
 * used as operands and why.
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * I don't think Date class needs any other assignment operators, as it won't make any sense to assign date or month or year 
 * alone to create a Date.
 *      The types which has a natural conversion to our class type should be used as operands.
 * ex:- 
 *      c-style string is a const array of characters which closely resembles string,our String class should take c-style string
 * as operands 
 *************************************************************************************************************************************************************/