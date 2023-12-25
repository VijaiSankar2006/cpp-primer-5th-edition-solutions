/*  Exercise 3.35: Using pointers, write a program to set the elements in an array to zero. */

#include <iostream>
#include <iterator>

int main(){
    constexpr size_t size{10};
    int ia[size];
    int *b = std::begin(ia);
    int *e = std::end(ia);

    while( b != e){
        *b = 0;
        ++b;
    }

    b = std::begin(ia);
    while(  b != e ){
        std::cout << *b++ << " ";
    }

    return 0;
    
}