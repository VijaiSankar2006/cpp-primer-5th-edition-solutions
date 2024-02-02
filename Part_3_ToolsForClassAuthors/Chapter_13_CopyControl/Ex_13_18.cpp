/************************************************************************************************************************************************************
 * @file Ex_13_18.cpp
 * @brief Exercise 13.18: Define an Employee class that contains an employee name and a unique employee identifier. Give the
 *  class a default constructor and a constructor that takes a string representing the employee’s name. Each constructor should
 *  generate a unique ID by incrementing a static data member.
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>

class Employee{
public :
    Employee() : id(++count) {}
    Employee(const std::string &name_p) : name(name_p), id(++count) {}  
    void info(){
        std::cout << "id : " << id << " " << "name : " << name << std::endl;
    }

private :
    std::string name;
    size_t id;
    static size_t count;
};

size_t Employee::count = 0;

int main(){
    Employee e1, e2("john sena");
    e1.info();
    e2.info();

    return 0;
}