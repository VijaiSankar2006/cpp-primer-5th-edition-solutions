/************************************************************************************************************************************************************
 * @file Ex_11_15.cpp
 * @brief Exercise 11.15: What are the mapped_type, key_type, and value_type of a map from int to vector<int>?
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

std::map<int, std::vector<int>> i_ivecmap;

key_type    : int
mapped_type : std::vector<int>
value_type  : std::pair<const int, std::vector<int>>

