/*  Exercise 5.5: Using an if–else statement, write your own version of the program to generate the letter grade from a 
 *  numeric grade */

#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> grades{"F","E","D","C","B","A++"};
    std::cout << "Enter the grade : ";
    int g;
    std::cin >> g;
    std::string grade_letter;
    if( g < 60 ){
        grade_letter = grades[0];
    }else {
        grade_letter = grades[(g - 50)/10];
    }    
    if( g != 100 ){
        g /= 10;
        if( g > 7 ){
            grade_letter += "+";
        }else if( g < 3){
            grade_letter += "-";
        }
    }

    std::cout << std::endl << grade_letter << std::endl;
    return 0;
}