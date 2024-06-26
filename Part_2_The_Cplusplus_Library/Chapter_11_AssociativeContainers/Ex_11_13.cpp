/************************************************************************************************************************************************************
 * @file Ex_11_13.cpp
 * @brief Exercise 11.13: There are at least three ways to create the pairs in the program for the previous exercise. Write 
 *        three versions of that program, creating the pairs in each way. Explain which form you think is easiest to write and
 *        understand, and why.
 * @date 2024-01-09
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <utility>

int main(){
    std::vector<std::pair<std::string, int>> agevec;
    
    // method 1, list initialise a pair
    agevec.push_back({"john", 60});

    // method 2, use make_pair function which returns a pair constructed from the arguments
    agevec.push_back(std::make_pair("victor", 56));

    // method 3, use pair constructor to construct a pair
    agevec.push_back(std::pair<std::string, int>("rose", 88));

    for(auto &p : agevec){
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}

/**
 * easiest form is to list initialise the element, when a pair element is expected as a argument, but type should be already known
 *  ex:- auto p = {"john", 56}  //  won't works as type of p cannot be deduced 
 * so if the type needs to deduced by auto std::make_pair is efficient and easy to write and understand, as the type infered from the arguments
 *  ex:- auto p = std::make_pair("john", 56);
 * if we use pair constructor, it will be annoying as it is too much verbose, as explicitly type should be mentioned
 *  ex:- std::pair<std::string, int>("john",56); 
 * 
 * 
 * in the above program, since the type is already known
 *      list initialising the pair is easy to write and understand.
 *  
*/