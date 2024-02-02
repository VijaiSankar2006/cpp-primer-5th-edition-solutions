/************************************************************************************************************************************************************
 * @file Ex_13_5.cpp
 * @brief Exercise 13.5: Given the following sketch of a class, write a copy constructor that copies all the members. Your 
 * constructor should dynamically allocate a new string(§ 12.1.2, p. 458) and copy the object to which ps points, rather 
 * than copying ps itself.
 * class HasPtr {
 * public:
 *      HasPtr(const std::string &s = std::string()):
 *      ps(new std::string(s)), i(0) { }
 * private:
 *      std::string *ps;
 *      int i;
 * };
 * @date 2024-01-22
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
private:
    std::string* ps;
    int i;
};

int main(){
    HasPtr obj1("hello world");
    HasPtr obj2 = obj1;
    obj1.info();
    obj2.info();

    return 0;
}
