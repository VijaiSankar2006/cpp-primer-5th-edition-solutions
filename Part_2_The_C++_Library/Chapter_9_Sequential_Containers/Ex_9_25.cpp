/************************************************************************************************************************************************************
 * @file Ex_9_25.cpp
 * @brief Exercise 9.25: In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal?
 *        What if elem2 or both elem1 and elem2 are the off-the-end iterator?
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * if elem1 == elem2, then range is empty, nothing will be deleted elem2 will be returned
 * if elem2 is off-the-iterator, all elements from elem1 to the last element will be removed, returns elem2
 * if elem1 and elem2 are off-the-end iterator, then range is empty returns elem2
*/