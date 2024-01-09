/************************************************************************************************************************************************************
 * @file Ex_10_4.cpp
 * @brief Exercise 10.4: Assuming v is a vector<double>, what, if anything, is wrong with calling 
 *        accumulate(v.cbegin(), v.cend(), 0)?
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

//  error : using '0' as the third argument, which is a int type. As the 3rd argument's type is used to determine the type of 
//          sum and return type of accumulate.         
//          so each element is converted to int with loss of data and then the sum is returned.
//          ex:-  v{1.5,1.5}
//          calling accumulate with '0' as 3rd arg, will return 2 rather than 3.
//          So 3rd argument should be '0.0', type double.

