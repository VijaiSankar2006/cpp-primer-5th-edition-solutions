/************************************************************************************************************************************************************
 * @file Ex_10_10.cpp
 * @brief Exercise 10.10: Why do you think the algorithms don’t change the size of containers?
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 * Algorithms operate over the containers through the iterators, they don't do container operations
 * assigning a val by derferencing a iterator writes a existing element, they don't add new element
 * so they don't change the size of containers. 
*/