/************************************************************************************************************************************************************
 * @file Ex_7_43.cpp
 * @brief Exercise 7.43: Assume we have a class named NoDefault that has a constructor that takes an int, but has no default
 *        constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C
 * @date 2023-12-22
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>

class NoDefault {
public :
    NoDefault(int val) : data(val) { std::cout << "NoDefault(int val) : invoked" << std::endl;};
private :
    int data;
};

class C{
public :
    C() = default;   // compiler will synthesis a default constructor
    /**
     * C() {} -- explicitly defined default constructor
    */
private :
    NoDefault nddata;
};

int main(){
    C cobj;         
    return 0;
}

/**
 * Output : constructor with default declaration
 * error: use of deleted function ‘C::C()’
 *      C cobj;
 * ‘C::C()’ is implicitly deleted because the default definition would be ill-formed: 
 *      C() = default;  
 * error: no matching function for call to ‘NoDefault::NoDefault()’
 * ‘NoDefault::NoDefault(int)’
 *      NoDefault(int val) : data(val) { std::cout << "NoDefault(int val) : invoked" << std::endl;};
 *      candidate expects 1 argument, 0 provided
*/

/**
 * Output : default constructor explicitly defined
 * In constructor ‘C::C()’:
 * error: no matching function for call to ‘NoDefault::NoDefault()’
 *     C(){}
 *        ^
 * note: candidate: ‘NoDefault::NoDefault(int)’
 *    NoDefault(int val) : data(val) { std::cout << "NoDefault(int val) : invoked" << std::endl;};
 *              ^~~~~~~~~
 * candidate expects 1 argument, 0 provided
*/