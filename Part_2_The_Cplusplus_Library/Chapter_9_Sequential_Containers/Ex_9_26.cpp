/************************************************************************************************************************************************************
 * @file Ex_9_26.cpp
 * @brief Exercise 9.26: Using the following definition of ia, copy ia into a vector and into a list. Use the single-iterator
 *        form of erase to remove the elements with odd values from your list and the even values from your vector.
               int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main(){
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    std::vector<int> ivec;
    std::list<int> ilist;

    ivec.assign(std::cbegin(ia), std::cend(ia));
    ilist.assign(std::cbegin(ia), std::cend(ia));

    auto it = ilist.begin();
    while(it != ilist.end()){
        if( *it % 2 ){
           it = ilist.erase(it);
        }else{
            ++it;
        }
    }   

    auto itvec = ivec.begin();
    while(itvec != ivec.end()){
        if( *itvec % 2 ){
            ++itvec;
        }else{
            itvec = ivec.erase(itvec);
        }
    }

    std::cout << "list<even> : \n";
    for( auto n : ilist){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "list<odd> : \n";
    for( auto n : ivec){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}    