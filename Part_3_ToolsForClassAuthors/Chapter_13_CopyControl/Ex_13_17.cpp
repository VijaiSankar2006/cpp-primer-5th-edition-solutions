/************************************************************************************************************************************************************
 * @file Ex_13_17.cpp
 * @brief Exercise 13.17: Write versions of numbered and f corresponding to the previous three exercises and check whether you
 * correctly predicted the output.
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
using std::cout; using std::endl;

/*  // version 1 with synthesised copy_constructor
struct numbered{
    static size_t count;
    size_t mysn;
    numbered() : mysn(++count) {}
};
size_t numbered::count = 0;

void f (numbered s) { cout << s.mysn << endl; }

int main(){
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    return 0;
}    

output :
    1 
    1
    1
*/

/*  // version 2 : with copy_constructor
struct numbered{
    static size_t count;
    size_t mysn;
    numbered() : mysn(++count) {}
    numbered(const numbered &n) : mysn(++count) {}  
};
size_t numbered::count = 0;

void f (numbered s) { cout << s.mysn << endl; }

int main(){
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    return 0;
}

output :
   4
   5
   6

*/

//version 3 : with call by reference 
struct numbered{
    static size_t count;
    size_t mysn;
    numbered() : mysn(++count) {}
    numbered(const numbered &n) : mysn(++count) {}  
};
size_t numbered::count = 0;

void f (const numbered &s) { cout << s.mysn << endl; }

int main(){
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    return 0;
}

/*
output :
    1
    2
    3
*/