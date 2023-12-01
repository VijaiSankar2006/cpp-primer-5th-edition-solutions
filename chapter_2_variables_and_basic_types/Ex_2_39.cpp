//  Exercise 2.39: Compile the following program to see what happens when you forge the semicolon after a class definition.
//  Remember the message for future reference. 
//  struct Foo { /* empty */ } // Note: no semicolon

#include <iostream>

struct Foo{
    /* empty */
}

int main()
{
    std::cout << "hello world" << std::endl;
}

output : 
 error: expected ‘;’ after struct definition
    9 | }
      |  ^
      |  ;