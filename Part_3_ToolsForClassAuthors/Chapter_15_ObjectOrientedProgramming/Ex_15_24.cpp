/************************************************************************************************************************************************************
 * @file Ex_15_24.cpp
 * @brief Exercise 15.24: What kinds of classes need a virtual destructor? What operations must a virtual destructor
 * perform?
 * @date 2024-02-05
 * 
 * @copyright Copyright (c) 2024
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * Base class must need a virtual destructor, so that when we run delete on base class pointer, the destructor of 
 * the dynamic type be run.
 *      The virtual destructors can be synthesised by using default, as it mostly doesn't need any aditional work
 * as its main purpose is to make the destruction based on dynamic type.
 * 
 *************************************************************************************************************************************************************/