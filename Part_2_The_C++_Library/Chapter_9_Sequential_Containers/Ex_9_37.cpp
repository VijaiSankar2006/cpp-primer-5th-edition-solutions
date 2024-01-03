/************************************************************************************************************************************************************
 * @file Ex_9_37.cpp
 * @brief Exercise 9.37: Why don’t list or array have a capacity member?
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * list : list is a doubly linked list, the elements are not stored in contigous memory location.Whenever we add a element a new
 *        memory will be alloted for the new element independently and a pointer will be stored in the last element, simply every 
 *        object in a list will contain value of the element and address of the next object and address of the predessor.
 * array : array type is implemented like the built-in array, where size of the array is part of the type. So once an array
 *         is created of a specific size, it cannot be resized
 *************************************************************************************************************************************************************/

