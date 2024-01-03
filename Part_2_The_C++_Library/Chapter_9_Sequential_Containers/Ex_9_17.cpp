/************************************************************************************************************************************************************
 * @file Ex9_17.cpp
 * @brief Exercise 9.17: Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types
 *        of c1 and c2?
                if (c1 < c2)
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/*  c1 and c2 must be same container type and have same element type.
 *  vector<int>(1) < vector<double>(1.0)  // error : different element type
 *  list<int>(1) < vector<int>(1)         // error : different container type
 *  vector<int>(1) < vector<int>({1,2,3}) // ok : same vector type, same element type int
 * */