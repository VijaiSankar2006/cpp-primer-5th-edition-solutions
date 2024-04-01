/************************************************************************************************************************************************************
 * @file Ex_9_22.cpp
 * @brief Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the
 *        problem(s)?
          vector<int>::iterator iter = iv.begin(),
          mid = iv.begin() + iv.size()/2;
          while (iter != mid)
            if (*iter == some_val)
                iv.insert(iter, 2 * some_val);
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * inserting in to a vector invalidates all the iterators, references and pointers in to the container
*/

// following code shows reference becoming invalidated
#include <iostream>
#include <vector>

int main(){
    std::vector<int> ivec{1,6,22};
    int &r = ivec[1];
    std::cout << "r = " << r << std::endl;      //  output : 6
    ivec.insert(ivec.begin(), 33);              //  output : 5  // 5 is not in the container
    std::cout << "r = " << r << std::endl;
    for(auto n : ivec){                     
        std::cout << n << " ";
    }
    return 0;
}