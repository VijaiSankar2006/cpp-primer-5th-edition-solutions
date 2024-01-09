/************************************************************************************************************************************************************
 * @file Ex_10_42.cpp
 * @brief Exercise 10.42: Reimplement the program that eliminated duplicate words that we wrote in § 10.2.3 (p. 383) 
 * to use a list instead of a vector.
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

int main(){
    
    std::cout << "Enter a list of words : " << std::endl;
    std::istream_iterator<std::string> str_iter(std::cin), end;
    std::list<std::string> wordLst(str_iter, end);

    
    std::ostream_iterator<std::string> ostr_iter(std::cout, " ");
    wordLst.sort();
    ostr_iter = "\nlist of words sorted \n";
    std::copy(wordLst.cbegin(), wordLst.cend(), ostr_iter); 

    wordLst.unique();
    ostr_iter = "\nlist of unique words\n";
    std::copy(wordLst.cbegin(), wordLst.cend(), ostr_iter);

    return 0;
}

