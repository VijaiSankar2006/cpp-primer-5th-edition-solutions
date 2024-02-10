/************************************************************************************************************************************************************
 * @file Ex_15_40.cpp
 * @brief Exercise 15.40: In the OrQuery eval function what would happen if its rhs member returned an empty set? What
 *  if its lhs member did so? What if both rhs and lhs returned empty sets?
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "Ex_15_40.cpp"

/************************************************************************************************************************************************************
 * if rhs member returns empty set, the set constructed by eval() will have only line_no's from set returned lhs
 * same thing will happen if lhs returns empty
 * if both are empty, then set constructed by eval will be empty, and the QueryResult will have empty set indicating 
 * word is not found in any line as per the query.
 *      The output stream operator defined to print QueryResult will print 
 * the <word> appeared 0 time in the file.
 * where the word is OrQuery.rep(); 
 *************************************************************************************************************************************************************/