/************************************************************************************************************************************************************
 * @file Ex_16_38.cpp
 * @brief Exercise 16.38: When we call make_shared (§ 12.1.1, p. 451), we have to provide an explicit template argument.
 *  Explain why that argument is needed and how it is used.
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * If there is no explicit template argument, a call with 0 as argument will result in to template parameter deduced as
 * int, but we want make_shared to return pointer to different types value initialised or default inialised. So in this
 * case auto template type deduction is not usable as
 *      make_shared(0)  // T is int
 * but how to make T as double or vector or class type.
 * So explicit template argument is must to define what type memory should be allocated and constructed and pointer to be returned
 *      make_shared<vector<int>(2) //  instantiates make_shared with vector<int> as template type parameter resulting in 
 *                                     returning a shared_ptr to a vector<int> with 2 elements default initialised.  
 * 
 *************************************************************************************************************************************************************/