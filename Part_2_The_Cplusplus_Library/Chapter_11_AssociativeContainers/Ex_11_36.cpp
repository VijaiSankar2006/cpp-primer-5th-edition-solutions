/************************************************************************************************************************************************************
 * @file Ex_11_36.cpp
 * @brief Exercise 11.36: Our program does no checking on the validity of either input file. In particular, it assumes
 * that the rules in the transformation file are all sensible. What would happen if a line in that file has a key, one
 * space, and then the end of the line? Predict the behavior and then check it against your version of the program.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * if a line contains a key, one space and then end of line, then 
 *      in my version : key itself is assigned as the value
 *      in author's version : throws runtime_error
 * 
 *************************************************************************************************************************************************************/