/************************************************************************************************************************************************************
 * @file Ex_9_23.cpp
 * @brief Exercise 9.23: In the first program in this section on page 346, what would the values of val, val2, val3, and val4
 *        be if c.size() is 1?
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

if (!c.empty()) {
    auto val = *c.begin(), val2 = c.front();
    auto last = c.end();
    auto val3 = *(--last); 
    auto val4 = c.back(); 
}

if c.size() is 1, then there is only one element in c.
    val == val2 == val3 == val4 == c[0]