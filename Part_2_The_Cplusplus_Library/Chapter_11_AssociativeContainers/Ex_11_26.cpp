/************************************************************************************************************************************************************
 * @file Ex_11_26.cpp
 * @brief Exercise 11.26: What type can be used to subscript a map? What type does the subscript operator return? Give a
 *        concrete example—that is, define a map and then write the types that can be used to subscript the map and the
 *        type that would be returned from the subscript operator.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <map>

int main(){
    std::map<std::string, size_t> word_count;  // word_count maps string to size_t
    // key_type : std::string
    // mapped_type : size_t
    // value_type : std::pair<const std::string, size_t>

    // key_type(std::string) should be used to subscript a map
    // mapped_type(size_t) is returned by the subscript operator 
 
}