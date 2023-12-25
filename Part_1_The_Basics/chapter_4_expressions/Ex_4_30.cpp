/*  Exercise 4.30: Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
(a) sizeof x + y                 (sizeof x) + y
(b) sizeof p->mem[i]             sizeof ((p->mem)[i])
(c) sizeof a < b                 (sizeof a) < b
(d) sizeof f()                   sizeof (f())              */

#include <iostream>
#include <vector>
class foo{
    public : 
    std::vector<int> ivec;
};

char f(){}

int main(){
    int x = 0, y = 0;
    foo fobj, *ptr = &fobj;
    fobj.ivec = {1,2,3,4,5,6,7,8,9,10};
    std::cout << (sizeof x + y) << std::endl;
    std::cout << (sizeof x < y) << std::endl;
    std::cout << (sizeof f()) << std::endl;
    std::cout << (sizeof ptr->ivec[9]) << std::endl;
    
    return 0;
}