/*  Exercise 6.27: Write a function that takes an initializer_list<int> and produces the sum of the elements in the list.*/

#include <iostream>
#include <initializer_list>

//  addLst takes an intialiser lst as the argument
int addLst(std::initializer_list<int> lst){
    int result = 0;
    for( auto n : lst){
        result += n ;
    }

    return result;
}

int main(){
    std::cout << addLst({1}) << std::endl;
    std::cout << addLst({1,2,3,4,5,6}) << std::endl;
    std::cout << addLst({12,45}) << std::endl;

    return 0;
}
/* * * * * * 
 *  output :
 *  1
 *  21
 *  57
 * * * * * */