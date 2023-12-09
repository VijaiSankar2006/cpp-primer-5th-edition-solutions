/*  Exercise 3.31: Write a program to define an array of ten ints. Give each element the same value as its position in the
    array.  */

#include <iostream>

int main(){
    constexpr size_t SZ = 10;
    int ia[SZ];

    for( size_t i = 0; i < SZ; ++i ){
        ia[i] = i;
    }

    for( auto n : ia ){
        std::cout << n << " ";
    }

    return 0;
}