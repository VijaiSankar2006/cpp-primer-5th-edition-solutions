/*  Exercise 6.38: Revise the arrPtr function on to return a reference to the array.*/

#include <iostream>

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
// returns a pointer to an array of five int elements
decltype(odd) &arrRef(int i)
{
return (i % 2) ? odd : even; // returns a pointer to the array
}

decltype(odd) *arrPtr(int i){
    return (i % 2) ? &odd : &even;
}
int main(){
    for( auto n : arrRef(1)){
        std::cout << n << " ";
    }

    for( auto n : arrRef(2)){
        std::cout << n << " ";
    }

    std::cout << std::endl;
    for( auto n : *arrPtr(1)){
        std::cout << n << " ";
    }
    
    return 0;
}