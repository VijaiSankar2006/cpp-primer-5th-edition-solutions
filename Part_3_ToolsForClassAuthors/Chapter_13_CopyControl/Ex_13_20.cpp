/************************************************************************************************************************************************************
 * @file Ex_13_20.cpp
 * @brief Exercise 13.20: Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes
 * from § 12.3 (p. 484)
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * a class needs to define its own copy_control members only when it allocates memory, but though TextQuery and QueryResult
 * allocates memory, they do it through shared_ptr, so the underlying data can be shared between the objects, So the synthesised
 * copy_control works fine.
 * when TextQuery copied, 
 *      shared_ptr use_count incremented by 1.
 *      map's copy_constructor is called
 *      which inturn calls string copy_constructor and increase use_count of shared_ptr
 * when QueryResult copied
 *      string copy_constructor is called to copy the string sought
 *      lines, shared_ptr use_count incremented by 1
 *      file, shared_ptr use_count incremented by 1
 * 
 * when TextQuery assigned
 *      if lhs and rhs are same object, nothing happens
 *      if not then, lhs shared_ptr decrements
 *      rhs shared_ptf increments as it is copied to the lhs shared ptr
 *      map's assignment operator is called
 *      which inturn calls string assignment_operator and decreases use_count of shared_ptr of old mapped_type and increments 
 *          shared_ptr of the rhs mapped_type as lhs mapped_type points to it now
 * when QueryResult assigned
 *      if lhs and rhs are same object, nothing happens
 *      if not then, 
 *      string's copy_assignment operator is called to assign rhs.string to lhs.string
 *      if not then, lhs shared_ptr decrements
 *      rhs shared_ptf increments as it is assigned to the lhs shared ptr
 *     
 * when TextQuery destroyed
 *      shared_ptr use_count decrements by 1, if it becomes zero, the object is destroyed, which in turn calls the vector's
 * destructor and which calls string's destructor 
 *      map destructor is called which inturn calls string's destructor and decreases the use_count of shared_ptr, and if it is
 * zero, object is destroyed which calls set's destructor
 * When QueryResult destroyed
 *      calls string's destructor
 *      decreases the shared_ptr use_count, if it is zero, destroys the object, which calls vector's destructor which in turn
 * calls string's destructor
 *      decreases the shared_ptr use_count, if it is zero, destroys the object, which calls set's destructor
 *************************************************************************************************************************************************************/