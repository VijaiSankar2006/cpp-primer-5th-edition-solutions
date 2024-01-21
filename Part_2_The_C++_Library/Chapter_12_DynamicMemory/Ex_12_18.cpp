/************************************************************************************************************************************************************
 * @file Ex_12_18.cpp
 * @brief Exercise 12.18: Why doesn’t shared_ptr have a release member?
 * @date 2024-01-16
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 * unique_ptr cannot be copied or assigned to another unique_ptr, as they own the object. So in-case if we want to manage the
 * obect through another pointer, unique_ptr needs to realease the object it owns so that another pointer can be assigned to manage, basicaly
 * we are transferring ownership.
 *         But shared_ptr doesn't own the object it points, so it cannot give away the ownership and there might be another
 * shared_ptr sharing the object which might delete the object even if there is a relese member.
 *         So there is no relese member for shared_ptr
 * refer : https://stackoverflow.com/questions/1525764/how-to-release-pointer-from-boostshared-ptr
 * 
*/