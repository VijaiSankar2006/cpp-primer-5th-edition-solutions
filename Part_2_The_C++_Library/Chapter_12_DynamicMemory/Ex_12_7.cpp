/************************************************************************************************************************************************************
 * @file Ex_12_7.cpp
 * @brief Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> allot();
void read(std::shared_ptr<std::vector<int>> );
void print(std::shared_ptr<std::vector<int>> );

int main(){
    std::shared_ptr<std::vector<int>> sp_ivec = allot();
    read(sp_ivec);
    print(sp_ivec);

    return 0;
}

std::shared_ptr<std::vector<int>> allot(){
    return std::make_shared<std::vector<int>>();
}

void read(std::shared_ptr<std::vector<int>> sp_ivec){
    std::cout << "Enter the elements : \n";
    int num;
    while(std::cin >> num){
        sp_ivec->push_back(num);
    }
}

void print(std::shared_ptr<std::vector<int>> sp_ivec){
    std::cout << "\nThe elements are : " << std::endl;
    for(auto num : *sp_ivec){
        std::cout << num << " "; 
    }
    std::cout << std::endl;
}

