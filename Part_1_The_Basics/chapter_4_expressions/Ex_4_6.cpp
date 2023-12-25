/*  Exercise 4.6: Write an expression to determine whether an int value is even or odd*/

#include <iostream>

int main(){
    std::cout << "Enter a number : ";
    int num;
    std::cin >> num;
    std::cout << std::endl;
    if( num % 2 ){
        std::cout << num << " is odd" << std::endl;
    }else{
        std::cout << num << " is even" << std::endl;
    }

    return 0;
}