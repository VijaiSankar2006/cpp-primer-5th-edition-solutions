/************************************************************************************************************************************************************
 * @file Ex_11_30.cpp
 * @brief Exercise 11.30: Explain the meaning of the operand pos.first->second used in the output expression of the final
 *        program in this section.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * pos.first->second :
 *      pos is the pair_type element returned by equal_range() member, it contains
 *      pos.first  : iterator same as returned by lower_bound
 *      pos.second : iterator same as returned by upper_bound 
 *      
 * since the container is multimap, the elements are pair_type, so pos indicates the range of elements with a particular key
 *      pos.first, pos.second : pair_type  
 *      pos.first->second  : -> operator is used to fetch the value of the element pointed by pos.first
 *************************************************************************************************************************************************************/