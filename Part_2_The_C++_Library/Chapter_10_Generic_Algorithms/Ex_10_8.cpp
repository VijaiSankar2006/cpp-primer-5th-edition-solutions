/************************************************************************************************************************************************************
 * @file Ex_10_8.cpp
 * @brief Exercise 10.8: We said that algorithms do not change the size of the containers over which they operate. Why doesn’t
 *       the use of back_inserter invalidate this claim?
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 * back_inserter() returns a insert iterator bounded to the container, when we assign to insert iterator, it calls container 
 * operation to add elements.
 * as most of the containers can grow in size, when we pass back_inserter to an algorithm, it will change the size of the container
 * 
*/