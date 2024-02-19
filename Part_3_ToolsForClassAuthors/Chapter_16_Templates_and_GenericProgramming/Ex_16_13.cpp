/************************************************************************************************************************************************************
 * @file Ex_16_13.cpp
 * @brief Exercise 16.13: Explain which kind of friendship you chose for the equality and relational 
 * operators for BlobPtr.
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * one to one friendship for both the classes. As equality and relational operators are implemented as non-member non-template
 * functions they are declared and defined as inline in the class template, which results in to generating these operators
 * seperatly for each instantiation. 
 *      ex :-   
 *              operator==(const Blob<int> &lhs, const Blob<int> &rhs) will be friend of Blob<int>, but it cannot access
 * the data of Blob<char>.
 *              (ie) for every instantiation of Blob class template, there exists a unique definition of both of these
 * operators. 
 *              
 * 
 *************************************************************************************************************************************************************/