/************************************************************************************************************************************************************
 * @file Ex_16_17.cpp
 * @brief Exercise 16.17: What, if any, are the differences between a type parameter that is declared as a typename 
 * and one that is declared as a class? When must typename be used?
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * There is no difference between a type parameter that is declared as a typename and one that is declared as a class.
 * typename should be used only when we using a type member of the template parameter inside the definition of the template
 * to indicate the compiler that it is a type rather than a static member.
 *************************************************************************************************************************************************************/