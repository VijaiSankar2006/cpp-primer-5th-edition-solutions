/************************************************************************************************************************************************************
 * @file Ex_9_30.cpp
 * @brief Exercise 9.30: What, if any, restrictions does using the version of resize that takes a single argument place on the
 *        element type?
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * if requested size is bigger than container's size, then new elements will be added, if it is built-in type, it will be
 * initialised to zero, 
 *      But if the element type is a class type, then the class needs to have a default constructor or we must supply a 
 *      initializer
*/