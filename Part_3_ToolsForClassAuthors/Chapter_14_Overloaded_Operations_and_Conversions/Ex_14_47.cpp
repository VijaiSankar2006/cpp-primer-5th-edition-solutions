/************************************************************************************************************************************************************
 * @file Ex_14_47.cpp
 * @brief Exercise 14.47: Explain the difference between these two conversion operators:
 * struct Integral {
 *      operator const int();
 *      operator int() const;
 * };
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 *  operator const int(), represents conversion from Integral to const int but type qualifier is ignored as there is no return type
 *  operator int(), represents conversion from const Integral to int (ie) a const member function
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>

struct Integral{
    Integral(int val_) : val(val_) {}
    operator int() { return val + 10; }
    operator int() const { return val + 100; }
    int val;
};

int main(){
    Integral i1(456);
    const Integral i2(567);
    std::cout << 1 + i1 << std::endl;
    std::cout << 1 + i2 << std::endl;
}