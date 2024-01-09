/************************************************************************************************************************************************************
 * @file Ex_10_13.cpp
 * @brief Exercise 10.13: The library defines an algorithm named partition that takes a predicate and partitions the container
 *        so that values for which the predicate is true appear in the first part and those for which the predicate is false 
 *        appear in the second part.The algorithm returns an iterator just past the last element for which the predicate 
 *        returned true. Write a function that takes a string and returns a bool indicating whether the string has five 
 *        characters or more. Use that function to partition words.Print the elements that have five or more characters.
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool checkLength(const std::string &source){
    return source.size() > 5;
}

int main(){
    std::vector<std::string> strvec;
    std::cout << "Enter the list of words to partition : ";
    std::string word;
    while(std::cin >> word){
        strvec.push_back(word);
    }

    std::cout << "\nList afer partition : " << std::endl;
    std::partition(strvec.begin(), strvec.end(), checkLength);
    for( auto s : strvec){
        std::cout << s << " ";
    }

    return 0;
}

// checks each element with the predicate, if true leaves in it position
// if false, then searches in reverse for which the predicate is true, then swaps the elements
// then processes the next element in sequential order