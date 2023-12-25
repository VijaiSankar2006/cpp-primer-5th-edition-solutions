/*  Exercise 4.11: Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, 
    which is greater than c, which is greater than d.*/

#include <iostream>
int main(){
    int a, b, c, d;
    std::cout << "Enter four numbers : ";
    std::cin >> a >> b >> c >> d;
    if( a > b && b > c && c > d){
        std::cout << "a > b > c > d";
    }else{
        std::cout << "it's not that a > b > c > d";
    }
    
    std::cout << std::endl;
    return 0;
}