/************************************************************************************************************************************************************
 * @file Database.cpp
 * @brief main interface of the DBMS
 * @date 2024-03-15
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include "Table.h"
#include "Query.h"
#include <iterator>
#include <map>
#include <fstream>
#include <limits>


using std::vector; using std::string; using std::map; using std::pair;
std::string prompt("sql[ o to submit ] > ");
std::string err_prompt(prompt + "error : ");

void query_table(Table &tb);
void display_help();
Table * create_table();
void save_to_file(Table &tb, const std::string &ifile_name);
void clear_cin();

int main() {
    std::set<std::string> first{"SELECT","CREATE","ADD", "DELETE", "EXIT","HELP","DELETE","SAVE","CLOSE"};
    std::vector<std::string> sql_query;
    bool table_exist = false;
    Table * tb;
    std::ifstream ifile;
    std::string ifile_name;
    std::cout << "SQL commands supported : \nADD CREATE DELETE EXIT SAVE SELECT" << std::endl;
    while (1) {
        std::cout << prompt;
        string cmd1, cmd2;
        std::cin >> cmd1;
        cmd1 = str_upper(cmd1);

        if (cmd1 == "CREATE") {
            std::cin >> cmd2;
            cmd2 = str_upper(cmd2);
            if (!table_exist) { 
                tb = create_table();
                if (tb) {
                    table_exist = true;
                } else {
                    std::cerr << err_prompt << "unable to open table" << std::endl;
                }
            } else {
                std::cerr << err_prompt << "Table is already open" << std::endl;
            }  
            clear_cin();
        }

        if (cmd1 == "SELECT") {
            if (table_exist) {
                query_table(*tb);
            } else {
                std::cerr << err_prompt << "no table exist" << std::endl;
            }
            clear_cin();
        }

        if (cmd1 == "ADD") {
            if (table_exist) {
                add_record(*tb);
            } else {
                std::cerr << err_prompt << "Table need to be created" << std::endl;   
            }
            clear_cin();
        }

        if (cmd1 == "EXIT") {
            return 0;
        }

        if (cmd1 == "DELETE") {
            if (table_exist) {
                string p_key, val, op;
                std::cin >> p_key >> op >> val;
                tb->remove_record({p_key, val});
            }
            clear_cin();
        }

        if (cmd1 == "SAVE") {
            if (table_exist) {
                std::cout << "file name : ";
                string file_name;
                std::cin >> file_name;
                save_to_file(*tb, file_name);
            } 
            clear_cin();      
        }
    }
}

void display_help() {
    std::map<string, string> syntax_dict{ {{"CREATE"}, {"CREATE <table_name> \n\tcreates a table with table name as table_name"}},
                                          {{"SELECT"}, {"SELECT <col_name1>, <col_name2> ...\n\tdisplays the records with col_name1 and col_name2 from the table, SELECT * refers to all coloumns"}},
                                          {{"FROM"}, {"FROM <table_name> \n\tfetches the records from table table_name"}},
                                          {{"WHERE"}, {"WHERE <constraint> \n\tfilters the records which matches the constraint"}},
                                          {{"AND"}, {"<constraint1> AND <constraint2>\n\tcontains only records matches both the constraint"}},
                                          {{"OR"}, {"<constraint1> OR <constraint2>\n\tcontains records which matches either or the other constraint"}},
                                          {{"NOT"}, {"NOT <constraint>\n\tcontains records that doesn't match the constraint"}},
                                          {{"CONSTRAINT"}, {"<col_name> <operator> <value>\n\ta record is a match if the operator returns true for the value in the specified coloumn"}},
                                          {{"OPERATOR"}, {"=, equality \n!=, in-equality \n<, less than \n>, greater than \n<=, less than or equal to \n>=, greater than or equal to"}},
                                          {{"ORDER_BY"}, {"ORDER_BY <col_name> DESC \n\tsorts the records based on the values in col_name.\n\tDESC is optional, makes the sorting in descendant order"}},
                                          {{"CLOSE"}, {"CLOSE <file_name>\n\tcloses the file named file_name"}},
                                          {{"OPEN"}, {"OPEN <file_name>\n\topens the file nameed file_name"}},
                                          {{"DELETE"}, {"DELETE <table_name>\n\tdeletes the table"}},
                                          {{"EXIT"}, {"\texits the program"}},
                                          {{"SAVE"}, {"\tsaves the table to file"}},
                                          {{"SAVE_AS"},{"\tsaves the table to new file"}}
                                        };

    string cmd;
    std::istream_iterator<string> beg(std::cin), end;
    vector<string> sql_query(beg, end);

    if (sql_query.back() != "0") {
        std::cerr << err_prompt << "syntax error, correct form HELP <cmd>" << std::endl;
        return;
    }

    if (sql_query.size() > 2 || sql_query.empty() || syntax_dict.find(sql_query[0]) == syntax_dict.end()) {
        std::cerr << err_prompt << "syntax error, correct form HELP <cmd>" << std::endl;
        return;
    }

    std::cout << prompt << syntax_dict[sql_query[0]] << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'0');
    std::cin.clear();
    return;                   
}

Table * create_table() {

    string tbname;
    std::cin >> tbname;

    Table::schema_type schema;
    string p_key;
    create_schema(schema, p_key);
    return new Table(schema, p_key, tbname);
}

void save_to_file(Table &tb, const std::string &file_name) {
    std::ofstream ofile(file_name);
    if (!ofile) {
        std::cerr << err_prompt << "unable to save file, try again" << std::endl;
        return;
    } 

    ofile << tb;
    std::cout << prompt << "File Saved successfully" << std::endl;

    ofile.close();
    return; 
}

void clear_cin() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '0');
    std::cin.clear();  
}

void query_table(Table &tb) {
    string word;
    vector<string> q_lst;
    while (std::cin >> word && word[0] != '0') {
        string up_word = str_upper(word);
        if (SqlParser::keywords.find(up_word) != SqlParser::keywords.end()) {
            q_lst.push_back(up_word);
        } else {
            q_lst.push_back(word);
        }    
    }
    SqlParser s1(q_lst, tb);
    s1.eval();

    return;
}
 