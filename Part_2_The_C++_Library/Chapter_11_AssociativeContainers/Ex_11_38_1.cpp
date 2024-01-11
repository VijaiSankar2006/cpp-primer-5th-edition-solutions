/************************************************************************************************************************************************************
 * @file Ex_11_38.cpp
 * @brief Exercise 11.38: Rewrite the word-counting (§ 11.1, p. 421) and word-transformation (§ 11.3.6, p. 440) programs to
 *        use an unordered_map.
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

// word counting program

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::unordered_map ; using std::vector; using std::endl; using std::string; 
int main()
{
    unordered_map<string, size_t> word_count;  //  library defines hash function for string and size_t

    std::string word;
    while (cin >> word)
        ++word_count[word];    

    auto b_count = word_count.bucket_count();
    std::cout << "\ntotal no of buckets in use : " << b_count << std::endl;

    // code to print the elements
    for(decltype(b_count) i = 1; i < b_count ; ++i){  // loop iterates the buckets from 0 to bucket_count - 1
        for(auto beg = word_count.cbegin(i); beg != word_count.cend(i); ++beg){  // loop prints the elements in the bucket
            std::cout << beg->first << " " << beg->second << std::endl;
        }
    }
        
    std::cout << "\nelements printed using normal for range" << std::endl;
    for( auto p : word_count){
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}

