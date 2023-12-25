#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
// sales_data class definition
struct Sales_data{
    std::string book_no;
    size_t units_sold;
    double revenue;
};

#endif