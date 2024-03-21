/************************************************************************************************************************************************************
 * @file Query.cpp
 * @brief member definitions of classes in Query
 * @date 2024-02-29
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "Query.h"
#include <set>
#include <algorithm>

class Table;
class QueryResults;

Where::Where() : all(true) {}   // defualt constructor fetches all coloumns

Where::Where(const std::string &col_name_, const std::string &val_)  //  constructor that takes coloumn name and value to search
    : col_name(col_name_), val(val_) {}

QueryResult & Where::eval(QueryResult &qr_) {
    if (all) {
        return qr = qr_;
    } else {
        auto pos = std::distance(qr.schema.find(col_name), qr.schema.begin());

        auto int_equal = [this,pos](Table::row &p){ return *static_cast<int *>(p[pos]) == stoi(val);};
        auto double_equal = [this,pos](Table::row &p){ return *static_cast<double *>(p[pos]) == stod(val);};
        auto char_equal = [this,pos](Table::row &p){ return *static_cast<char *>(p[pos]) == val[0];};
        auto string_equal = [this,pos](Table::row &p){ return *static_cast<std::string *>(p[pos]) == val; };

        std::vector<Table::row>::iterator end;
        switch(qr_.schema[col_name][0]) {
            case 'i' : end = std::partition(qr_.records.begin(), qr_.records.end(), int_equal); break;
            case 'd' : end = std::partition(qr_.records.begin(), qr_.records.end(), double_equal); break;
            case 'c' : end = std::partition(qr_.records.begin(), qr_.records.end(), char_equal); break;
            case 's' : end = std::partition(qr_.records.begin(), qr_.records.end(), string_equal); break;
        }
        std::vector<Table::row> res(qr_.records.begin(), end);
        qr = qr_;
        return qr;
    }
}

int main () {
    Table tb;
    
}