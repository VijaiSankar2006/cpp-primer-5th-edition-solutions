/************************************************************************************************************************************************************
 * @file Query.h
 * @brief Query class header 
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <vector>
#include "Table.h"

class Table;
class QueryResult {
    friend class From;
    friend class Where;
    friend class And;
    friend class Or;
    friend class Not;
    private :
        QueryResult() = default;
        QueryResult(std::vector<Table::row> records_, Table::schema_type schema_)
            : records(records_), schema(schema_) {}

        std::vector<Table::row> records;
        Table::schema_type schema;
};

class From {
    protected :
        From(Table &tb_) : tb(tb_) {}
    public :
        QueryResult eval() {
            return QueryResult(tb.get_records(), tb.get_schema());  
        }
    private :   
        Table &tb;
};

class QueryBase {
    protected :
        QueryBase();
        virtual QueryResult & eval(QueryResult &qr) = 0; 
        virtual std::string & res() = 0;
};

class Where : public QueryBase {
    public :
        Where();
        Where(const std::string &col_name_, const std::string &val_);
        QueryResult & eval(QueryResult &qr) override ;
        std::string & res() override ;
    private :
        std::string col_name;
        std::string val; 
        bool all = false;
        QueryResult qr;
};

class Binary_operator : public Where {
    protected :
        Binary_operator(const std::string& lhs_col_name_, const std::string &lhs_val_,
            const std::string& rhs_col_name_, const std::string &rhs_val_, const std::string &op_);
        QueryResult & eval(QueryResult &qr) = 0;
        std::string & res () override ;    

    protected : 
        QueryResult &qr;
        std::string lhs_col_name;
        std::string lhs_val;
        std::string rhs_col_name;
        std::string rhs_val;
        std::string operand;
};

class And : public Binary_operator {
    public :
        And(const std::string& lhs_col_name_, const std::string &lhs_val_,
            const std::string& rhs_col_name_, const std::string &rhs_val_);
        QueryResult &eval(QueryResult &qr);
};

class Or : public Binary_operator {
    public :
        Or(const std::string& lhs_col_name_, const std::string &lhs_val_,
            const std::string& rhs_col_name_, const std::string &rhs_val_);
        QueryResult & eval(QueryResult &qr) override ;
};

class Not : public Where {
    public :
        Not(const std::string &col_name_, const std::string val_);
        QueryResult &eval(QueryResult &qr) override;
        std::string & res() override;
    
    private :
        std::string col_name;
        std::string val;
};

#endif