//  contains the definitions of getFactorial() and factorial()

#include "Chapter6.h"   //  contains the declarations of functions defined here
#include <iostream>

//  definition of getFactorial() function
int getFactorial(int num){
    int result = 1;
    for(int i = 1; i <= num; ++i ){
        result *= i;
    }
    return result;
}

//  definition of factorial function 
void factorial(){
    std::cout << "Enter a number : ";
    int num;
    std::cin >> num;
    std::cout << getFactorial(num) << std::endl;
}

