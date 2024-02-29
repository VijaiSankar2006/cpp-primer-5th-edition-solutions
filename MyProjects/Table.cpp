/************************************************************************************************************************************************************
 * @file Table.cpp
 * @brief definitions of all members of Table class
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include "Table.h"

void Table::add_schema(const schema_type &schema_) {
    schema = schema_;
}

Table::schema_type Table::get_schema() {
    return schema;
}

bool Table::add_record(const row record_) {
    records.push_back(record_);

    return 1;
}

void Table::print() {
    size_t N = 10;
    for(auto p : schema) {  //  table header
        std::cout << std::setw(N) << p.first << "||";
    }
    std::string h_line(schema.size() * N, '=');
    std::cout << '\n' + h_line << std::endl;

    for (auto r : records) {
        auto s_iter = schema.begin();
        for (auto p : r) {
            switch(s_iter->second[0]) {
                case 'i' : std::cout << std::setw(N) << *(static_cast<int *>(p)) << "||"; break;
                case 'd' : std::cout << std::setw(N) << *(static_cast<double *>(p)) << "||"; break;
                case 'c' : std::cout << std::setw(N) << *(static_cast<char *>(p)) << "||"; break;
                case 's' : std::cout << std::setw(N) << *(static_cast<std::string *>(p)) << "||"; break;
            }
            ++s_iter;
        }
        std::cout << std::endl;
    }
}

