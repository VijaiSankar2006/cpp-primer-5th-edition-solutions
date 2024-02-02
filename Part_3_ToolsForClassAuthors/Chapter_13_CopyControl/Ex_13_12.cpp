/************************************************************************************************************************************************************
 * @file Ex_13_12.cpp
 * @brief Exercise 13.12: How many destructor calls occur in the following code fragment?
 * bool fcn(const Sales_data *trans, Sales_data accum)
 * {
 *     Sales_data item1(*trans), item2(accum);
 *     return item1.isbn() != item2.isbn();
 * }
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * bool fcn(const Sales_data *trans, Sales_data accum)
 * {
 *     Sales_data item1(*trans), item2(accum);
 *     return item1.isbn() != item2.isbn();
 * }
 * 
 * 3 destructor calls occurs.
 *      - accum
 *      - item1
 *      - item2
 * 
 * as trans is built-in pointer, nothing is done when trans goes out of scope.
 * 
 *************************************************************************************************************************************************************/