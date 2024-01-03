/************************************************************************************************************************************************************
 * @file Ex_9_39.cpp
 * @brief Exercise 9.39: Explain what the following program fragment does:
 * vector<string> svec; 
 * svec.reserve(1024); 
 * string word; 
 * while (cin >> word) 
 *  svec.push_back(word); 
 * svec.resize(svec.size()+svec.size()/2);
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * svec.reserve(1024), allocates a new memory for svec to hold a maximum of 1024 elements with out reallocating
 * while(){}, will keep adding strings to svec as long as the user supplies
 * svec.resize(svec.size() + svec.size()/2), will resize the vector with 50% more elements with empty string than what's added
 * if resize results in more than the capacity of svec, then svec will be reallocated with new larger memory as resize requested
 * or else capacity of svec remains same as resize a vector to smaller size doesn't reduce the capacity, (ie) no deallocation
 * of memory happens.
 * */