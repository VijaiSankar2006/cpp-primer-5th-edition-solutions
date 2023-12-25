/*  Exercise 6.26: Write a program that accepts the options presented in this section. Print the values of the arguments
 *  passed to main. */

#include <iostream>

int main(int argc, char **argv){      //  argv is pointer to pointer to char or argv is a array of pointers to char
    while(*argv){
        std::cout << *argv++ << std::endl;
    }

}
