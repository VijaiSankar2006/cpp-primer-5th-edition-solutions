/************************************************************************************************************************************************************
 * @file Ex_12_6.cpp
 * @brief Exercise 12.6: Write a function that returns a dynamically allocated vector of ints. Pass that vector to another 
 * function that reads the standard input to give values to the elements. Pass the vector to another function to print the 
 * values that were read. Remember to delete the vector at the appropriate time.
 * @date 2024-01-15
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>
#include <vector>

std::vector<int> * allot();
void read(std::vector<int> *);
void print(std::vector<int> *);

int main(){
    std::vector<int> *p_ivec = allot();   
    read(p_ivec);
    print(p_ivec);
    delete p_ivec;

    return 0;
}

std::vector<int> * allot(){
    return new std::vector<int>();
}

void read(std::vector<int> *p_ivec){
    std::cout << "Enter the elements : \n" << std::endl;
    int num;
    while(std::cin >> num){
        p_ivec->push_back(num);
    } 
}

void print(std::vector<int> *p_ivec){
    std::cout << "\nThe elements are : \n";
    for( auto num : *p_ivec){
        std::cout << num << " ";
    }
}