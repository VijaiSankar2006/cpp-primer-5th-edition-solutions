/************************************************************************************************************************************************************
 * @file Ex_11_29.cpp
 * @brief Exercise 11.29: What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not
 *        in the container?
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * upper_bound : iterator to  an element larger whose key is larger than key passed so that inserting a new element will
 *               not affect the order of the container. If key passed is the largest of the container then off-the-end
 *               iterator will be returned
 * lower_bound : same as upper_bound, so lower_bound == upper_bound
 * equal_range : returns a pair type with iterator same as returned by lower_bound as first and iterator same as upper_bound
 *               as second element in pair. Both iterators will indicate the element with a key larger than key passed or 
 *               off-the-end iterator if the key is the largest
 *************************************************************************************************************************************************************/

