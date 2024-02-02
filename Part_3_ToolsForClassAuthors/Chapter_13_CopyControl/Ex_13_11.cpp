/************************************************************************************************************************************************************
 * @file Ex_13_11.cpp
 * @brief Exercise 13.11: Add a destructor to your HasPtr class from the previous exercises
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>
class HasPtr {
public:
    HasPtr(const std::string& s = std::string())
        : ps(new std::string(s)), i(0){}
    HasPtr(const HasPtr& hp) : ps(new std::string(*(hp.ps))), i(hp.i) {
        std::cout << "copy constructor called" << std::endl;
    } 
    void info(){
        std::cout << ps << " " << *ps << " " << i << std::endl;
    }
    HasPtr & operator=(const HasPtr &source){
        *ps = *(source.ps);
        i = source.i;

        return *this;
    }
    ~HasPtr(){
        delete ps;
        std::cout << "destructor is run and the memory allocated to hold the string is deleted" << std::endl;
    }

private :
    std::string* ps;
    int i;
};

int main(){
    HasPtr hp1("hello");
    {
        HasPtr hp2("world");
    } 

    return 0;

}