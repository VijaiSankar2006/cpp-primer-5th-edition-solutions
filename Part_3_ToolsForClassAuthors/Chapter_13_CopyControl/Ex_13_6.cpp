/************************************************************************************************************************************************************
 * @file Ex_13_6.cpp
 * @brief Exercise 13.6: What is a copy-assignment operator? When is this operator used? What does the synthesized 
 * copy-assignment operator do? When is it synthesized?
 * @date 2024-01-22
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * copy-assignment operator is a overloaded assignment operator definded by the class to control what happens when it's objects
 * is assigned to its own type
 * ex:-  foo f1(10), f2(40);  
 *       f1 = f2 
 * copy assignment operator is used to copy the righthand object's value in to the lefthand object's value. 
 * A synthesised copy-assignment operator assigns the members of the right hand operand to the corresponding members of the left
 * hand operand. lhs operand will be pass implicit this pointer and rhs operand will be passed as an explicit parameter
 *      It is synthesised when a class doesn't define its own copy-assignment operator.
 *************************************************************************************************************************************************************/
