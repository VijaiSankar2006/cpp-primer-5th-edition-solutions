#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>

int main(){
    
    std::ifstream ifile("text1.txt");   //  ifile is filestream which can be used to read like cin from file "text1.txt"
    std::ofstream ofile("text2.txt");   //  ofile is filestream which can be used to write like cout to "text2.txt" 
    
    std::ostringstream o_strstream;     //  strings are writen to o_strstream using <<
    std::ostream_iterator<std::string> o_striter(o_strstream, "\n");  // o_striter wites to o_strstream along with "\n"; 
    std::istream_iterator<std::string> i_striter(ifile), end ; // i_striter reads string from ifile using >>
    std::vector<std::string> words(i_striter, end);  // words is initialised with contents by iterating i_striter

    ifile.clear();      
    ifile.open("text1.txt"); // file is reopened as iterator is at eof, clear() won't rewind iterator in file

    std::string line;
    while(getline(ifile, line)){   // reads a line from ifile - ifstream
        *o_striter++ = line;       // writes to o_strstream along with "\n" 
    }

    ofile << o_strstream.str();   //  writes string contained with o_strstream in ofile, ofstream

    return 0;
}