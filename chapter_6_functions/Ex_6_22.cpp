/*  Exercise 6.22: Write a function to swap two int pointers. */

#include <iostream>

// function to swap two int pointers using pointers
void swapIntPtrsbyPtrs(int **ptr1, int **ptr2){
     int *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

//  function to swap two int pointers using reference to pointers
void swapIntptrsbyRef(int *(&ptr1), int *(&ptr2)){
    int *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

int main(){
    int i = 89, j = 56;
    int *p = &i, *q = &j;
    std::cout << i << " " << j << std::endl;
    std::cout << "p = " << p << "  q = " << q << std::endl;
    swapIntPtrsbyPtrs(&p,&q);
    std::cout << "p = " << p << "  q = " << q << std::endl;
    swapIntptrsbyRef(p, q);
    std::cout << "p = " << p << "  q = " << q << std::endl;
    return 0;
}