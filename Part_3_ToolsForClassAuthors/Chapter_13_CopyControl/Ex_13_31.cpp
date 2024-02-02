/************************************************************************************************************************************************************
 * @file Ex_13_31.cpp
 * @brief Exercise 13.31: Give your class a < operator and define a vector of HasPtrs. Give that vector some elements and then
 * sort the vector. Note when swap is called
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

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

    // comparison operator
    bool operator<(const HasPtr &rhs){
        std::cout << *ps << " < " << *rhs.ps << std::endl;
        return *ps < *rhs.ps;
    }

    void info(){
        std::cout << ps << " " << *ps << " " << i << std::endl;
    }

    std::string & get_val(){
        return *ps;
    }
private :
    std::string* ps;
    int i;
};
void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "successfully swaped" << std::endl;
}

int main(){
    std::string str1("gamma"), str2("alpha"), str3("ray"), str4("delta"), str5("alpha"), str6("beta"), str7("zebra");
    std::vector<HasPtr> hpvec{str1,str2,str3,str4,str5,str6,str7};

    for(auto &hp : hpvec){
        std::cout << hp.get_val() << " ";
    }
    std::cout << std::endl;

    std::sort(hpvec.begin(), hpvec.end());
    std::cout << "after sorted" << std::endl;
    for(auto &hp : hpvec){
        std::cout << hp.get_val() << " ";
    }
    std::cout << std::endl;

    return 0;
}