/************************************************************************************************************************************************************
 * @file Ex_15_28.cpp
 * @brief Exercise 15.28: Define a vector to hold Quote objects but put Bulk_quote objects into that vector. 
 * Compute the total net_price of all the elements in the vector.
 * @date 2024-02-05
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include "Ex_15_27_DiscQuote.cpp" 
#include <vector>
#include <memory>

int main(){
    std::vector<Quote>  basket;
    basket.push_back(*(std::make_shared<Bulk_quote>("c++ primer", 56, 0.4,50)));
    basket.push_back(*(std::make_shared<Bulk_quote>("discrete math", 76, 0.2, 100)));
    basket.push_back(*(std::make_shared<Bulk_quote>("advanced c", 36, 0.3 , 100)));
    basket.push_back(*(std::make_shared<Bulk_quote>("Java", 46, 0.2, 50)));

    for( auto iter = basket.begin(); iter != basket.end(); ++iter){
        std::cout << iter->net_price(100) << std::endl;
    }

    return 0;
}