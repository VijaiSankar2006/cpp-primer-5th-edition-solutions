/************************************************************************************************************************************************************
 * @file Query.cpp
 * @brief definitions of all Database Query related classes
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 *
 *************************************************************************************************************************************************************/

#include "Query.h"
#include "Table.h"
#include "Types.cpp"
#include "pause.h"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <stack>

using namespace std::placeholders;
using std::set;
using std::stack;
class Table;
std::ostream& operator<<(std::ostream& os, const Table& tb);
std::ostream& operator<<(std::ostream& os, const QueryResult& qr);
extern std::map<string, std::function<bool(const vector<void*>, const string&, int, size_t)>> op_map;

// QueryResult class members definition----------
QueryResult::QueryResult(Table& tb_, Table& og_)
    : tb(tb_)
    , original(og_)
{
}
QueryResult::QueryResult(Table* tb_, Table& og_)
    : tb(*tb_)
    , original(og_)
{
}
QueryResult::QueryResult(const error_type& e)
    : error(e)
{
}
std::ostream& operator<<(std::ostream& os, const QueryResult& qr)
{
    if (qr.error.first) {
        os << "> error : \n> " <<  qr.error.second << std::endl;
    } else {
        os << std::endl << qr.tb << std::endl;
    }    
    return os;
}
//-----------------------------------------------

//  From class member definitions---------------
From::From(const Table& tb_)
{
    tb_lst.push_back(tb_);
}
From::From(vector<string> tb_name_lst)
{
    std::ifstream ifile(tb_name_lst[0]);
    if (!ifile) {
        tb_error.push_back({ true, tb_name_lst[0] + " doesn't exist" });
    } else {
        tb_error.push_back({ false, "" });
        Table tb(ifile);
        tb_lst.push_back(tb);
    }
}

QueryResult From::eval()
{
    if (!tb_error[0].first) {
        Table og_tb(*(tb_lst[0].new_table(tb_lst[0].records.begin(), tb_lst[0].records.end())));
        return QueryResult(tb_lst[0], og_tb);
    } else {
        return QueryResult(tb_error.front());
    }
};

string From::res()
{
    return string("From " + tb_lst[0].name);
}

//----------------------------------------------

// Query class members defintions---------------
Query::Query(const Table::constraint& item, const string& op_)
    : qb_ptr(new Where(item, op_))
{
}

Query::Query(QueryBase* q)
    : qb_ptr(q)
{
}

QueryResult Query::eval(QueryResult& qr)
{
    return qb_ptr->eval(qr);
}

string Query::res()
{
    return qb_ptr->res();
}
//------------------------------------------------

// Where class member definitions
Where::Where()
    : all(true)
{
}

Where::Where(const Table::constraint& item_, const string& op_)
    : item(item_)
    , op(op_)
{
}

QueryResult Where::eval(QueryResult& qr)
{
    if (all) {
        return QueryResult(qr.tb, qr.original);
    }

    std::string col_name = item.first;
    auto p = qr.tb.get_col_info(col_name);
    if (p.first == string::npos) {
        return QueryResult(error_type({ true, "unknown identifier " + col_name}));
    }
    Table::types t;
    switch (p.second[0]) {
    case 'i':
        t = Table::int_type;
        break;
    case 'd':
        t = Table::double_type;
        break;
    case 'c':
        t = Table::char_type;
        break;
    case 's':
        t = Table::string_type;
        break;
    }

    auto last = std::partition(qr.tb.records.begin(), qr.tb.records.end(), std::bind(op_map[op], _1, item.second, t, p.first));
    std::cout << "where::no_of_items :" << last - qr.tb.records.begin() << std::endl;
    return QueryResult(qr.tb.new_table(qr.tb.records.begin(), last), qr.original);
}

string Where::res()
{
    return "Where " + item.first + " " + op + " " + item.second;
}
//--------------------------------------------------
Query operator~(const Query& q)
{
    return Query(new NotQuery(q));
}

NotQuery::NotQuery(const Query& source)
    : q(source)
{
}

QueryResult NotQuery::eval(QueryResult& qr_)
{
    auto qr = q.eval(qr_);
    Table res_tb(qr.tb.get_schema(), qr.tb.get_pkey());
    for (auto& r : qr.original.records) {
        if (!std::any_of(qr.tb.records.begin(), qr.tb.records.end(), std::bind(compare_equal, _1, r, qr.tb.key_type, qr.tb.key_pos))) {
            res_tb.create_new_record(r);
        }
    }
    return QueryResult(res_tb, qr.original);
}

string NotQuery::res()
{
    return "~(" + q.res() + ")";
}
//---------------------------------------------------------

BinaryQuery::BinaryQuery(const Query& lhs, const Query& rhs, const string& op)
    : lhs(lhs), rhs(rhs), operand(op) {}

string BinaryQuery::res()
{
    return lhs.res() + operand + rhs.res();
}
//--------------------------------------------------------

Query operator&(const Query& lhs, const Query& rhs)
{
    return Query(new AndQuery(lhs, rhs));
}

