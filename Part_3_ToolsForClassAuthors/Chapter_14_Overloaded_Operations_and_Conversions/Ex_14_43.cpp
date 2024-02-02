/************************************************************************************************************************************************************
 * @file Ex_14_43.cpp
 * @brief Exercise 14.43: Using library function objects, determine whether a given int value is divisible by any element
 *  in a container of ints.
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <functional>
#include <vector>

using std::placeholders::_1;
class IsDivisible{
    public :
        IsDivisible(int val) : dividend(val) {}
        bool operator()(int val){
            return std::modulus<int>()(val, dividend) == 0;
        }
    private :
        int dividend;
};
int main(){
    std::vector<int> ivec{2,3,4,5,6,7,8,9,10};
    int val = 13;

    bool res = std::any_of(ivec.begin(), ivec.end(), IsDivisible(val));
    std::cout << res << std::endl;
}