/* Exercise 4.21: Write a program to use a conditional operator to find the elements in a vector<int> that have odd value
** and double the value of each such element. */

#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec{1,2,3,4,5,17,7,8,9,10};
    for( int &num : ivec ){
        num = (num % 2) ? num * 2 : num;
    }

    for( int num : ivec){
        std::cout << num << " ";
    }

    return 0;
}

