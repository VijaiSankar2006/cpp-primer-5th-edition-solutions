/************************************************************************************************************************************************************
 * @file Ex_15_11.cpp
 * @brief Exercise 15.11: Add a virtual debug function to your Quote class hierarchy that displays the data members
 * of the respective classes.
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>

// base class
class Quote {
public:     //  every one can access the members
    Quote() = default;

    Quote(const std::string& book_no_, double price_)
        : book_no(book_no_), price(price_)
    {}

    virtual double net_price(size_t count) const {   //  derived classes can override the definition 
        return price * count;
    }

    const std::string& isbn() const {   //   derived classes cannot override these non-virtual functions, they just inherit these
        return book_no;
    }

    virtual void debug() const {
        std::cout << book_no << " " << price << " ";
    }

    virtual ~Quote() = default; // base class destructor should be declared as virtual

private:   //  derived class don't have access to private members like users of the class     
    std::string book_no;    

protected:  //  derived class can access protected members but not the users
    double price;
};

void print_total(const Quote &item, size_t count){
    std::cout << "ISBN : " << item.isbn() << "\n" << 
              "net price : " << item.net_price(count) << std::endl;
}

// derived class, derives from quote
class Bulk_quote : public Quote {   //  The interface of base class becomes part of derived class
public :
    Bulk_quote() = default;
    // constructor, uses base class constructor to initialize its base part
    Bulk_quote(const std::string &book_no_, double price_, double disc_, size_t min_qty_) 
        : Quote(book_no_, price_), disc(disc_), min_qty(min_qty_) {}
    
    //  virtual function overriden 
    double net_price(size_t count) const override {
        if (count >= min_qty) {
            return count * (1 - disc) * price;
        } else {
            return count * price;
        }
    }

    void debug() const override {
        Quote::debug();
        std::cout << disc << " " << min_qty << std::endl;
    }

private :
    double disc;
    size_t min_qty;
};

// derived class, derives from Quote
class LimitedQuote : public Quote {     //  interface of Quote is part of the interface of LimitedQuote
public :    
    LimitedQuote() = default;   
    
    LimitedQuote(const std::string &book_no_, double price_, double disc_, size_t max_qty_) 
        : Quote(book_no_, price_), disc(disc_), max_qty(max_qty_) {}

    double net_price(size_t count) const override {
        if(count <= max_qty){
            return count * (1 - disc) * price;
        } else {
            return max_qty * (1 - disc) * price + (count - max_qty) * price;
        }
    }

    void debug() const override {
        Quote::debug();
        std::cout << disc << " " << max_qty << std::endl;
    }

private :
    double disc;
    size_t max_qty;
};

int main(){
    Quote q1("c++ primer", 45);
    Bulk_quote bq1("discrete maths", 60, 0.2, 100);
    LimitedQuote lq1("advanced c", 88, 0.4, 50);

    Quote *r = &q1;
    r->debug();
    r = &bq1;
    r->debug();
    r = &lq1;
    r->debug();

    return 0;
}
