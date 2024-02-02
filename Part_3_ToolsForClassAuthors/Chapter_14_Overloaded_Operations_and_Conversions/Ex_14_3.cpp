/************************************************************************************************************************************************************
 * @file Ex_14_3.cpp
 * @brief Exercise 14.3: Both string and vector define an overloaded == that can be used to compare objects of those types. 
 * Assuming svec1 and svec2 are vectors that holdstrings, identify which version of == is applied in each of the following 
 * expressions:
 * (a) "cobble" == "stone" 
 * (b) svec1[0] == svec2[0]
 * (c) svec1 == svec2 
 * (d) "svec1[0] == "stone"
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * (a) "cobble" == "stone"    //   string version
 * (b) svec1[0] == svec2[0]   //   string version
 * (c) svec1 == svec2         //   vector version
 * (d) svec1[0] == "stone"    //   string version
 *************************************************************************************************************************************************************/