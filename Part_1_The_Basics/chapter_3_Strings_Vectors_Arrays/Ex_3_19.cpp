/*  Exercise 3.19: List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether 
    there is a preferred way to do so and why.  */


#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec1(10,42);    //  creates a vector of int type initialised with 10 elements of vale 42 each
    std::vector<int> ivec2{42,42,42,42,42,42,42,42,42,42};  //  creates a vector of int type and list initialises with 10 elements of value 42 each
    std::vector<int> ivec3;     //  creates a empty vector
    //  this pushes value 42, 10 times in to ivec3
    for( size_t i = 0; i < 10 ; ++i){
        ivec3.push_back(42);
    }

    std::cout << "ivec1 : [size : " << ivec1.size() << ", values : ";
    for( auto n : ivec1){
        std::cout << n << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "\nivec2 : [size : " << ivec2.size() << ", values : ";
    for(auto n : ivec2){
        std::cout << n << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "\nivec3 : [size : " << ivec3.size() << ", values : ";
    for(auto n : ivec3){
        std::cout << n << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}


//  if no of elements is known and if all the elements are of same value, then 1st method(ivec1(10,42)) is simple and error less