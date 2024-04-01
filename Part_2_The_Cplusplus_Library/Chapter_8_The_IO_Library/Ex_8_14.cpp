/************************************************************************************************************************************************************
 * @file Ex_8_14.cpp
 * @brief Exercise 8.14: Why did we declare entry and nums as const auto &?
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

//  As we are not going to modify the data in people, we inititialise a const auto reference with each element in people.
//  As entry is reference to const, we cannot use plain reference to nums, it has to be reference to const;
