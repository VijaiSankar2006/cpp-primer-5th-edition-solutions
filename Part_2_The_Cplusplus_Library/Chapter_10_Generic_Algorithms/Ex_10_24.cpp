/************************************************************************************************************************************************************
 * @file Ex_10_24.cpp
 * @brief Exercise 10.24: Use bind and check_size to find the first element in a vector of ints that has a value greater than 
 *        the length of a specified string value.
 * @date 2024-01-06
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>

using std::placeholders::_1;

bool checksz(const int n, const std::string &str){
    return n > static_cast<int>(str.size());
}

int main(){
    
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
    std::string szword("english");
    auto iter = std::find_if(ivec.begin(), ivec.end(), std::bind(checksz, _1, szword));
    std::cout << "the first element is greater than the size of \"english\" : " << *iter << std::endl;

    return 0;
}