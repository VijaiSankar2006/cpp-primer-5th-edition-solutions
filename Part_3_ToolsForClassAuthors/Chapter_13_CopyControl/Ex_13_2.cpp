/************************************************************************************************************************************************************
 * @file Ex_13_2.cpp
 * @brief Exercise 13.2: Explain why the following declaration is illegal:
 *              Sales_data::Sales_data(Sales_data rhs);
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * Sales_data::Sales_data(Sales_data rhs);   //  illegal, parameter is not a reference type
 *      in this case, to call the constructor argument should be copied to the parameter, for that copy constructor should be called
 * and for that, we need to copy the argument again copy constructor is called, it goes on indifinitely
 *************************************************************************************************************************************************************/