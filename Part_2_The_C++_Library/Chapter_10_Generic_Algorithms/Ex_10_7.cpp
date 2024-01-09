/************************************************************************************************************************************************************
 * @file Ex_10_7.cpp
 * @brief Exercise 10.7: Determine if there are any errors in the following programs and, if so, correct the error(s):
 * (a) vector<int> vec; 
 *     list<int> lst; 
 *     int i;
 *     while (cin >> i)
 *          lst.push_back(i);
 *     copy(lst.cbegin(), lst.cend(), vec.begin());
 * (b) vector<int> vec;
 *     vec.reserve(10); // reserve is covered in § 9.4 (p. 356) 
 *     fill_n(vec.begin(), 10, 0);
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 *  (a) error : vec is empty, need to use insert iterator to add new elements
 *  (b) error : reserve only increases the capacity, but still vec is empty (ie) vec.size() == 0
*/