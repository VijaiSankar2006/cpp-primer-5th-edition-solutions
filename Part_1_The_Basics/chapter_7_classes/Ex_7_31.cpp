/************************************************************************************************************************************************************
 * @file Ex_7_31.cpp
 * @author semicolon_missing
 * @brief Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 **************************************************************************************************************************************************************/

#include <iostream>

class Y;        //  forward declaration of class Y is required for class X to declare a ptr to Y

class X{
    private :
        Y *ptr;
      //  Y var;    error : as Y is not defined yet we won't be able to create a variable
};    //                    ptr is possible but not a variable, as to create a variable compiler needs to know how                           
      //                    much size it occupies, but for ptr unless we dereference compiler can handle an incomplete type  
class Y{
    private :
        X var;   // ok : X has been defined before its usage
};


