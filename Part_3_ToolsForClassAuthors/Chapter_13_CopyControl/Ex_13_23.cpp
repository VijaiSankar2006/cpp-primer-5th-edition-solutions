/************************************************************************************************************************************************************
 * @file Ex_13_23.cpp
 * @brief Exercise 13.23: Compare the copy-control members that you wrote for the solutions to the previous section’s exercises
 * to the code presented here. Be sure you understand the differences, if any, between your code and ours.
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

// my copy-assignment operator
HasPtr & operator=(const HasPtr &source){
        *ps = *(source.ps);         
        i = source.i;

        return *this;
}

//  author's code for copy-assignment operator
HasPtr& operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps); 
    delete ps; 
    ps = newp;
    i = rhs.i;
    return *this; 
}

/**
 * though my version works fine in this case, as we directly copy the value pointed by rhs.ps and write in to the memory pointed
 * by the lhs.ps, it won't work if the objects are of array type with different size.
 *      so we have to incultivate the habit of copying the value pointed rhs pointers in to a new dynamicaly alloted memory
 * and destroying the object pointed by lhs pointers and freeing the memory pointed by lhs pointers and finaly assign the
 * new memory to the pointer in the lhs.
 * It has to kept in mind
 *      - Assignment operators must work correctly if an object is assigned to itself
 *      - so always copy the rhs in to local temporary
 *      - once the copy is done successfully, destroy the members of lhs
 *      - once the lhs members are destroyed, copy the data from the temporary into the members of the lhs
 * 
 * refer https://stackoverflow.com/questions/28786364/why-do-we-need-to-delete-pointers-inside-copy-assignment-operator 
*/