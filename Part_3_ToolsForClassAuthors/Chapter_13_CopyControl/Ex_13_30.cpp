/************************************************************************************************************************************************************
 * @file Ex_13_30.cpp
 * @brief Exercise 13.30: Write and test a swap function for your valuelike version of HasPtr. Give your swap a print 
 * statement that notes when it is executed.
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>

//  class defined to behave like value, (ie) object's state is independent from the other
class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    // constructor that takes a string with empty string as a default value to behave as default constructor
    HasPtr(const std::string& s = std::string())
        : ps(new std::string(s)), i(0){}

    // copy constructor    
    HasPtr(const HasPtr& hp) : ps(new std::string(*(hp.ps))), i(hp.i) {
        std::cout << "copy constructor called" << std::endl;
    } 

    // copy-assignment operator
    HasPtr & operator=(HasPtr rhs){
        swap(*this, rhs);
        return *this;
    }

    // destructor 
    ~HasPtr(){
        delete ps;
        std::cout << "destructor is run and the memory allocated to hold the string is deleted" << std::endl;
    }

    void info(){
        std::cout << ps << " " << *ps << " " << i << std::endl;
    }
private :
    std::string* ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "successfully swaped";
}

int main(){
    HasPtr hp1("hello"), hp2("world");
    hp1.info();
    hp2.info();
    {
        HasPtr hp3(hp2);
        hp3.info();
        hp3 = hp1;
        hp3.info();
        std::cout << "after assignment" << std::endl;
    }

}