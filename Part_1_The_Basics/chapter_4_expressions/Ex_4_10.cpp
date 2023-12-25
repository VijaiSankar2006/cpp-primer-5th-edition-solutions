/*  Exercise 4.10: Write the condition for a while loop that would read ints from the standard input and stop when the \
    value read is equal to 42.  */

#include <iostream>

int main(){
    std::cout << "Enter a list of numbers, to end enter 42 : \n";
    int num;
    int count = 0;
    while( (std::cin >> num) && num != 42){
        ++count;
    }
    std::cout << count << std::endl;
    return 0;
}