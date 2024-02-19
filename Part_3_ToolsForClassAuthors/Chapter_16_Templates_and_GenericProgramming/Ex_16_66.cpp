/************************************************************************************************************************************************************
 * @file Ex_16_66.cpp
 * @brief Exercise 16.66: What are the advantages and disadvantages of overloading these debug_rep functions as compared
 * to defining specializations?
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * template overloading :
 *   advantages :
 *      overloading affects function matching, when a call is made, all the overloaded functions will be the candidate functions
 * and from which viable functions will be chosen and the better match is used.  
 *   dis-advantages :
 *      if we forget to provide the declaration of overloaded function before the template then template instantiation
 * will happen   
 *          
 *************************************************************************************************************************************************************/