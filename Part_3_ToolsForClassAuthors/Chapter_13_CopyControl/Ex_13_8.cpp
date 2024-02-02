/************************************************************************************************************************************************************
 * @file Ex_13_8.cpp
 * @brief Exercise 13.8: Write the assignment operator for the HasPtr class from exercise 13.5 in § 13.1.1 (p. 499). As with
 * the copy constructor, your assignment operator should copy the object to which ps points.
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
private :
    std::string* ps;
    int i;
};

int main(){
    HasPtr hp1("hello"), hp2("hello world");
    std::cout << "hp1 : " ; hp1.info();
    std::cout << "hp2 : " ; hp2.info();

    hp1 = hp2;
    std::cout << "hp1 = hp2 \n";
    std::cout << "hp1 : " ; hp1.info();
    std::cout << "hp2 : " ; hp2.info();
    
    return 0;
}