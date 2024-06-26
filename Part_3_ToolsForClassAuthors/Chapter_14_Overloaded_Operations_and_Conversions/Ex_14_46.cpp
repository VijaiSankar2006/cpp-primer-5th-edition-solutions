/************************************************************************************************************************************************************
 * @file Ex_14_46.cpp
 * @brief Exercise 14.46: Explain whether defining these Sales_data conversion operators is a good idea and whether
 * they should be explicit.
 * @date 2024-02-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * Their is no direct mapping of Sales_data type to either string or double, so I don't think these conversion operators
 * should be defined for the class. But just to try, I though all the data of the transaction can be represented 
 * as string appended together and revnue alone can be represented as double but these conversion operators should 
 * be explicit.
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <memory>

struct Sales_data;   
std::istream & read(std::istream &, Sales_data &); 


class Sales_data{      
public :        
    friend std::ostream & operator<<(std::ostream &os, const Sales_data &source);    
    friend std::istream & operator>>(std::istream &is, Sales_data &source);   
    Sales_data operator+(const Sales_data &rhs);
    Sales_data & operator+=(const Sales_data &rhs);             
    std::string isbn() const {      
        return book_no;
    }

    double avg_price() const;       
    Sales_data & combine(const Sales_data &rhs);

    Sales_data() : Sales_data("", 0, 0) {                   
        std::cout << "Sales_data() : invoked" << std::endl;
    } 

    explicit Sales_data(std::istream & is) : Sales_data("",0,0) {    
        std::cout << "Sales_data(std::istream & is) : invoked" << std::endl;
        read(is, *this);                                   
    }

    explicit Sales_data(const std::string book_no_p) : Sales_data(book_no_p,0,0) {   
        std::cout << "Sales_data(const std::string book_no_p) : invoked" << std::endl;
     }

    Sales_data(const std::string book_no_p, const unsigned units_sold_p, const double price) :
            book_no(book_no_p), units_sold(units_sold_p), revenue( units_sold_p * price ) {
                std::cout << "Sales_data(const std::string book_no_p, const unsigned units_sold_p, const double price) : invoked"
                          << std::endl;  
            }
    explicit operator std::string() {
        return book_no + " " + std::to_string(units_sold) + " " + std::to_string(revenue);
    }

    explicit operator double(){
        return revenue;
    }

private :                                          
    std::string book_no;                                               
    unsigned units_sold = 0 ;                      
    double revenue = 0;                            
};

Sales_data Sales_data::operator+(const Sales_data &rhs){
    Sales_data temp(*this);
    return temp += rhs;
}

Sales_data & Sales_data::operator+=(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}             

std::istream & operator>>(std::istream &is, Sales_data &source){
    double price;
    is >> source.book_no >> source.units_sold >> price;
    if (is){     //  checks if read was successfull
        source.revenue = price * source.units_sold;
    } else {
        source = Sales_data();
    }

    return is;
}

std::ostream & operator<<(std::ostream &os, const Sales_data &item){
    os << item.book_no << " " << item.units_sold << " " << item.revenue ;
    return os;
}

Sales_data & Sales_data::combine(const Sales_data &rhs){  
    units_sold += rhs.units_sold;                         
    revenue += rhs.revenue;

    return *this;                                   
}

inline double Sales_data::avg_price() const {
    return revenue / units_sold;
}

int main(){
    Sales_data b1("897-456-324x", 45, 10);
    std::string str = static_cast<std::string>(b1);
    std::cout << str << std::endl;
    double gain = static_cast<double>(b1);
    std::cout << gain << std::endl;

    return 0;
}