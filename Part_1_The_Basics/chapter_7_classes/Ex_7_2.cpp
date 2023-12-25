/*  Exercise 7.2: Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).*/

#include <iostream>

struct Sales_data{
    std::string isbn() const {          //   declared as const member function so that we can call isbn() for const objects
        return book_no;
    }
    
    Sales_data & combine(const Sales_data &rhs);

    std::string book_no;                           //   isbn no                     
    unsigned units_sold;                           //   total no of units sold
    double revenue;                                //   revenue from the total sale of this book
};

Sales_data & Sales_data::combine(const Sales_data &rhs){  //   returns reference of the object for which combine was called, it-
    units_sold += rhs.units_sold;                         //   -mimics the += operator's return value   
    revenue += rhs.units_sold;

    return *this;                                   //  this is pointer which is rvalue, to get lvalue we dereference it
}

