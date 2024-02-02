/************************************************************************************************************************************************************
 * @file Ex_13_1.cpp
 * @brief Exercise 13.1: What is a copy constructor? When is it used?
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * copy constructor is a constructor that takes a reference to an object of it's own type, they are used for copy initialisation when
 *  - we assign an object using '=' operator to initialise 
 *  - call by value 
 *  - return by value 
 *  - brace initialise an array or other members of an aggregate class
 * 
 * ex :-  class foo{
 *        public :
 *            foo(const foo &);  //  copy constructor
 *        };
 *************************************************************************************************************************************************************/