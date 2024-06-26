/*  Exercise 7.14: Write a version of the default constructor that explicitly initializes the members to the values we have
 *  provided as in-class initializers. */

#include <iostream>
#include <string>

struct Sales_data;
std::istream & read(std::istream &, Sales_data &);

// definition of Sales_data class
struct Sales_data{
//  interface begins here

    std::string isbn() const {          //   declared as const member function so that we can call isbn() for const objects
        return book_no;
    }
    
    Sales_data & combine(const Sales_data &rhs);
    Sales_data() : units_sold(0), revenue(0) {}                        //   default constructor
    Sales_data(std::istream &is){                  //   constructor that takes one parameter of type istream reference
        read(is, *this);
    }    
    //  constructor that takes only isbn no
    Sales_data(const std::string book_no_p) : book_no(book_no_p) {}
    //  constructor that takes isbn no, units sold, and revenue
    Sales_data(const std::string book_no_p, const unsigned units_sold_p, const double price) :
            book_no(book_no_p), units_sold(units_sold_p), revenue( units_sold_p * price ) {}

//  interface ends here

    std::string book_no;                           //   isbn no                     
    unsigned units_sold ;                           //   total no of units sold
    double revenue ;                                //   revenue from the total sale of this book
};

Sales_data & Sales_data::combine(const Sales_data &rhs){  //   returns reference of the object for which combine was called, it-
    units_sold += rhs.units_sold;                         //   -mimics the += operator's return value   
    revenue += rhs.revenue;

    return *this;                                   //  this is pointer which is rvalue, to get lvalue we dereference it
}

std::istream & read(std::istream &is, Sales_data &item){
    std::cout << "Enter the transactin details[isbn count price] : \n";
    double price;
    is >> item.book_no >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream & print(std::ostream &os, const Sales_data &item){
    os << item.book_no << " " << item.units_sold << " " << item.revenue ;
    return os;
}