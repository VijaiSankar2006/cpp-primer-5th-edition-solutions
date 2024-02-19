/************************************************************************************************************************************************************
 * @file Ex_16_10.cpp
 * @brief Exercise 16.10: What happens when a class template is instantiated?
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * When a class template is instantiated, a specific class is generated with class template name followed by the template
 * argument in the angle brackets and and class defintion will have all the template parameters replaced by the template
 * arguments, but member functions will be defined in the generated class if and only if the member functions are used 
 * in the program.
 * 
 *************************************************************************************************************************************************************/