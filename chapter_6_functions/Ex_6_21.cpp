/*  Exercise 6.21: Write a function that takes an int and a pointer to an int and returns the larger of the int value or
 *  the value to which the pointer points. What type should you use for the pointer? */

    /*  return type is int as first parameter is a local copy.
     *  pointer type is pointer to const as the value is not going to modified */

#include <iostream>

//  function to get the bigger integral value out of two
int maxInt(const int val1,const int *val2ptr){
        return val1 > *val2ptr ? val1 : *val2ptr;
}

int main(){
    int val1 = 23, val2 = 45;

    std::cout << maxInt(val1, &val2) << std::endl;
    std::cout << maxInt(56,&val2) << std::endl;

    return 0; 
}

    