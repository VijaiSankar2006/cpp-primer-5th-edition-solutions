/************************************************************************************************************************************************************
 * @file Ex_13_50.cpp
 * @brief Exercise 13.51: Although unique_ptrs cannot be copied, in § 12.1.5 (p. 471) we wrote a clone function that returned
 * a unique_ptr by value. Explain why that function is legal and how it works.
 * @date 2024-01-27
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * when we return a unique_ptr by value, the compiler knows the object which is created at the return statement or the local object ret is 
 * going to be destroyed, so compiler uses move operations to move the resources to the result of the expression

 * unique_ptr<int> clone(int p) {
 *   return std::move(unique_ptr<int>(new int(p)));
 * }
 *************************************************************************************************************************************************************/