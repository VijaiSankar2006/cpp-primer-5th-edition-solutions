/************************************************************************************************************************************************************
 * @file Ex_16_67.cpp
 * @brief Exercise 16.67: Would defining these specializations affect function matching for debug_rep? If so, how?
 *  If not, why not?
 * @date 2024-02-18
 * @copyright Copyright (c) 2024
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * template specializations won't affect the function matching. As for function matching, only overloaded fuctions and 
 * primary template matching the call will be considered.
 *      only when a primary template is chosen for the call, then the specialized versions will be used unless other
 * wise these specializations doen't impact function matching.
 * 
 *************************************************************************************************************************************************************/