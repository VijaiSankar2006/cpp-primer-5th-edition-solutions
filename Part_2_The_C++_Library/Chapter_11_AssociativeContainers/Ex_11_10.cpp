/************************************************************************************************************************************************************
 * @file Ex_11_10.cpp
 * @brief Exercise 11.10: Could we define a map from vector<int>::iterator to int? What about from list<int>::iterator to int? In each case, if not, why not?
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <vector>
#include <map>
#include <list>

std::map<std::vector<int>::iterator, int> itvec_int; // ok : vector supports < operator
std::map<std::list<int>::iterator, int> itlst_int;   // error : list doen't support < operator   

key type in a ordered associative container should support < operator, as the keys will be compared when the elements are added
in to the container.