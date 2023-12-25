/*  Exercise 6.10: Using pointers, write a function to swap the values of two ints. Test the function by calling it and
 *  printing the swapped values.*/

#include <iostream>

//  function to swap two ints
void swapNum(int *p, int *q){  //  takes two parameters of type pointer to int 
    int temp = *p;
    *p = *q ;
    *q = temp;
}

int main(){
    int m = 10, n = 78;
    std::cout << "original sequence : "<< m << " " << n << std::endl;
    swapNum(&m,&n);
    std::cout << "swaped sequence : " << m << " " << n << std::endl;

    return 0;
}