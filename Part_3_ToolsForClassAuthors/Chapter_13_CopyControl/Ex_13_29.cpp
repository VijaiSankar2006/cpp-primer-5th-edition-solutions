/************************************************************************************************************************************************************
 * @file Ex_13_29.cpp
 * @brief Exercise 13.29: Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

//  type-spefic version of swap is used when we call swap, if it is not defined std::swap is called, 
// the calls to swap inside is used to swap string pointers and int type, where as our version is used for HasPtr type so
// no recursion loop is caused 