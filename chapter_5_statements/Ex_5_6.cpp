/*  Exercise 5.6: Rewrite your grading program to use the conditional operator (§ 4.7,p. 151) in place of the if–else
 *  statement.*/

#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> grades{"F","E","D","C","B","A++"};
    std::cout << "Enter the grade : ";
    int g;
    std::cin >> g;
    std::string grade_letter = g < 60 ? grades[0] : grades[(g-50)/10];     
    g /= 10;
    (g > 7 && g != 10) ? grade_letter += "+" : g < 3 ? grade_letter += "-" : grade_letter;
    std::cout << std::endl << grade_letter << std::endl;
    return 0;
}