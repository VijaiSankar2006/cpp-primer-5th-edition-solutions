/************************************************************************************************************************************************************
 * @file Ex_10_26.cpp
 * @brief Exercise 10.26: Explain the differences among the three kinds of insert iterators.
 * @date 2024-01-06
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/**
 * insert iterators :
 *      - back_inserter(c), takes a container,c and returns a insert iterator which when assigned calls push_back(val) on the container
 *      - front_inserter(c), takes a container,c and returns a insert iterator which when assigned calls push_front(val) on the container
 *      - inserter(c, iter), takes a container,c and iterator to the container and returns a insert iterator when assigned calls insert()
 *        to insert the val just before the element pointed by the iter. Regardless of how many times we call, inserter() always calls inserts
 *        just before the iter.
*/

