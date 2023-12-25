/*  Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap
 *  the value of two ints. Which version do you think would be easier to use and why? */

#include <iostream>

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){
    int first = 89, second = 123;
    std::cout << "original sequence : " << first << " " << second << std::endl;
    swap(first, second);
    std::cout << "swaped sequence : " << first << " " << second << std::endl;

    return 0;
}