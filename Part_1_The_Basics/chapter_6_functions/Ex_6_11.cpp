/*  Exercise 6.11: Write and test your own version of reset that takes a reference.*/

#include <iostream>

void reset(int &r){
    r = 0;
}

int main(){
    int j = 45, k = 98;
    std::cout << j << " " << k << std::endl;
    reset(j);
    reset(k);
    std::cout << j << " " << k << std::endl;

    return 0;
}