/************************************************************************************************************************************************************
 * @file Ex_13_40.cpp
 * @brief Exercise 13.40: Add a constructor that takes an initializer_list<string> to your StrVec class.
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

StrVec::StrVec(const std::initializer_list<std::string> &il){
    auto data = alloc_n_copy(il.begin(), il.end());
    elements = data.first;
    first_free = cap = data.second;
}