/*  Exercise 7.1: Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you
 *  defined for the exercises in § 2.6.1 (p. 72). */

#include <iostream>
#include "sales_data.h"

/*  struct sales_data{
 *     std::string book_no;
 *     size_t units_sold;
 *     double revenue;
 *  };
 * * * * * * * * * * * * */

int main(){
    sales_data total;
    std::cout << "Enter the list of transaction : ";
    double price;

    if(std::cin >> total.book_no >> total.units_sold >> price){         //  condition checks for valid input
        total.revenue = total.units_sold * price;
        sales_data trans;
        while(std::cin >> trans.book_no >> trans.units_sold >> price){  //  transactions are read and processed until eof
            trans.revenue = trans.units_sold * price;
            if( total.book_no == trans.book_no ){
                total.revenue += trans.revenue;
                total.units_sold += trans.units_sold;
            }else{
                std::cout << "\n\t# " << total.book_no << " " << total.units_sold << " " << total.revenue << std::endl;
                total = trans;
            }
        }
        std::cout << "\n\t# " << total.book_no << " " << total.units_sold << " " << total.revenue << std::endl;
    }else{
        std::cerr << "NO INPUT";
        return -1;
    }

    return 0;
}