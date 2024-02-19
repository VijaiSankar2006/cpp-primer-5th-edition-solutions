#include <iostream>
#include <string>

struct Sales_data;   
std::istream & read(std::istream &, Sales_data &); 


class Sales_data{      
public :        
    friend std::ostream & operator<<(std::ostream &os, const Sales_data &source);    
    friend std::istream & operator>>(std::istream &is, Sales_data &source);               
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
private :                                          
    std::string book_no;                                               
    unsigned units_sold = 0 ;                      
    double revenue = 0;                            
};

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
