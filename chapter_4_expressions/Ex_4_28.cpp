/*  Exercise 4.28: Write a program to print the size of each of the built-in types.*/

#include <iostream>

int main(){
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(long double) << std::endl;
    std::cout << sizeof(bool) << std::endl;
    std::cout << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(unsigned) << std::endl;
    std::cout << sizeof(void) << std::endl;         /*  warning : invalid application of sizeof, but still got 1 printed, as
                                                        a non standard implementation of gcc */

}