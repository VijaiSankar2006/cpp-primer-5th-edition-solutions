/************************************************************************************************************************************************************
 * @file Ex_12_31.cpp
 * @brief Exercise 12.31: What difference(s) would it make if we used a vector instead of a set to hold the line numbers? 
 * Which approach is better? Why?
 * @date 2024-01-19
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * set doesn't allow multiple elements to be with same value, as we don't want the line numbers to be repeated if same word
 * appears more than once in a line, set is a natural choice as it ignores if a line number is already present.
 *      if we use a vector, every time we add a line number we need to check if line number is already added, it is more verbose
 * compared to using set and it will be unnecessarily hard to read and write .
 *      It's always a better choice to use set if we want the elements not to be repeated
 * 
 *************************************************************************************************************************************************************/