/************************************************************************************************************************************************************
 * @file Ex_14_39.cpp
 * @brief Exercise 14.39: Revise the previous program to report the count of words that are sizes 1 through 9 and
 *  10 or more.
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Offlength{
    private :
        std::string::size_type min, max;
    public :
        Offlength(size_t min_, size_t max_) : min(min_), max(max_) {}
        bool operator()(const std::string &str){
            if((str.size() >= min) && (str.size() <= max))
                return 1;
            return 0;    
        }
};

int main(){
    std::ifstream ifile("test.txt");
    std::string word;
    if(!ifile){
        std::cerr << "unable to open file" << std::endl;
        return -1;
    }

    Offlength check1_9(1,9), check10_m(10,-1); 

    size_t count1_9 = 0, count10_m = 0;
    while(ifile >> word){
       if(check1_9(word)){
            ++count1_9;
       }else if(check10_m(word)){
            ++count10_m;
       }    
    }

    std::cout << "words of length from 1 to 9 : " << count1_9 << std::endl;
    std::cout << "words of length from 10 or above : " << count10_m << std::endl;

    return 0;
}