/************************************************************************************************************************************************************
 * @file Ex_9_3.cpp
 * @brief Exercise 9.3: What are the constraints on the iterators that form iterator ranges?
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 *  (a) both iterators needs to belong the same container, that is they should refer to elements or one past the end of the same 
 *      container
 *  (b) by incrementing begin repeatedly we should be able to reach end (ie) end can never precede begin
 *  
*/