/************************************************************************************************************************************************************
 * @file Ex_15_8.cpp
 * @brief Exercise 15.8: Define static type and dynamic type.
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * static type : type of the variable with which it is declared or type the expression yields
 * dynamic type : type the variable or expression represents in memory.
 * for a variable, static type and dynamic type are same, where as for a pointer and reference static and dynamic
 * type may differ in inheritance.
 *      ex:-  
 *              base b1;        //  static type == dynamic type ==  base
 *              derived d1;     //  static type == dynamic type == d1
 *              base *p;        //  static type == base  , dynamic type == unknown
 *              p = &b1;        //  static type == base,   dynamic type == base
 *              p = &d1;        //  static type == base,   dynamic type == derived
 * 
 *************************************************************************************************************************************************************/