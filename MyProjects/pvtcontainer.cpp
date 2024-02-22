/************************************************************************************************************************************************************
 * @file pvtcontainer.cpp
 * @brief pvtcontainer is the template from which base container class will be instantiated
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#ifndef PVTCONTAINER_CPP
#define PVTCONTAINER_CPP

/*
#include <iostream>
#include "pvtmemory.cpp"

template <typename T>
class pvtcontainer {
    typedef size_t size_type;
    
    friend bool operator==(pvtcontainer<T> &lhs, pvtcontainer<T> &rhs);
    friend bool operator!=(pvtcontainer<T> &lhs, pvtcontainer<T> &rhs);
    friend size_type operator<(pvtcontainer<T> &lhs, pvtcontainer<T> &rhs);
    friend size_type operator<=(pvtcontainer<T> &lhs, pvtcontainer<T> &rhs);
    friend size_type operator>(pvtcontainer<T> &lhs, pvtcontainer<T> &rhs);
    friend size_type operator>=(pvtcontainer<T> &lhs, pvtcontainer<T> &rhs);

    protected :
        typedef size_type size_type;
        pvtcontainer();
        pvtcontainer(size_type N);
        virtual ~pvtcontainer();
        std::allocator<T> alloc;
        realloc();

        T *beg;
        T *first_free;
        T *end;
    public :
        T & operator[](size_type N);
        resize(size_type N);
        size_type size();
        size_type empty();
};
*/
#endif