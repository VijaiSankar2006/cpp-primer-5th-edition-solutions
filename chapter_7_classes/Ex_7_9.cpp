/*  Exercise 7.9: Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260)*/

#include <iostream>

struct Person{
    std::string name;
    std::string address;
};

std::istream & read(std::istream &is, Person &item){
    is >> item.name >> item.address;
    return is;
}

std::ostream & print(std::ostream &os,const Person &item){
    os << item.name << item.address;
    return os;
}


