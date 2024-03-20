/************************************************************************************************************************************************************
 * @file Ex_17_1.cpp
 * @brief Exercise 17.1: Define a tuple that holds three int values and initialize the members to 10, 20, and 30
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <tuple>

int main() {
    // tuple definition std::tuple<T1, T2, T3...., Tn> tuple_name(init1, init2, init3...., initn);
    std::tuple<int, int, int> t1(10,20,30);  

    std::cout << "The tuple contains : ";
    std::cout << std::get<0>(t1) << " ";   //  std::get<const_expr pos>(tuple_name) returns value of member at the pos in the tuple 
    std::cout << std::get<1>(t1) << " ";
    std::cout << std::get<2>(t1) << " ";

    return 0;
}