/************************************************************************************************************************************************************
 * @file pvtmake_shared.cpp
 * @brief pvtmake_shared template 
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#ifndef PVTMEMORY
#define PVTMEMORY

#include <iostream>
#include <memory>
#include <utility>
#include "pvtsmart_ptr.cpp"
#include "pvtshared_ptr.cpp"
#include "pvtunique_ptr.cpp"

template <typename T> class pvtshared_ptr;

template <typename T, typename... Args>
pvtshared_ptr<T> pvtmake_shared(Args&&... args) {
    T *p = new T(std::forward<Args>(args)...);
    pvtshared_ptr<T> sp(p);
    return sp;
}

#endif