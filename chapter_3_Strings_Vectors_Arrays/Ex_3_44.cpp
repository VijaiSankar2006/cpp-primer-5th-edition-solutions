/*  Exercise 3.44: Rewrite the programs from the previous exercises using a type alias for the type of the loop control 
    variables.*/
#include <iostream>
#include <iterator>

int main(){
    using row_array = int[4];                       //  row_array is a type allias for array of 4 ints;
    constexpr size_t row_sz = 3, col_sz = 4;
    int ia[row_sz][col_sz] =  {{1,2,4,8},
                                {16,32,64,128},
                                {256,512,1024,2048}};

    //  using 'range for' to print the array
    std::cout << std::endl;
    for( row_array &row : ia ){     //  row is declared as reference, otherwise row will ptr to array of four int. if-
        for( int ele : row ){           //  -that's the case then 2nd for will be illegal, as we are trying to assign ptr to int
            std::cout << ele << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //  using subscript to print the array
    for( size_t i = 0; i < row_sz; ++i){
        for( size_t j = 0; j < col_sz; ++j ){
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //  using pointers to print the array
    for( row_array *p = ia; p != ia + row_sz; ++p){       //  (or)    p != std::end(ia) 
        for( int *q = *p; q != *p + col_sz; ++q){
            std::cout << *q << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
