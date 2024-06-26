/************************************************************************************************************************************************************
 * @file Ex_10_9.cpp
 * @brief Exercise 10.9: Implement your own version of elimDups. Test your program by printing the vector after you read the
 *        input, after the call to unique, and after the call to erase.
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void elimDups(std::vector<std::string> &sourcVec);
int main(){
    std::vector<std::string> strvec;
    std::cout << "Enter the list of words :\n";
    std::string word;
    while(std::cin >> word){
        strvec.push_back(word);
    }

    std::cout << "\nList of words entered : "<< std::endl; 
    for( auto s : strvec){
        std::cout << s << " ";
    }

    elimDups(strvec);
    std::cout << "\nafter eliminating duplicates:" << std::endl;
    for( auto s : strvec){
        std::cout << s << " ";
    }
    return 0;
}

void elimDups(std::vector<std::string> &sourceVec){
    // sort() the elements in the given sequence
    std::sort(sourceVec.begin(), sourceVec.end());
    std::cout << "\n\nList after sorted : " << std::endl;
    for( auto s : sourceVec){
        std::cout << s << " ";
    }
    std::cout << "[end of list]" << std::endl;

    //  unique() rearranges the elements such that, elements appear only once in the front by writing over the adjusant duplicates
    //  and returns the end of the unique range
    auto endOfUnique = std::unique(sourceVec.begin(), sourceVec.end());
    std::cout << "\nUnique list with duplicate words : " << std::endl;
    for( auto s : sourceVec){
        std::cout << s << " ";
    }
    std::cout << "[end of list]" << std::endl;    //  as the duplicate words are overwriten with the next unique word eventualy we get a empty string 

    //  code to erase the duplicate words
    sourceVec.erase(endOfUnique, sourceVec.end());
    std::cout << "\nunique words with out duplicates : " << std::endl;
    for( auto s : sourceVec){
        std::cout << s << " ";
    }
    std::cout << "[end of list]" << std::endl;

}

/************************************************************************************************************************************************************
 * sorted list : 
 *      fox  jumps  over  quick  red   red   slow   the     the   turtle
 *                                     slow         the     the   turtle     //   'slow' is writen over 'red', empty string in the place of 'slow'   
 *                                     slow  the            the   turtle     //   'the' is writen over in the place of empty string and old position is filled with an another empty string
 *                                     slow  the    turtle  the              //    'turtle' is writen over the empty string, and an empty string is added in the old position
 *                              //  as there are no unique words left, we end up with 'the' and an empty string as the last element
 *                              //  size of the vec remains same
 * 
 * unique list with duplicate words
 *      fox  jumps  over  quick  red  slow  the turtle  the  [empty string]
 * 
 * duplicates elimnated list
 *      fox  jumps  over  quick  red  slow  the turtle
 * 
 *************************************************************************************************************************************************************/

