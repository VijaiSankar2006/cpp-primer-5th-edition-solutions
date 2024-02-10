/************************************************************************************************************************************************************
 * @file Ex_15_4.cpp
 * @brief Exercise 15.4: Which of the following declarations, if any, are incorrect? Explain why.
 * class Base { ... };
 * (a) class Derived : public Derived { ... };
 * (b) class Derived : private Base { ... };
 * (c) class Derived : public Base;
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * class Derived : public Derived { ... };   //  error : class cannot derive from itself
 * class Derived : private Base { ... };     //  ok : Derived inherits from Base 
 * class Derived : public Base;       //  error : class declaration should not contain derivation list
 *************************************************************************************************************************************************************/