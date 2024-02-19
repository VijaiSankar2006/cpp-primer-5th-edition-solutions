/************************************************************************************************************************************************************
 * @file Ex_16_59.cpp
 * @brief Exercise 16.59: Assuming s is a string, explain svec.emplace_back(s)
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * std::string s;
 * svec.emplace_back(s)
 * emplace_back() template with template parameter pack of 1 type (ie) Args is pack of 1 type
 * emplace_back() function with function parameter args of type Args&&..., which expands the Args parameter pack in the pattern
 * type&& in to std::string &&,  
 * then in the alloc.construct() call, std::forward<Args>(args)..., expands in to std::forward<std::string>(s)
 * (ie) we get the original type of s which is passed to construct to construct at the address pointed by first_free
 * 
 *************************************************************************************************************************************************************/