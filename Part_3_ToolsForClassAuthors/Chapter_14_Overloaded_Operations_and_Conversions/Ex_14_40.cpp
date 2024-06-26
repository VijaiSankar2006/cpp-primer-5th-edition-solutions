/************************************************************************************************************************************************************
 * @file Ex_14_40.cpp
 * @brief Exercise 14.40: Rewrite the biggies function from § 10.3.2 (p. 391) to use function-object classes in place of 
 * lambdas.
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void biggies(std::vector<std::string> &words);
void elimDups(std::vector<std::string> &words);

class PrintString{
    private : 
        std::ostream &os;
        char additional;
    public :
        PrintString(std::ostream &strm = std::cout, char ch = ' ') : os(strm), additional(ch) {}
        void operator()(const std::string &str){
            os << str << additional;
        }
};

class IsShorter{
    public :
        bool operator()(const std::string &lhs, const std::string &rhs){
            return lhs.size() < rhs.size();
        }
};

class Greater{
    private :
        std::string::size_type sz;
    public :
        Greater(std::string::size_type sz_) : sz(sz_){}
        bool operator()(const std::string &str){
            return str.size() >= sz;
        }
};

int main(){
    std::vector<std::string> wordlst;
    std::cout << "Enter the list of words : " << std::endl;
    std::string word;
    while(std::cin >> word){
        wordlst.push_back(word);
    }

    biggies(wordlst);
    return 0;
}

void biggies(std::vector<std::string> &words){
    

    // sorts the list in dict order, removes dup words and sorts by length by preserving dict order
    elimDups(words);

    // code to count the number of words greater than or equal to 6
    auto count = std::count_if(words.begin(), words.end(), Greater(6));
    std::cout << "\nthere are " << count << " words greater than or equal to 6" << " letters" << std::endl;

    //  code to partition the list wiht element whose size is greater than sz preceding the rest with original order preserved
    auto endOfMatches = std::stable_partition(words.begin(), words.end(), Greater(6));
    std::cout << "\nwords greater than or equal to 6" << " letter" << std::endl;
    std::for_each(words.begin(), endOfMatches, PrintString());
    
    return;
}

void elimDups(std::vector<std::string> &words){

    // code to sort the list
    std::sort(words.begin(), words.end());
    std::cout << "\nsorted list of words with duplicates : " << std::endl;
    std::for_each(words.begin(), words.end(), PrintString());
    std::cout << std::endl;

    // code to eliminate dups
    auto endUnique = std::unique(words.begin(), words.end());
    words.erase(endUnique, words.end());  //    erases the duplicate words
    std::cout << "\nSorted list of unique words : " << std::endl;
    std::for_each(words.begin(), words.end(), PrintString());
    std::cout << std::endl;

    // code to sort the list based on length preserving alphabetical order
    std::stable_sort(words.begin(), words.end(), IsShorter());
    std::cout << "\nsorted list of words by length : " << std::endl; 
    std::for_each(words.begin(), words.end(), PrintString());
    std::cout << std::endl;

    return;
}
