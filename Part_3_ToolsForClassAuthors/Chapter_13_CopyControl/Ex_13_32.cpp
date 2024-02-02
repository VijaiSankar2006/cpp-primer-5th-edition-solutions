/************************************************************************************************************************************************************
 * @file Ex_13_32.cpp
 * @brief Exercise 13.32: Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the 
 * benefit? If not, why not?
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * pointer-like version of HasPtr doesn't need to define a swap function as the only reason a class needs a swap function is
 * when swaping values rather than unnecessarily allocating new memory, we can indeed swap the pointers. But HasPtr pointer-like
 * version , when swap() is called copy_constructor is called as needed, which by definition copies the pointer rather than 
 * value (ie) no memory is allocated again, at the end swap() by default will swap the pointers. So as copy_constructor just
 * copies the pointers this class doesn't need its own swap() function.
 *************************************************************************************************************************************************************/

