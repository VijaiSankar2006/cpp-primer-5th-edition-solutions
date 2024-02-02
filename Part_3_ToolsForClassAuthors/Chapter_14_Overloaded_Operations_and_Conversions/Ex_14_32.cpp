/************************************************************************************************************************************************************
 * @file Ex_14_32.cpp
 * @brief Exercise 14.32: Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that
 * class.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include "Ex_14_30_StrBlob.cpp"

class ptrToStrBlobPtr {
    public :
        ptrToStrBlobPtr() : ptr(nullptr) {}
        ptrToStrBlobPtr(StrBlobPtr &&iter) : ptr(&iter) {}
        StrBlobPtr & operator*();
        StrBlobPtr * operator->();
    private :
        StrBlobPtr * ptr;
};

StrBlobPtr & ptrToStrBlobPtr::operator*(){
    return *ptr;
}

StrBlobPtr * ptrToStrBlobPtr::operator->(){
    return ptr;
}

int main(){
    StrBlob b1{"alpha","beta", "gamma"};
    ptrToStrBlobPtr p = b1.begin();
    std::cout << p->deref() << std::endl;
    
}