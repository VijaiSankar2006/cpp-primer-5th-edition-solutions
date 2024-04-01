/************************************************************************************************************************************************************
 * @file Ex_12_5.cpp
 * @brief Exercise 12.5: We did not make the constructor that takes an initializer_list explicit (§ 7.5.4, p. 296). Discuss the
 * pros and cons of this design choice.
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * as the StrBlob class holds the vector of strings, an initializer list naturaly resembles the vector of strings, so there is no
 * need to make the constructor explicit.
 *     so any where a StrBlob object is needed an initializer list can be used to construct one
 * 
 *************************************************************************************************************************************************************/