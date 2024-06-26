/************************************************************************************************************************************************************
 * @file Ex_13_25.cpp
 * @brief Exercise 13.25: Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to 
 * continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector. Your revised class will
 * need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and
 * copy-assignment operators must do. Explain why the class does not need a destructor.
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * copy constructor should allocate new memory and copy the contents rather than the shared_ptr
 * copy assignment operator should allocate a new memory and copy the rhs contents to the memory not the shared_ptr, then
 * assign the memory to the shared_ptr
 * 
 * As the class handles the memory management through a shared_ptr, when the object is destroyed, the synthesised destructor
 * calls the shared_ptr destructor to do memory deallocation if necessary. so the class doesn't need to define a destructor
 * 
 *************************************************************************************************************************************************************/