/************************************************************************************************************************************************************
 * @file Ex_14_31.cpp
 * @brief Exercise 14.31: Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor.
 *  Why is that okay?
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * StrBlobPtr doesn't allocate or manage any resource, so synthesised copy-control members which does a member wise copy is
 * what is needed, as creation of weakptr and destruction of weakptr doesn't impact the data contained by StrBlob
 * 
 *************************************************************************************************************************************************************/

