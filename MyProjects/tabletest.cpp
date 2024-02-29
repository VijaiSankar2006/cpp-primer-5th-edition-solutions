/************************************************************************************************************************************************************
 * @brief code to test Table class
 *************************************************************************************************************************************************************/

#include "Table.h"
 
class Table;

void add_rec(Table &tb) {
    
    char repeat;
    do {
        std::cout << "add record : ";
        Table::row record;
        for(auto p : tb.get_schema()) {
            switch(p.second[0]) {
                case 'i' : int val;
                           std::cin >> val; 
                           record.push_back(new int(val));
                           break;
                case 'd' : double vald;
                           std::cin >> vald;
                           record.push_back(new double(vald));
                           break;
                case 'c' : char valc;
                           std::cin >> valc;
                           record.push_back(new char(valc));
                           break;
                case 's' : std::string vals;
                           std::cin >> vals;
                           record.push_back(new std::string(vals));
            }
        }
        tb.add_record(record);
        std::cout << "add another record[y/n] : ";
        std::cin >> repeat;
    } while(repeat == 'y' || repeat == 'Y');
}

void add_schema(Table &tb) {
    std::cout << "Enter the schemma[coloumn_name type] and [0 to exit] : \n" ;
    Table::schema_type t_shcema;
    std::pair<std::string, std::string> col_info;
    while(1) {
        std::cin >> col_info.first >> col_info.second;
        if (col_info.first.size() > 1 && col_info.second.size() > 1) {
            t_shcema.push_back(col_info);
        } else {
            break;
        }
    }
    tb.add_schema(t_shcema);
}

int main() {

    Table tb;
    add_schema(tb);
    add_rec(tb);    
    std::cout << std::endl;
    tb.print();

    return 0;
}