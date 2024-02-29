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

class Table;

Where::Where() : all(true) {}   // defualt constructor fetches all coloumns

Where::Where(const std::string &col_name_, const std::string &val_)  //  constructor that takes coloumn name and value to search
    : col_name(col_name_), val(val_) {}

qr Where::eval(QueryResult &qr) {
    if (all) {
        return qr;
    } else {
        std::set<Table::row> res;
        auto col = qr.schema.find(col_name) - qr.schema.begin();
        for (auto r : qr.records) {
            switch(schema[col_name][0]) {
                case 'i' : if (stoi(val) == static_cast<int *>(r[col])) 
                                res.insert(), break;
                case 'd' : if (stod(val) == )
                case 'c' :
                case 's' :
            }
        }
    }
}
