/*  Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that used recursion to print the 
 *  contents of a vector to conditionally print informationabout its execution. For example, you might print the size of
 *  the vector on each call.Compile and run the program with debugging turned on and again with it turned off. */

#include <iostream>
#include <vector>
#include <cassert>

void printVec(std::vector<int>::iterator beg, std::vector<int>::iterator end){
    #ifndef NDEBUG
        std::cout << __FILE__<< " " << __func__ << " "
                  << __DATE__ << " " << __TIME__ << __LINE__ << std::endl;
        std::cout << "size of vector : " << (end - beg) << std::endl;
    #endif
    if(beg == end)
        return ;
    std::cout << *beg++ << std::endl;
    printVec(beg, end);
}

int main(){
    std::vector<int> ivec{1,2,3,4,5,6};
    printVec(ivec.begin(), ivec.end());

    return 0;
}