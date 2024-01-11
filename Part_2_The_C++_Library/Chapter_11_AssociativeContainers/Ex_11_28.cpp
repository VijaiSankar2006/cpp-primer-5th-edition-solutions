/************************************************************************************************************************************************************
 * @file Ex_11_28.cpp
 * @brief Exercise 11.28: Define and initialize a variable to hold the result of calling find on a map from string to 
 *        vector of int.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <map>
#include <vector>
#include <iostream>

int main(){
    std::map<std::string, std::vector<int>> grades{{"john",{1,2,3}},{"victor",{5,6,7}}};

    std::map<std::string, std::vector<int>>::iterator iter = grades.find("victor");
    if(iter == grades.end()){
        std::cout << "not present";
    }else{
        std::cout << iter->first << " " << iter->second[0] << " " << iter->second[1] << " " << iter->second[2] << std::endl;
    }
    
    return 0;
}