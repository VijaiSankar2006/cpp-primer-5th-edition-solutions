/*  Exercise 3.32: Copy the array you defined in the previous exercise into another array. Rewrite your program to use 
    vectors. */

#include <iostream>
#include <vector>

int main(){
    constexpr size_t SZ(10);
    int ia[SZ];

    for( size_t i = 0; i < SZ; ++i){
        ia[i] = i;
    }

    std::vector<int> ivec;
    for( auto n : ia){
        ivec.push_back(n);
    }

    std::cout << "ivec contains : ";
    for( auto n : ivec){
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
