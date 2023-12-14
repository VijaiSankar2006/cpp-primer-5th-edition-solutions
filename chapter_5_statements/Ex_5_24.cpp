/*  Exercise 5.24: Revise your program to throw an exception if the second number is zero. Test your program with a zero
    input to see what happens on your system if you don’t catch an exception.*/

#include <iostream>
#include <stdexcept>
int main(){
    std::cout << "Enter two integers : ";
    int num1, num2;
    std::cin >> num1 >> num2;
    if(!num2){
        throw std::domain_error("division by zero");
    }
    std::cout << num1 << " / "<< num2 << " " << num1/num2 << std::endl;

    return 0;
}