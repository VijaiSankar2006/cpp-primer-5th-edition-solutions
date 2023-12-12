/*  Exercise 4.22: Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades
 *  between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should
 *  use one or more if statements. Which version do you think is easier to understand and why?*/

#include <iostream>

int main(){
    int grade;
    std::cout << "Enter the grade : ";
    std::cin >> grade;
    std::string result1 = grade > 90 ? "high pass" : grade > 75 ? "pass" : grade >= 60 ? "low pass" : "fail";
    std::string result2;

    if( grade > 90 ){
        result2 = "high pass";
    }else if( grade > 75){
        result2 = "pass";
    }else if(grade >= 60){
        result2 = "low pass";
    }else {
        result2 = "fail";
    }

    std::cout << result1 << " " << result2 << std::endl;
    return 0;
}

//  nested if-else is easier to read and understand than nested conditional operator