/************************************************************************************************************************************************************
 * @file Ex_8_1.cpp
 * @brief Exercise 8.1: Write a function that takes and returns an istream&. The function should read the stream until it hits
 *        end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid 
 *        before returning the stream.
 * @date 2023-12-25
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

#include <iostream>


std::istream & print(std::istream &);

int main(){
    /*  once we it eof in std::cin the following line is must to recover or else even after cin.clear() and
        cin.good() true cin won't read. */
    //  https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull    

    std::iostream::sync_with_stdio(false);      
    std::cout << "main() invoked print()\n";
    int num;
    print(std::cin);
    std::cout << "cin.good() : " << std::cin.good() << "\ncin.rdstate() : " << std::cin.rdstate() 
                << "\ncin.fail() :  " << std::cin.fail() << "\ncin.eof() : " << std::cin.eof() << std::endl;
    std::cout << "Enter a num : ";
    std::cin >> num;
    std::cout << "\nyou entered : " << num;
    return 0;
}

std::istream & print(std::istream &is){
    std::cout << "condition of cin before input : \n";
    std::cout << is.good() << " " << is.rdstate() << " " << is.fail() << " " << is.eof() << std::endl;
    std::cout << "Enter a sentence : " << std::endl;
    char ch;
    while(is >> ch){
        std::cout << ch;
    }
    std::cout << "state of cin after eof : \n";   
    std::cout << is.good() << " " << is.rdstate() << " " << is.fail() << " " << is.eof() << std::endl;
    is.clear();
    std::cout << "Enter a num : ";
    return is;
}

