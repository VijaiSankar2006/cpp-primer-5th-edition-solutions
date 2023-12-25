//  Exercise 2.20:
//  What does the following program do?

#include <iostream>

int main(){
    int i = 42;         
    int *p1 = &i;
    *p1 = *p1 * *p1;   // since dereference operator,'*' has higher precedence, rhs becomes '42 * 42', which is then assigned to i.
    std::cout << *p1 << std::endl;
}