AndQuery::AndQuery(const Query& lhs, const Query& rhs)
    : BinaryQuery(lhs, rhs, "&")
{
}

QueryResult AndQuery::eval(QueryResult& qr)
{
    auto l_qr = lhs.eval(qr);
    auto r_qr = rhs.eval(qr);
    Table tb1(l_qr.tb.get_schema(), l_qr.tb.get_pkey());
    for (auto beg = l_qr.tb.records.begin(); beg != l_qr.tb.records.end(); ++beg) {
        if (std::any_of(r_qr.tb.records.begin(), r_qr.tb.records.end(), std::bind(compare_equal, _1, *beg, r_qr.tb.key_type, r_qr.tb.key_pos))) {
            tb1.create_new_record(*beg);
        }
    }
    return QueryResult(tb1, qr.original);
}
//---------------------------------------------------
Query operator|(const Query& lhs, const Query& rhs)
{
    return new OrQuery(lhs, rhs);
}

OrQuery::OrQuery(const Query& lhs, const Query& rhs)
    : BinaryQuery(lhs, rhs, "|")
{
}

QueryResult OrQuery::eval(QueryResult& qr)
{
    auto l_qr = lhs.eval(qr);
    auto r_qr = rhs.eval(qr);
    Table tb(qr.tb.get_schema(), qr.tb.get_pkey());
    for (auto beg = l_qr.tb.records.begin(); beg != l_qr.tb.records.end(); ++beg) {
        if (!std::any_of(r_qr.tb.records.begin(), r_qr.tb.records.end(), std::bind(compare_equal, _1, *beg, r_qr.tb.key_type, r_qr.tb.key_pos))) {
            tb.create_new_record(*beg);
        }
    }

    for (auto beg = r_qr.tb.records.begin(); beg != r_qr.tb.records.end(); ++beg) {
        tb.create_new_record(*beg);
    }

    return QueryResult(tb, qr.original);
}

//------------------------------------------------------------
Select::Select(const vector<string>& col_lst_)
    : col_lst(col_lst_)
{
}

QueryResult Select::eval(QueryResult& qr)
{
    Table tb = qr.tb;

    std::cout << std::endl;
    size_t sz = 14;
    string line_break(col_lst.size() * 14 + 5, '=');
    std::cout << "s.no ";
    for (auto s : col_lst) {
        std::cout << std::setw(sz) << s;
    }
    std::cout << "\n" + line_break << std::endl;

    int i = 0;
    for (auto& r : tb.records) {
        std::cout << std::setw(5) << ++i;
        for (auto s : col_lst) {
            auto col_info = tb.get_col_info(s);
            switch (col_info.second[0]) {
            case 'i':
                std::cout << std::setw(14) << *static_cast<int*>(r[col_info.first]);
                break;
            case 'd':
                std::cout << std::setw(14) << *static_cast<double*>(r[col_info.first]);
                break;
            case 'c':
                std::cout << std::setw(14) << *static_cast<char*>(r[col_info.first]);
                break;
            case 's':
                std::cout << std::setw(14) << *static_cast<string*>(r[col_info.first]);
                break;
            }
        }
        std::cout << std::endl;
    }

    return qr;
}

string Select::res()
{
    string str;
    for (auto s : col_lst) {
        str += " " + s;
    }

    return str;
}
//-------------------------------------------------------
string str_upper(string str)
{
    for (auto& c : str) {
        c = std::toupper(c);
    }
    return str;
}
//-----------------------------------------------------------

Order_by::Order_by(const vector<string>& order_list_)
    : order_list(order_list_)
{
}

QueryResult Order_by::eval(QueryResult qr)
{
    for (auto beg = order_list.begin(); beg != order_list.end(); ++beg) {
        if (str_upper(*beg) == "DESC") {
            asc = false;
        }
    }

    for (auto beg = order_list.begin(); beg != order_list.end(); ++beg) {
        if (str_upper(*beg) == "DESC") {
            continue;
        }

        auto col_info = qr.tb.get_col_info(*beg);
        Table::types t;
        switch (col_info.second[0]) {
        case 'i':
            t = Table::int_type;
            break;
        case 'd':
            t = Table::double_type;
            break;
        case 'c':
            t = Table::char_type;
            break;
        case 's':
            t = Table::string_type;
            break;
        }
        if (asc) {
            std::sort(qr.tb.records.begin(), qr.tb.records.end(), std::bind(compare_less, _1, _2, t, col_info.first));
        } else {
            std::sort(qr.tb.records.begin(), qr.tb.records.end(), std::bind(compare_less, _2, _1, t, col_info.first));
        }
    }
    return qr;
}
//-----------------------------------------------------------
set<string> SqlParser::keywords{"FROM", "WHERE", "AND", "OR", "NOT", "ORDERBY"};

bool SqlParser::check(const string &str) {
    return (keywords.find(str_upper(str)) != keywords.end());
}

