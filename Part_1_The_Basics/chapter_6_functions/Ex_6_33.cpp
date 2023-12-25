/*  Exercise 6.33: Write a recursive function to print the contents of a vector*/

#include <iostream>
#include <vector>

// function takes two iterators pointing to begining and end of the vector
void printIntVec(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end){
    if(beg == end){          
        return ;
    }
    std::cout << *beg << " ";
    printIntVec(beg+1,end);
}

int main(){
    std::vector<int> ivec{1,2,3,4,5,12,34,56,78,90};

    printIntVec(ivec.cbegin(), ivec.cend());

    return 0;

}