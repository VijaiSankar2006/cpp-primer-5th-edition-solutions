/************************************************************************************************************************************************************
 * @file Table.cpp
 * @brief Table class to create tables for RDBMS    
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

class Table {
    public : 
        typedef std::map<std::string, std::string>> schema_type;
        typedef std::vector<void *> row;

        void add_schema(const schema_type &schema_);
        schema_type get_schema();

        bool add_record(const row record_);
        void print();  
    private :
        schema_type schema;
        std::vector<row> records;

};

#endif