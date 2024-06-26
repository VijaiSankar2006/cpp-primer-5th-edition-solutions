/************************************************************************************************************************************************************
 * @file Ex_10_38.cpp
 * @brief Exercise 10.38: List the five iterator categories and the operations that each supports.
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

ITERATOR CATEGORIES 
    1. Input iterators : reads an element in a sequence, single pass only, supports 
             ++, pre and post increment operator
             ==, != equality comparison operator 
             *, dereference operator to get the value, can only be right hand side of the assignment
             ->, inshort of (*iter).member, member access operator to get the member of the underlying object
        can be used only sequentialy, so incrementing invalidates all other iterators to the stream, so state of iter cannot be saved 
        ex:- istream_iterator
             find, count algorithm requires one

    2. Output iterators : writes an element, single pass only, support 
             ++, pre and post increment operator
             ==, != equality comparison operator
             *, deference operator, when a value is assigned writes to the sequence, can only on the left hand side of the assignment
        ex:- ostream_iterator, destination iterator
             third argument of copy algorithm

    3. Forward iterators : reads and writes elements, multi pass but only in forward directions, so state of the iterator can be saved. supports
             all the operations of input and output iterators
        ex:- iterators provided by forward_list, 
             replace algorithm requires one

    4. Bidirectional iterators : reads and writes, multi pass in both direction
             all the operations of forward iterators
             --, pre and post decrement operators
        ex:- reverse algorithm requires one 
             except forward_list all library containers iterators meet the requirments of bidirectional iterator    

    5. Random Access iterators : reads and writes, provides constant time access to any position in the sequence
            all of Bidirectional iterators
            along with equality, all relative operators 
            +,-,+=,-= on an iterator and an integral 
            - on two iterators gives the distance of one from the other
            [], subscript operator in short of *(iter + 1)
        ex:- sort algorithm requires one 
             vector, deque, array, string and pointers of built-in array are random access iterators.
