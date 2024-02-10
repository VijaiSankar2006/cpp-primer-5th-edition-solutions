/************************************************************************************************************************************************************
 * @file Ex_15_5.cpp
 * @brief Exercise 15.5: Define your own version of the Bulk_quote class.
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "Ex_15_3_Quote.cpp"

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

private :
    double disc;
    size_t min_qty;
};

