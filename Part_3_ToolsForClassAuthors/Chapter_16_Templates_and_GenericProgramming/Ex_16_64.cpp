/************************************************************************************************************************************************************
 * @file Ex_16_64.cpp
 * @brief Exercise 16.64: Write a specialized version of the template from the previous exercise to handle 
 * vector<const char*> and a program that uses this specialization. 
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>

template <typename T>
size_t count(const std::vector<T> &tvec, const T val) {
    std::cout << "general template" << std::endl;
    size_t cnt = 0;
    for(auto beg = tvec.begin(); beg != tvec.end(); ++beg) {
        if (*beg == val) {
            ++cnt;
        }
    }

    return cnt;
}


template <>  //  tells the compiler this is template specialisation of previously declared template
size_t count(const std::vector<const char *> &tvec, const char * const val) {   // const T == const (const char *) == const char * const ,as const (*) is const pointer(* const) 
    size_t cnt = 0;                                                             //            ^^^^^                                ^^^^^ 
    for (auto beg = tvec.begin(); beg != tvec.end(); ++beg) {
        if( strcmp(*beg, val) == 0 ) {
            ++cnt;
        }
    }

    return cnt;
}

int main() {

    std::vector<const char *> cvec{"alpha", "beta", "gamma", "alpha", "alpha"};
    const char *wptr = "alpha";
    std::cout << count(cvec, "alpha") << std::endl;

   
}