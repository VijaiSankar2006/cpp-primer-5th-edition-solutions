/************************************************************************************************************************************************************
 * @file Ex_16_20.cpp
 * @brief Exercise 16.20: Rewrite the function from the previous exercise to use iterators returned from begin and 
 * end to control the loop.
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>

template <typename T> 
void print(const T & seq) {
    typename T::const_iterator beg = seq.begin(), end = seq.end();
       
    while (beg != end) {  //  auto deducing the type is much simpler( auto iter = seq.begin())
        std::cout << *beg++ << " " ;
    }

    std::cout << std::endl;

}

int main() {
    std::vector<std::string> svec{"alpha", "beta", "gamma"};
    std::vector<int> ivec{1,3,5,7,9};
    print(svec);  //  template parameter type will be automatically deduced as std::vector<std::string>
    print(ivec);  //  template parameter type will be automatically deduced as std::vector<std::int>
    return 0;
}