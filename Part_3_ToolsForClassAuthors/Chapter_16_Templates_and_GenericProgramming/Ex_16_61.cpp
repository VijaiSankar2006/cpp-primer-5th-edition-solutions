/************************************************************************************************************************************************************
 * @file Ex_16_61.cpp
 * @brief Exercise 16.61: Define your own version of make_shared.
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include "Ex_16_28_SmartPointer.cpp" 

template <typename type, typename... Args>
shared_ptr<type> make_shared(Args&&... args) {

    //shared_ptr(T *ptr_) : ptr(ptr_), count(new size_t(1)), del(nullptr) {}
    return shared_ptr<type>(new type(std::forward<Args>(args)...));
}

int main() {
    shared_ptr<std::string> str1 = make_shared<std::string>(10,'H');
    str1.setDeleter(DebugDelete());
    std::cout << str1.use_count() << " " << *str1 << std::endl;
    

    return 0;
}