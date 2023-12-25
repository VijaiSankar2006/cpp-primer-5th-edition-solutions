/*  Exercise 7.5: Provide operations in your Person class to return the name and address. Should these functions be const?
 *  Explain your choice */

#include <iostream>
#include <string>

struct Person{
    std::string get_name() const;
    std::string get_address() const;
    std::string name;
    std::string address;
};  
/*  as get_name() and get_address doesn't need write access to the object, these functions are declared as const member
 *  functions */

std::string Person::get_name() const {
    return name;
}

std::string Person::get_address() const {
    return address;
}

