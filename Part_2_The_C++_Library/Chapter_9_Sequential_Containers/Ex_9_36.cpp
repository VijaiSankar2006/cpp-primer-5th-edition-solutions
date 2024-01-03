/************************************************************************************************************************************************************
 * @file Ex_9_36.cpp
 * @brief Exercise 9.36: Can a container have a capacity less than its size?
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * A container capacity can never be less than its size, as capacity is maximum how many elements a vector can hold, as size is
 * the no of elements a vector holds, so capacity of a vector at any time will be same as size or larger than size.
 * When we add a new element beyound a vector's capacity, it allocates new larger memory and stores all the elements with the
 * new element in the new memory and deallocates the old memory.
*/