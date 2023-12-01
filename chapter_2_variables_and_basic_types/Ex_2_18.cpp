//  Exercise 2.18: 
//  Write code to change the value of a pointer. Write code to change the value to which the pointer points.

#include <iostream>

int main(){
    int i1 = 20, i2 = 40;
    int *ptr = &i1;
    std::cout << *ptr << std::endl;
    ptr = &i2;
    std::cout << *ptr << std::endl;
    *ptr = 50;
    std::cout << i2 << std::endl;
    return 0;
}