/*  Exercise 3.41: Write a program to initialize a vector from an array of ints */

#include <iostream>
#include <vector>
#include <iterator>

int main(){
    int ia[] = {1,2,3,4,5,12,23,34,56};
    std::vector<int> ivec(std::begin(ia), std::end(ia));
    for( auto n : ivec){
        std::cout << n << " ";
    }

    return 0;
}