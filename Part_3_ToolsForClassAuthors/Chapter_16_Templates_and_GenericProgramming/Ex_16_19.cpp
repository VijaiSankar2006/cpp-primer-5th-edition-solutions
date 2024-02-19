/************************************************************************************************************************************************************
 * @file Ex_16_19.cpp
 * @brief Exercise 16.19: Write a function that takes a reference to a container and prints the elements in that container.
 *  Use the container’s size_type and size members to control the loop that prints the elements.
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>

template <typename T> 
void print(const T & seq) {
    typename T::size_type sz = seq.size();

    for (size_t i = 0; i != sz; ++i) {
        std::cout << seq[i] << " " ;
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

