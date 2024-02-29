#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
/**
typedef std::vector<std::string> schema;
typedef std::vector<void *> record;

struct table {
    schema type;
    std::vector<record> data;
    static size_t count;
};

size_t table::cout = 0;

bool write_record(const table &t) {
    for(auto s : t.type) {
        std::cout << std::setw(10);
        std::cout << s;
    }
    std::cout << std::endl;
    size_t i = 0;
    for(auto s : t.type) {
        std::cout << std::setw(10);
        switch(s[0]) {
            case 'i' : std::cout << *(static_cast<int *>(t.data[i])); break;
            case 'f' : std::cout << *(static_cast<float *>(t.data[i])); break;
            case 'd' : std::cout << *(static_cast<double *>(t.data[i])); break;
            case 'c' : std::cout << *(static_cast<char *>(t.data[i])); break;
        }   
        ++i;
    }
    return 1;
}

bool read_record(table &t) {
    for(auto s : t.type) {
        switch(s[0]) {
            case 'i' : int val1; std::cin >> val1;
                       t.data.push_back(new int(val1));
                       break;
                       
            case 'f' : float val2; std::cin >> val2;
                       t.data.push_back(new float(val2));
                       break;
                       
            case 'd' : double val3; std::cin >> val3;
                       t.data.push_back(new double(val3));
                       break;
                       
            case 'c' : char val4; std::cin >> val4;
                       t.data.push_back(new char(val4));
                       break;             
        }
    }    
    return 1;
}

int main() {
    std::cout << "create a record type[0 to finish] :\n";
    std::string word;
    std::vector<std::string> s_type;
    std::vector<void *> rec_val;

    while(std::cin >> word) {
        if(word.size() == 1)
            break;
        rec_type.push_back(word);
    }
    
    table tb1{s_type};
    std::cout << "Enter a record : \n" << std::endl;
    read_record(tb1);
    std::cout << "\noutput : \n" << std::endl; 
    write_record(tb1);

    return 0;
}

**/

