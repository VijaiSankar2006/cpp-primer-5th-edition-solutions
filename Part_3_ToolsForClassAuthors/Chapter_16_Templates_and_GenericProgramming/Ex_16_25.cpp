/************************************************************************************************************************************************************
 * @file Ex_16_25.cpp
 * @brief Exercise 16.25: Explain the meaning of these declarations:
 * extern template class vector<string>; 
 * template class vector<Sales_data>;
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/***********************************************************************************************************************************************************
 *  extern template class vector<string>;  //  instantiation declaration, which promises the compiler that somewhere else
 * a non-extern usage of the instantiation will be present so compiler won't generate code for instantiation in this file.This
 * is done to avoid multiple instantiations of same type or same function type in the program.
 * 
 * template class vector<Sales_data>;    //  explicit instantiation definition, when compiler sees this, it generates or 
 * instantiates the class with all the all the members, as the compiler have no idea what members will be used.
 * 
 *************************************************************************************************************************************************************/