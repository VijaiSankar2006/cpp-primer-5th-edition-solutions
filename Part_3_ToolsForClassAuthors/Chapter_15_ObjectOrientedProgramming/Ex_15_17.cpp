/************************************************************************************************************************************************************
 * @file Ex_15_17.cpp
 * @brief Exercise 15.17: Try to define an object of type Disc_quote and see what errors you get from the compiler.
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "Ex_15_15_DiscQuote.cpp"

int main(){
    Disc_quote dq1("c++ primer", 56, 0.3, 100);

    // error: cannot declare variable ‘dq1’ to be of abstract type ‘Disc_quote’
   //    Disc_quote dq1("c++ primer", 56, 0.3, 100);
}