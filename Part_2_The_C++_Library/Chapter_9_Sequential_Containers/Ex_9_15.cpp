/************************************************************************************************************************************************************
 * @file Ex_9_15.cpp    
 * @brief Exercise 9.15: Write a program to determine whether two vector<int>s are equal.
 * @date 2023-12-29 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec1{1,3,5,7,9,11};
    std::vector<int> ivec2{2};
    std::vector<int> ivec3{1,3,7,9,};
    std::vector<int> ivec4{1,3,5,7,9,11,1};
    std::vector<int> ivec5(ivec1);

    // relational operators compare two vectors of same element type in dictionary order (ie) {1,23,45} < {2}
    std::cout << "ivec1 > ivec2 : " << (ivec1 > ivec2 ? "true" : "false") << std::endl;         //   false
    std::cout << "ivec1 > ivec3 : " << (ivec1 > ivec3 ? "true" : "false") << std::endl;         //   false
    std::cout << "ivec1 > ivec4 : " << (ivec1 > ivec4 ? "true" : "false") << std::endl;         //   false    
    std::cout << "ivec1 == ivec5 : " << (ivec1 == ivec5 ? "true" : "false") << std::endl;       //   true

    if(ivec2 < ivec3){
        std::cout << "ivec2 < ivec3" ;
    }else if(ivec2 == ivec3){
        std::cout << "ivec2 == ivec3";
    }else{
        std::cout << "ivec2 > ivec3";       //  true
    }
    return 0; 

}
