/************************************************************************************************************************************************************
 * @file Ex_11_37.cpp
 * @brief Exercise 11.37: What are the advantages of an unordered container as compared to the ordered version of that 
 * container? What are the advantages of the ordered version
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * ordered container : elements are ordered(sorted), so searching for a key is quick operation but requires a way to compare the keys
 * unordered container : since elements are stored unordered, searching for a key consumes more time normally, but if the 
 *          - cost of maintaining elements in order is prohibitive or
 *          - there is no natural way of comparison between keys
 * an unordered container is the solution, as these uses hash to store elements.
 * 
 *************************************************************************************************************************************************************/