/************************************************************************************************************************************************************
 * @file Ex_16_54.cpp
 * @brief Exercise 16.54: What happens if we call print on a type that doesn’t have an << operator?
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * if we call print on a type that doesn't have an << operator, then the call is in compile time error [no operator << found]
 * ex:-  print(42, s, Sales_data());
 * //  error : no operator << found for val of type Sales_data(). 
 * 
 *************************************************************************************************************************************************************/