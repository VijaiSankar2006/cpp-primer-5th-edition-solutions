/************************************************************************************************************************************************************
 * @file Ex_16_8.cpp
 * @brief Exercise 16.8: In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers 
 * prefer using != to using <. Explain the rationale for this habit.
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * When defining templates, restrictions on the types we can use arises whether if all the operations used in the template
 * defintion is supported by the types. For instance if we compare two objects with '<' and if the object didn't have
 * the '<' operator then the code is in error.
 *      For example one pass iterators don't have '<' operator defined for them, so if our template compare list::begin() < list::end() 
 * then the code is in error. So c++ programmers normally use "==" & "!=" operators in template defintions to reduce
 * type restrictions as much as possible. 
 * 
 *************************************************************************************************************************************************************/