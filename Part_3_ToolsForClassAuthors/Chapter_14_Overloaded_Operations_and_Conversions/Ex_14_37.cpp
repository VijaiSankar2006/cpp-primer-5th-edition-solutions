/************************************************************************************************************************************************************
 * @file Ex_14_37.cpp
 * @brief Exercise 14.37: Write a class that tests whether two values are equal. Use that object and the library algorithms
 * to write a program to replace all instances of a given value in a sequence.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class test{
    private :
       const std::string lhs;
    public :
        test(const std::string &str) : lhs(str) {}
        bool operator()(const std::string &rhs){
            return lhs == rhs;
        }
};

int main(){
    std::vector<std::string> svec{"alpha","beta","charlie","beta","beta","delta","echo", "beta"};
    int count = std::count_if(svec.begin(), svec.end(), test("beta"));
    std::cout << count << std::endl;
}