/************************************************************************************************************************************************************
 * @file Ex_14_2.cpp
 * @brief Exercise 14.2: Write declarations for the overloaded input, output, addition, and compound-assignment operators for
 * Sales_data.
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include <iostream>
class Sales_data;

std::istream & operator>>(std::istream &, Sales_data &source);    //  input operator
std::ostream & operator<<(std::ostream &, const Sales_data &source);   //  output operator
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);   //   addition operator
Sales_data & Sales_data::operator+=(const Sales_data &rhs);    //  compound-assignment operator

