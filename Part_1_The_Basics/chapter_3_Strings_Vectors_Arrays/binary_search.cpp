/*  write a program to search a given number in a sorted array by implementing binary search*/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec{10,20,33,45,51,58,67,69,70,89,90,100};
    std::cout << "Enter a number to search : ";
    int num;
    
    while( std::cin >> num ){
        auto mid = ivec.cbegin() + (ivec.cend() - ivec.cbegin()) / 2; 
        auto end = ivec.cend();
        auto beg = ivec.cbegin();
        while( mid != end && *mid != num ){
            if( *mid < num ){
                beg = mid + 1;
            }else{
                end = mid;
            }
            mid = beg + (end - beg) / 2;
        }
        if( mid != end){
            std::cout << num << " found";
        }else{
            std::cout << num << "not found";
        }
        std::cout << "\nEnter number to search : ";
    }
    
    return 0;
}