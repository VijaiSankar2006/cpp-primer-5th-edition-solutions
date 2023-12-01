/*  Exercise 2.8: Using escape sequences, write a program to print 2M followed by a new-
 *  line. Modify the program to print 2, then a tab, then an M, followed by a newline   */

#include <iostream>

int main(){
    std::cout << "2\115\12";
    std::cout << "2\t\115\12";
    return 0;
}