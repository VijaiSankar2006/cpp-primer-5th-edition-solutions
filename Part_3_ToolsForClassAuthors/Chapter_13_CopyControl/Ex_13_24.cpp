/************************************************************************************************************************************************************
 * @file Ex_13_24.cpp
 * @brief Exercise 13.24: What would happen if the version of HasPtr in this section didn’t define a destructor? What if HasPtr
 * didn’t define the copy constructor?
 * @date 2024-01-23
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * if HasPtr didn't define a destructor, one will be synthesised for the class, but synthesised destructor will not delete the
 * built-in pointer resulting in memory leak
 * if HasPtr didn't define a copy constructor, one will be synthesised for the class, but synthesised copy_constructor will
 * copy the pointer rather than allocating a new memory to hold the data resulting in both the original and new sharing the
 * state which we don't want as HasPtr objects should have independent state.
 * 
 *************************************************************************************************************************************************************/