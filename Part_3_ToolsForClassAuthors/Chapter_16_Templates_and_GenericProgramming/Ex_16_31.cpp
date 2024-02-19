/************************************************************************************************************************************************************
 * @file Ex_16_31.cpp
 * @brief Exercise 16.31: Explain how the compiler might inline the call to the deleter if we used DebugDelete with
 * unique_ptr.
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * since a custom deleter is part of the unique_ptr type. we have to pass the type of the callable object as the template 
 * parameter along with the type of the object to create a unique_ptr. 
 *      Then we have to pass the callable object to the constructor of the unique_ptr. When unique_ptr is destroyed
 * it executes the call operator on the callable object we passed which in return deletes the pointer. 
 * 
 *************************************************************************************************************************************************************/