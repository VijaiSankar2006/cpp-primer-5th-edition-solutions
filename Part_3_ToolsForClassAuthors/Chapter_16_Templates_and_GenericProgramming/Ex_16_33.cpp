/************************************************************************************************************************************************************
 * @file Ex_16_33.cpp
 * @brief Exercise 16.33: Name two type conversions allowed on function arguments involved in template argument 
 * deduction.
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * 1. top-level const is ignored on both template arguments and template parameters, (ie) const conversion happen when
 * a non-const reference is passed to const reference or const type is passed to non-const type.
 * 
 * 2. array and function to pointer conversion happens but if a function template uses same template type
 * parameter to define its reference parameters, then all arguments should be of same size in case of arrays or else the call 
 * is in error. As size is part of the type for arrays, a function template should use multiple type parameters to define
 * the function parameters for a function call with different types of arrays to be successfull.
 *      As for the pointer parametes, sizes of the arrays doesn't need to be same, as we are only passing the address.
 * 
 *************************************************************************************************************************************************************/

