/*  Exercise 7.7: Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new
 *  functions. */

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
    revenue += rhs.revenue;

    return *this;                                   //  this is a pointer which is rvalue, to get lvalue we dereference it
}

std::istream & read(std::istream &is, Sales_data &item){
    double price;
    is >> item.book_no >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream & print(std::ostream &os, const Sales_data &item){
    os << item.book_no << " " << item.units_sold << " " << item.revenue ;
    return os;
}

int main(){

    Sales_data total;
    std::cout << "Enter the list of transactions : \n";

    if( read(std::cin, total) ){
        Sales_data trans;
        while( read(std::cin, trans) ){
            if( total.isbn() == trans.isbn()){      //  isbn() function returns book_no from the corresponding objext
                total.combine(trans);               //  combine() takes trans and returns a reference to total object
            }else{
                std::cout << "\n# ";
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total);
    }else{
        std::cerr << "NO VALID INPUT" << std::endl; 
    }    

    return 0;
}