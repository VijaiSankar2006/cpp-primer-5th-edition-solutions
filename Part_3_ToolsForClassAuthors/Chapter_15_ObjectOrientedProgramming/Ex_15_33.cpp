/************************************************************************************************************************************************************
 * @file Ex_15_33.cpp
 * @brief Exercise 15.33: What about objects of type Query_base?
 * @date 2024-02-07
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * Since Query_base is an abstract class with two pure virtual functions, the objects can be constructed as a part of
 * derived class objects. Again as we don't implement any copy control members, all the copy control members for us.
 * So when the derived class object is copied, moved , assigned and destroyed, it will run the respective members of 
 * Query_base object. 
 *************************************************************************************************************************************************************/