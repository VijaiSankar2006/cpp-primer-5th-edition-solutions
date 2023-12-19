/*  Exercise 6.7: Write a function that returns 0 when it is first called and then generates numbers in sequence each time
    it is called again */

#include <iostream>

//  counter takes no parameters and returns the no of times it is called
int counter(){      
    static size_t count = 0;        //  count is a local static varible, its value persists across function call
    return count++;
}

int main(){

    for(int i = 0; i <= 10; ++i){
        std::cout << counter() << " ";
    }
    std::cout << std::endl;

    return 0;
}