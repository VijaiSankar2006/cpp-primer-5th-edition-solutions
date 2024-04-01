/************************************************************************************************************************************************************
 * @file Ex_12_8.cpp
 * @brief Exercise 12.8: Explain what if anything is wrong with the following function.
 *        bool b() 
 *        { int* p = new int; 
 *          // . . . 
 *          return p; 
 *        }
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * as the function's return type is bool, when we assign a pointer to the return expression, a valid pointer will be converted
 * to true and a pointer with null pointer will be converted to false.
 *        so the function's return statement tells memory allotment is successfull or not, but if new is unable to allot memory
 * then it will throw bad_alloc() exception.
 *        so in-order to avoid the exception new should be passed 'nothrow' library object to indicate that it should not throw
 * exception. so the correct form is as follows
 *************************************************************************************************************************************************************/

#include <memory>

bool b(){
    int *p = new(std::nothrow) int;
    //.......//
    return p;
}