/************************************************************************************************************************************************************
 * @file Ex_13_19.cpp
 * @brief Exercise 13.19: Does your Employee class need to define its own versions of the copy-control members? If so, why? 
 * If not, why not? Implement whatever copy-control members you think Employee needs.
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * synthesised copy_constructor will copy the id from the source, objects will not have unique id
 * synthesised copy_assignment operator also results in id being duplicated
 * so, inorder for the objects to have unique id, we must define all copy_control members except destructor
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>

class Employee{
public :
    Employee() : id(++count) {}
    Employee(const std::string &name_p) : name(name_p), id(++count) {}  
    Employee(const Employee &source) : name(source.name), id(++count) {}
    Employee & operator=(const Employee &rhs) {
        name = rhs.name;
    }

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
    Employee e1, e2("john sena"), e3("george");
    Employee e4(e2);
    e1.info();
    e2.info();
    e3.info();
    e4.info();
    e4 = e3;
    e4.info();

    return 0;
    
}