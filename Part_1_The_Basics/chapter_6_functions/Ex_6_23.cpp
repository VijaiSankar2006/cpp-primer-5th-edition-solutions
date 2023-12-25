/*  Exercise 6.23: Write your own versions of each of the print functions presented in this section. Call each of these
 *  functions to print i and j defined as follows:
 *  int i = 0, j[2] = {0, 1};  */

#include <iostream>
#include <iterator>

//  function to print an array by size 
//  void printArrbySz(const int arr[], const size_t sz)     int arr[] = int *arr   
void printArrbySz(const int *ptr, const size_t sz){
    for(size_t i = 0; i < sz ; ++i){
        std::cout << *ptr++ << " "; 
    }
    std::cout << std::endl;
}

//  function to print an array by iterators
void printArrbyiter(const int *beg, const int *end){
    while(beg != end){
        std::cout << *beg++ << " ";
    }
    std::cout << std::endl;
}

// function to print an array by reference
void printArrbyRef( const int (&arr)[2]){
    for( auto n : arr){
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// main function
int main(){
    int i = 0, j[2] = {0,1};
    printArrbySz(&i, 1);
    printArrbySz(j, 2);
   // printArrbyiter(std::begin(&i), std::end(&i));
    printArrbyiter(std::begin(j), std::end(j));
  //  printArrbyRef(i);
    printArrbyRef(j);

    return 0;
}
