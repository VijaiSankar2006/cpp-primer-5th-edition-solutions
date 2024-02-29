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
#inlcude "Table.h"

Class Table;
class QueryResult {
    friend class From;
    friend class Where;
    friend class And;
    friend class Or;
    friend Class Not;
    private :
        QueryResult(std::set<Table::row> records_, Table::schema &schema_type_)
            : records(records_), schema(schema_) {}

        std::set<Table::row> records;
        Table::schema_type schema;
};

class From {
    protected :
        From(Table &tb_) : tb(tb_) {}
    public :
        qr eval() {
            return QR(tb.);  
        }
};

class QueryBase {
    protected :
        QueryBase();
        virtual qr& eval() = 0; 
        virtual std:string & res() = 0;
};

class Where : public QueryBase {
    public :
        Where(const Table &tb);
        Where(const std::string &col_name_, const std::string &val_);
        qr & eval() override ;
        std::string & res() override ;
    private :
        QueryResult &qr;
        std::string col_name;
        std::string val; 
        bool all = false;
};

class Binary_operator : public Where {
    protected :
        Binary_operator(const std::string& lhs_col_name_, const std::string &lhs_val_,
            const std::string& rhs_col_name_, const std::string &rhs_val_, const std::string &op_);
        qr & eval() = 0;
        std::string &res () override ;    

    protected : 
        QueryResult &qr;
        std::string lhs_col_name;
        std::string lhs_val;
        std::string rhs_col_name;
        std::string rhs_val;
        std::string operand;
}

class And : public Binary_operator {
    public :
        And(const std::string& lhs_col_name_, const std::string &lhs_val_,
            const std::string& rhs_col_name_, const std::string &rhs_val_);
        qr &eval;
        std::string res() override;
};

class Or : public Binary_operator {
    public :
        Or(const std::string& lhs_col_name_, const std::string &lhs_val_,
            const std::string& rhs_col_name_, const std::string &rhs_val_);
        qr & eval() overrirde ;
        std::string res() override;
};

class Not : public Where {
    public :
        Not(const std::string &col_name_, const std::string val_);
        qr &eval() override;
        std::string & res();
    
    private :
        std::string col_name;
        std::string val;
};

#endif