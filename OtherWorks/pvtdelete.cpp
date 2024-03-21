/************************************************************************************************************************************************************
 * @file pvtdelete.cpp
 * @brief pvtdelete template 
 * @date 2024-02-21
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#ifndef PVTDELETE_CPP
#define PVTDELETE_CPP

#include <iostream>

template <typename T>
class pvtdelete {
    friend void swap(pvtdelete &lhs, pvtdelete &rhs) {}
    public :
        void operator()(T *ptr) const;      //  deletes the pointer               
};

template <typename T>
void pvtdelete<T>::operator()(T *ptr) const {
    std::cout << "pvtdelete::operator()(T *ptr)";
    delete ptr;
}

#endif