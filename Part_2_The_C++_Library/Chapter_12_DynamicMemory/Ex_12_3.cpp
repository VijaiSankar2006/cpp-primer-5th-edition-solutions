/************************************************************************************************************************************************************
 * @file Ex_12_3.cpp
 * @brief Exercise 12.3: Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t 
 * they needed?
 * @date 2024-01-13
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * push_back() adds a element to the container and pop_back() deletes the last element in the container, both alters the state
 * of the container.
 * const member functions cannot alter the state of the object, so this class need not have const versions of these functions
 * 
 *************************************************************************************************************************************************************/


