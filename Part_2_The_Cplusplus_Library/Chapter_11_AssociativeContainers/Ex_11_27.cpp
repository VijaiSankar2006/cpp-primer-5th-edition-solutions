/************************************************************************************************************************************************************
 * @file Ex_11_27.cpp
 * @brief Exercise 11.27: What kinds of problems would you use count to solve? When might you use find instead?
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 * set and map : find should be used as the keys are unique
 * multiset and multimap :
 *      find() should be used to check whether a key is present or not, if key is present, it won't check other elements
 * where as count() will process the entire map
 *      count() should be used if we want to know number of elements with a particular key if present
*/