/************************************************************************************************************************************************************
 * @file Ex_15_15.cpp
 * @brief Exercise 15.15: Define your own versions of Disc_quote and Bulk_quote.
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
    { std::cout << "Quote() constructor invoked : " << std::endl; }

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

//  abstract base class
class Disc_quote : public Quote {
public :    
    Disc_quote() = default;
    Disc_quote(const std::string &book_no_, double price_, double disc_, size_t qty_) 
        : Quote(book_no_, price_), qty(qty_), disc(disc_) {
            std::cout << "Disc_quote() constructor finished : qty =  " << qty << std::endl;
        }

    double net_price(size_t count) const override = 0;
    void debug() const override {
        Quote::debug();
        std::cout << qty << " " << disc << std::endl;
    }

protected :
    size_t qty;
    double disc;
};

// derived class, derives from quote
class Bulk_quote : public Disc_quote {   //  The interface of base class becomes part of derived class
public :
    Bulk_quote() = default;
    // constructor, uses base class constructor to initialize its base part
    Bulk_quote(const std::string &book_no_, double price_, double disc_, size_t qty_) 
        : Disc_quote(book_no_, price_, disc_, qty_) {
            std::cout << "BulkQuote() constructor finished : " << std::endl;
        }
    
    //  virtual function overriden 
    double net_price(size_t count) const override {
        if (count >= qty) {
            return count * (1 - disc) * price;
        } else {
            return count * price;
        }
    }

    void debug() const override {
        Disc_quote::debug();
    }
};

// derived class, derives from Quote
class LimitedQuote : public Disc_quote {     //  interface of Quote is part of the interface of LimitedQuote
public :    
    LimitedQuote() = default;   
    
    LimitedQuote(const std::string &book_no_, double price_, double disc_, size_t qty_) 
        : Disc_quote(book_no_, price_, disc_, qty_) {
            std::cout << "LimitedQuote() constructor finished : "<< std::endl;
        }

    double net_price(size_t count) const override {
        if(count <= qty){
            return count * (1 - disc) * price;
        } else {
            return qty * (1 - disc) * price + (count - qty) * price;
        }
    }

    void debug() const override {
        Disc_quote::debug();
    }
};

