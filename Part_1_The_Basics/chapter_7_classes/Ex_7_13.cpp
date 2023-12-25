/*  Exercise 7.13: Rewrite the program from page 255 to use the istream constructor.*/

#include <iostream>
#include "Ex_7_12.cpp"

int main(){
    Sales_data total(std::cin), trans;  // total is instantiated by constructor with istream & parameter, trans by default

    if( !total.isbn().empty() ){           // if total.book_no is not an empty string
        while( read(std::cin, trans)){
            if( total.isbn() == trans.isbn() ){
                total.combine(trans);
            }else{
                print(std::cout, total);
                total = trans;
            }
        }
        print(std::cout , total);
    }else{
        std::cerr << "NO VALID INPUT" << std::endl;
    }

    return 0;
}