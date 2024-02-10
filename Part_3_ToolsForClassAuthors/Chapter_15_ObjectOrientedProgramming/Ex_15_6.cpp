/************************************************************************************************************************************************************
 * @file Ex_15_6.cpp
 * @brief Exercise 15.6: Test your print_total function from the exercises in § 15.2.1 (p. 595) by passing both
 * Quote and Bulk_quote objects to that function.
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "Ex_15_5_BulkQuote.cpp"

int main(){
    Bulk_quote bq1("c++ primer", 45, 0.2, 200);
    Quote q1("discrete maths", 77);
    print_total(q1, 100);
    print_total(bq1, 200);
    print_total(bq1, 199);

    return 0;
}