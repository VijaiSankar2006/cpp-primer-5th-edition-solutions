/* Exercise 6.3: Write and test your own version of fact. */

#include <iostream>

//  fact function takes an int parameter and returns the result in integral type
int fact(int num){
    int res = 1;
    for(int i = 1; i <= num; ++i){    //  for loop will multiply 1 * 2 *... * num
        res *= i ;
    }
    return res;
}

int main(){

    std::cout << fact(5) << std::endl;
    std::cout << fact(10) << std::endl;

    return 0;
}