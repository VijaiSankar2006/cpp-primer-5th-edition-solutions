/*  Exercise 3.42: Write a program to copy a vector of ints into an array of ints   */

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec{11,21,31,41,51,61,71,81,91,101};
    int ia[10];

    for( size_t i = 0; i < 10; ++i ){
        ia[i] = ivec[i];
    }

    for( auto b = std::begin(ia); b != std::end(ia); ++b){
        std::cout << *b << " ";
    }

    return 0;
}