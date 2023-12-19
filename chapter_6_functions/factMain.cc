//  contains main() which uses the functions defined in fact.cc

#include <iostream>
#include "Chapter6.h"

int main(){

    std::cout << std::endl;
    std::cout << getFactorial(5) << std::endl;
    factorial();
    std::cout  << std::endl;

    return 0;
}