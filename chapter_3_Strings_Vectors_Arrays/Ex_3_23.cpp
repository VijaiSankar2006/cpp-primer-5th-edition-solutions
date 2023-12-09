/*  Exercise 3.23: Write a program to create a vector with ten int elements. Using an iterator, assign each element a value
 *  that is twice its current value. Test your program by printing the vector.  */

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec{1,2,3,4,5,6,11,22,33,44};

    for( auto beg = ivec.begin(); beg != ivec.end(); ++beg ){
        *beg = *beg * *beg;
    }

    for( auto beg = ivec.begin(); beg != ivec.end(); ++beg ){
        std::cout << *beg << " ";
    }

    return 0;

}