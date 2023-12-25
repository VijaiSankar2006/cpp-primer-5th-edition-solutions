/*  Exercise 3.14: Write a program to read a sequence of ints from cin and store those values in a vector. */

#include <iostream>
#include <vector>

int main(){
    std::cout << "Enter a list of numbers : \n";
    std::vector<int> ivec;
    int num;
    while( std::cin >> num ){
        ivec.push_back(num);        //  pushes back 'num' at the bact of ivec
    }

    std::cout << "The list of numbers entered : \n";
    for( auto n : ivec ){
        std::cout << n << " ";
    }

    return 0;
}
