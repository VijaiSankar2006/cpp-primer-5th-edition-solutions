/************************************************************************************************************************************************************
 * @file Ex_16_21.cpp
 * @brief Exercise 16.21: Write your own version of DebugDelete.
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>


class DebugDelete {
    public :
       DebugDelete() {} 
       DebugDelete(const DebugDelete &source) = default;
       DebugDelete(DebugDelete &&source) = default;
       DebugDelete & operator=(const DebugDelete &rhs) = default;
       DebugDelete & operator=(DebugDelete &&rhs) = default;

       template <typename Type>
       void operator()(Type *p) const {
            std::cout << "pointer is deleted successfully" << std::endl;
            delete p;
       }

       ~DebugDelete() = default;
};

