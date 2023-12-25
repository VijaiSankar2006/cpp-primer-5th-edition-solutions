/*  Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program
    so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so 
    on  */

#include <iostream>
#include <vector>

using subscript = std::vector<int>::size_type;
int main(){
    std::vector<int> ivec;
    std::cout << "Enter a set of integers : ";
    int n;
    while( std::cin >> n ){
        ivec.push_back(n);
    }
    std::cout << std::endl;
    //  code to print sum of adjusent elements
    for( subscript first = 0, next = first + 1 ;  next != ivec.size(); ++first, ++next){
        std::cout << ivec[first] + ivec[next] << " ";
    }
    std::cout << std::endl;

    //  code to print first and last, followed by second and second last, and so on
    for( subscript first = 0, last = ivec.size() - 1; first <= last; ++first, --last){
        std::cout << ivec[first] + ivec[last] << " ";
    }
    std::cout << std::endl;

    return 0;
}