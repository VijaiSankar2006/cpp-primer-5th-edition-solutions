//  Generate a hexa-decimal representation of a given number

#include <iostream>
#include <string>

int main(){
    std::string hex{"0123456789ABCDE"};
    std::cout << "Enter series of numbers from 0 to 15 seperated by spaces : ";
    
    std::string result;
    //  code to print the respective hexa decimal number
    std::string::size_type n;
    while( std::cin >> n ){
        if( n < hex.size() ){
            result += hex[n];
        }    
    }

    std::cout << result << std::endl;

    return 0;
}