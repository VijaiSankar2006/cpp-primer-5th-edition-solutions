/*  Exercise 6.51: Write all four versions of f. Each function should print a distinguishing message. Check your answers
 *  for the previous exercise. If your answers were incorrect, study this section until you understand why your answers
 *  were wrong.*/

#include <iostream>
void f(){
    std::cout << "f() called\n";
}
void f(int){
    std::cout << "f(int) called\n";
}
void f(int, int){
    std::cout << "f(int, int) called\n";
}
void f(double, double = 3.14){
    std::cout << "f(double, double = 3.14) called";
}

int main(){
    // f(2.56,42); - ambiguous
    f(42);
    f(42,0);
    f(2.56,3.14);
    return 0;
}