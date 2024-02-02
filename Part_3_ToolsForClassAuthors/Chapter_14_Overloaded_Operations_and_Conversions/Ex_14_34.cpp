/************************************************************************************************************************************************************
 * @file Ex_14_34.cpp
 * @brief Exercise 14.34: Define a function-object class to perform an if-then-else operation: The call operator for this 
 * class should take three parameters. It should test its first parameter and if that test succeeds, it should return its
 * second parameter; otherwise, it should return its third parameter.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include <iostream>

class which{
    public :
        int operator()(int n1, int n2, int n3){
            return n1 % 2 ? n2 : n3;
        }
};



int main(){
    which w;
    std::cout << w(1,34,56) << std::endl;
    std::cout << w(2,34,56) << std::endl;

    return 0;
}