SqlParser::SqlParser(const vector<string>& lst)
    : sql_query(lst)
{
    auto beg = sql_query.begin();
    if (beg != sql_query.end() && str_upper(*beg) != "SELECT") {
        s_error = { true, "syntax error : expected SELECT" };
    } else {
        ++beg;
        while (beg != sql_query.end() && (!check(*beg))) {
            select_lst.push_back(*beg++);
        }
        if (select_lst.empty()) {
            s_error = { true, "identifier required after select, SELECT <what>" };
            beg = sql_query.end();
        }

        if (beg != sql_query.end() && str_upper(*beg) == "FROM") {
            keywords.erase("FROM");
            ++beg;
            while (beg != sql_query.end() && (!check(*beg))) {
                from_lst.push_back(*beg++);
            }
            if (from_lst.empty()) {
                f_error = { true, "required <table name>" };
            }
        } else {
            f_error = { true, "from clause is missing" };
            beg = sql_query.end();
        }

        if (beg != sql_query.end() && str_upper(*beg) == "WHERE") {
            keywords.erase("WHERE");
            ++beg;
            auto last = std::find(sql_query.begin(), sql_query.end(), "ORDER_BY");
            bool lhs_seen = false;
            while (beg != last ) {
                if (last - beg < 3) {
                    w_error = {true, "incomplete where clause : 401"};
                    break;
                }
                if (lhs_seen == false) {
                    if (str_upper(*beg) == "NOT") {
                        ++beg;
                        if (last - beg < 3) {
                            w_error = {true, "incomplete Not clause"};
                            break;
                        }
                        if (!std::any_of(beg, beg + 3, check)) {
                            Query q = Query({*beg, *(beg + 2)}, *(beg + 1));
                            query_stck.push(Query(new NotQuery(q)));
                            lhs_seen = true;
                            beg += 3;
                        } else {
                            w_error = {true, "incomplete Not clause"};
                            break;
                        }
                    }else if (!std::any_of(beg, beg + 3, check)) {
                        query_stck.push(Query({ *beg, *(beg + 2) }, *(beg + 1)));
                        lhs_seen = true;
                        beg += 3;
                    } else {
                        w_error = {true, "incomplete Where clause 429"};
                        break;
                    }
                } else if (str_upper(*beg) == "AND" || str_upper(*beg) == "OR") {   
                    string op = str_upper(*beg);
                    ++beg;
                    if (last - beg < 3) {
                        w_error = {true, "incomplete where 439"};
                        break;
                    }
                    if (!std::any_of(beg, beg + 3, check)) {
                        Query rhs = Query({*beg, *(beg + 2)}, *(beg + 1));
                        Query lhs = query_stck.top();
                        query_stck.pop();
                        if (op == "AND") {
                            query_stck.push(Query(new AndQuery(lhs, rhs)));
                        } else {
                            query_stck.push(Query(new OrQuery(lhs, rhs)));
                        }  
                        beg += 3;     
                    } else {
                        w_error = {true, "incomplete where clause 456"};
                        break;
                    }
                } 
            }
            beg = last;                    
        } else if (beg != sql_query.end() && str_upper(*beg) != "ORDER_BY") {
            w_error = {true, "expected WHERE"};
            beg = sql_query.end();
        }
        if (beg != sql_query.end() && str_upper(*beg) == "ORDER_BY") {
            ++beg;
        } else if (beg != sql_query.end()) {
            o_error = {true, "ORDER_BY clause is incomplete"};
            beg = sql_query.end();
        }

        while (beg != sql_query.end()) {
            string str = *beg++;
            if (beg == sql_query.end() || str_upper(*beg) != "DESC") {
                order_lst.push_back({ str, false });
            } else if (str_upper(*beg) == "DESC") {
                order_lst.push_back({ str, true });
                ++beg;
            } 
        }
    }
}

QueryResult SqlParser::eval()
{
    if(s_error.first || w_error.first || o_error.first || f_error.first ) {
        string str = s_error.second + " " + w_error.second + " " + o_error.second + " " + f_error.second;
        std::cout << "> error : \n> " << str << std::endl;
        return QueryResult(error_type({true, str}));
    }
    auto qr = From(from_lst).eval();
    if (qr.error.first) {
        std::cout << "> error : \n> " << qr.error.second << std::endl;
        return QueryResult(error_type({true, qr.error.second}));
    }
    Where w;
    if (!query_stck.empty()) {
        auto qr1 = query_stck.top().eval(qr);
        qr = qr1;
    } 
    std::cout << qr << std::endl;

    return qr;
}

int main()
{
    const string eq = "=";
    const string sm = "<";
    const string n_eq = "!=";
    const string sm_eq = "<=";
    const string gr = ">";
    const string gr_eq = ">=";

    std::cout << "sql_parser:\n> ";
    string word;
    vector<string> q_lst;
    while (std::cin >> word && word[0] != '0') {
        q_lst.push_back(word);
    }
    std::cout << "no of words : " << q_lst.size() << std::endl;
    SqlParser s1(q_lst);
    s1.eval();

    return 0;
}