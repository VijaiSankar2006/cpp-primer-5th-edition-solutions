/************************************************************************************************************************************************************
 * @file Ex_13_38.cpp
 * @brief Exercise 13.38: We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?
 * @date 2024-01-25
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * As our classes are not allocating any resource, any local object will be destroyed at the end of the block, 
 * so if copy_assignment operator takes a non-reference type, it will be a temporary object which eventualy dies at the end of block
 * so no point in adding it, as swaping will only swap the lhs with the temp object.
 * if we use swap with reference type, then we will be swaping the messages rather than assigning
 * 
 *************************************************************************************************************************************************************/