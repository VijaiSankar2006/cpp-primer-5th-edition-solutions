/************************************************************************************************************************************************************
 * @file Ex_14_35.cpp
 * @brief Exercise 14.35: Write a class like PrintString that reads a line of input from an istream and returns a string
 * representing what was read. If the read fails, return the empty string.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>

class PrintString{
    public :
        PrintString(std::istream &istrm = std::cin) : is(istrm) {}
        std::string operator()(){
            if(getline(is, str))
                return str;
            else    
                return std::string();
        }

    private :
        std::istream &is;
        std::string str;
};
