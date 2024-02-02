/************************************************************************************************************************************************************
 * @file Ex_13_46.cpp
 * @brief Exercise 13.46: Which kind of reference can be bound to the following initializers?
 * int f();
 * vector<int> vi(100);
 * int? r1 = f();
 * int? r2 = vi[0];
 * int? r3 = r1;
 * int? r4 = vi[0] * f();
 * @date 2024-01-27
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * int f();
 * vector<int> vi(100);
 * int? r1 = f();   //  rvalue reference, as the return type is non-reference
 * int? r2 = vi[0]; //  lvalue reference, as the subcript operator yields the lvalue reference
 * int? r3 = r1;    //  lvalue reference, though the r1 is an rvalue reference, an expression consisting only a variable yields lvalue and lvalue doesn't steal from an object
 * int? r4 = vi[0] * f();   // rvalue reference, an arithmatic operator yields an rvalue
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

int f(){ return 10; }
int main(){
    std::vector<int> vi(100);
    int &&r1 = f();
    int &r2 = vi[0];
    r2 = 65;
    int &r3 = r1;
    r3 = r3 * 5;
    int &&r4 = vi[0] * f();
    r4 = 10000;
    std::cout << r1 << " " << r2 << " " << r3 << " " << r4 << std::endl;
    std::vector<int &&> vrr{r1, r4};
    std::cout << vrr[0] << " " << vrr[1] << std::endl;
     return 0;
}