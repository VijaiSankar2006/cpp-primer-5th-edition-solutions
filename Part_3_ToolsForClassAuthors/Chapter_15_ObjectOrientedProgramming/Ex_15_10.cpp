/************************************************************************************************************************************************************
 * @file Ex_15_10.cpp
 * @brief Exercise 15.10: Recalling the discussion from § 8.1 (p. 311), explain how the program on page 317 that
 * passed an ifstream to the Sales_data read function works.
 * @date 2024-02-03
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * Sales_data::read(std::istream &, Sales_data &)  
 *      As read function takes a reference to the istream, from which ifstream derives (ie) istream is the base class
 * of the ifstream, so we can pass ifstream to the read() function.
 * 
 *************************************************************************************************************************************************************/