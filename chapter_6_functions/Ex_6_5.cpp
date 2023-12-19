/*  Exercise 6.5: Write a function to return the absolute value of its argument.*/

#include <iostream>

// absValue takes int parameter and return int type
int absValue(int num){   
    return num < 0 ? -num : num ;   //  absolute value of -n is n and n is n itself  
}

int main(){
    std::cout << "the absolute value of -3 : " << absValue(-3) << std::endl;
    std::cout << "the absolute value of 3 : " << absValue(3) << std::endl;
    return 0;
}