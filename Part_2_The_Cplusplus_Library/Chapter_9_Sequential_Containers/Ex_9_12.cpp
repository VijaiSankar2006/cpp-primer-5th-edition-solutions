/************************************************************************************************************************************************************
 * @file Ex_9_12.cpp
 * @brief Exercise 9.12: Explain the differences between the constructor that takes a container to copy and the constructor
 *        that takes two iterators.
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 *  Container_type c(d) : c is copy initialise with each element from d, where as c and d should be same container type and the
 *                        element type should be same.
 *  Container_type c(b,e) : b and e forms a range with b refers to first element and e to one past the last element in the range
 *                          the element type shoule be same or convertible to the container's element type, container type need not
 *                          be same.
 *  ex :- vector<int> ivec{1,2};
 *        list<int> ilst(ivec)   // error : container type is different
 *        list<int> ilst(ivec.begin(), ivec.end())  // ok : element type is same
 *        vector<double> dvec(ivec)  //  error : element type is different;
 *        vector<double> dvec{ilst.begin(), ilst.end()} // ok : element type is compatible
*/