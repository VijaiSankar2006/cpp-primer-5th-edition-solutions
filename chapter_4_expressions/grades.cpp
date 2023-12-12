//  use bitwise operators to store grades of 30 students

#include <iostream>

int main(){
    unsigned long grades{0};    //  int is guaranteed to have only 16 bits, ul is guaranteed to have 32 bits
    std::cout << "Enter the student no : ";
    int id;
    while(std::cin >> id){
        id -= 1;
        std::cout << "Enter the grade of the student[0/1] : ";
        int g;
        std::cin >> g;
        grades |= g << id;
        std::cout << "Enter the student no : ";
    }

    std::cout << "list of students passed : \n";
    for( size_t i = 0 ; i <= 30; ++i){
        if( (grades & (1 << i)) ) {
            std::cout << i + 1 << " ";
        }    
    } 

    return 0;
}