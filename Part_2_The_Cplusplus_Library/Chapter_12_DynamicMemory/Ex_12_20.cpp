/************************************************************************************************************************************************************
 * @file Ex_12_20.cpp
 * @brief Exercise 12.20: Write a program that reads an input file a line at a time into a StrBlob and uses a StrBlobPtr to 
 * print each element in that StrBlob.
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "Ex_12_19_StrBlobPtr.cpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

int main(){
    std::ifstream ifile("text.txt");
    std::string line;
    StrBlob blob;
    while(getline(ifile, line)){
        blob.push_back(line);
    }

    StrBlob::size_type pos = 0;
    for(StrBlobPtr beg(blob.begin()); pos != blob.size(); beg.incr(), ++pos){
        std::cout << beg.deref() << std::endl;
    }

    return 0;
}