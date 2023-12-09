/*  Exercise 3.36: Write a program to compare two arrays for equality. Write a similar program to compare two vectors.*/

#include <iostream>
#include <vector>

int main(){
    constexpr size_t size{10};
    int ia1[size] = {1,2,3,4,5,6,7,8,9,10};
    int ia2[size] = {1,2,3,4,5,6,7,8,9,10};

    auto b1 = std::begin(ia1), b2 = std::begin(ia2);
    auto e1 = std::end(ia1), e2 = std::end(ia2);
    if( (e1 - b1) != (e2 - b2)){
        std::cout << "both arrays are not equal";
    }else{
        while( b1 != e1){
            if( *b1++ != *b2++ ){
                std::cout << "both arrays are not equal";
                break;
            }
        }
        if( b1 == e1 ){
            std::cout << "both arrays are equal";
        }

    }
    std::cout << std::endl;

    std::vector<int> ivec1{1,2,3,4,5,6,7,8,9,10}, ivec2{1,2,3,4,5,6,7,8,9,10};
    if( ivec1 == ivec2) {
        std::cout << "Both vectors are equal ";
    }else{
        std::cout << "Both vectors are not equal";
    }
    std::cout << std::endl;
    return 0;   
}
