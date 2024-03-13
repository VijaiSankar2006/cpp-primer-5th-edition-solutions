/************************************************************************************************************************************************************
 * @file Table.h
 * @brief Header for table class
 * @date 2024-03-01
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <unordered_map>

using std::string; using std::unordered_map; using std::vector; using std::pair;
class QueryResult;

class Table {
    friend class Order_by;
    friend class From;
    friend class Where;
    friend class NotQuery;
    friend class AndQuery;
    friend class OrQuery;
    friend class Select;
    friend QueryResult order_by(QueryResult qr, bool desc);
    friend void add_record(Table &tb);
    friend std::ostream & operator<<(std::ostream &os, Table const &tb);
    friend std::istream & operator>>(std::istream &os, Table &tb);
    public :
        typedef pair<string, string> constraint;
        enum types {int_type = 0, double_type = 1, char_type = 2, string_type = 3};
        typedef vector<pair<string, string>> schema_type;
        typedef vector<vector<void *>> record_type;

        Table() = default;
        Table(std::ifstream &ifile); 
        Table(schema_type schema_, const string &p_key);
        bool add_record(const vector<void *> record_);
        bool create_new_record(vector<void *> &r);
        int remove_record(const constraint &item);  
        bool check(const std::vector<string> &lst);
    //  int delete_records(record_type::iterator b, record_type::iterator e);
        Table * new_table(record_type::iterator b, record_type::iterator e);
        size_t size() const ;
        bool empty() const ;

        schema_type get_schema() const ;
        string get_pkey() const;
        pair<size_t, string> get_col_info(const string &col_name) const ;
        
    private :
        vector<vector<void *>> records;
        schema_type schema;
        string primary_key;
        types key_type;
        size_t key_pos;
        string name;
};

std::ostream & operator<<(std::ostream &os, Table const &tb);
std::istream & operator>>(std::istream &os, Table &tb);
bool compare_equal(const vector<void *> &lhs, const vector<void *> &rhs, int N, size_t pos);
bool compare_less(vector<void *> &lhs, vector<void *> &rhs, int N, size_t pos);
bool equal(const vector<void *> &vec, const string &val, int N, size_t pos);
#endif