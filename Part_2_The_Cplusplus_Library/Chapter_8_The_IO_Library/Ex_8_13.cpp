/************************************************************************************************************************************************************
 * @file Ex_8_13.cpp
 * @brief Exercise 8.13: Rewrite the phone number program from this section to read from a named file rather than from cin.
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;

struct PersonInfo {
string name;
vector<string> phones;
};

bool valid(const std::string &strnum){
    //  will be updated in next chapter
}

std::string format(const std::string &strnum){
    // will be updated in next chapter
}

int main(){
    
    //  opens a file to read
    std::ifstream ifile("contacts.txt");
    if(!ifile){
        cerr << "Unable to open file";
        return -1;
    }

    // opens a file to write
    std::ofstream ofile("formatedContacts.txt");
    if(!ofile){
        cerr << "Unable to open file to write";
        return -1;
    }

    string line, word; 
    vector<PersonInfo> people;  //  people is a vector of PersonInfo, each ele will contain name and vector of phone_nos 
    while (getline(ifile, line)) {    // populating people by processing each line in the file
        PersonInfo info; 
        istringstream record(line); 
        record >> info.name; 
        while (record >> word) 
            info.phones.push_back(word); 
        people.push_back(info); 
    }

    for (const auto &entry : people) {      //  binds a const reference to person's info in people
        ostringstream formatted, badNums; 
        for (const auto &nums : entry.phones) {    // binds a reference to const to each num in a person's phone no vector
            if (!valid(nums)) { 
                badNums << " " << nums; 
            }else 
                formatted << " " << format(nums);
        }

        if (badNums.str().empty()) 
            ofile << entry.name << " " << formatted.str() << endl; 
        else 
            cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
    }   
         
}