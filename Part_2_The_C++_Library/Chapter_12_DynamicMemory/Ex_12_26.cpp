/************************************************************************************************************************************************************
 * @file Ex_12_26.cpp
 * @brief 
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

//  using new to dynamic allocate memory
/***************************************************************
string *const p = new string[n]; // construct n empty strings
string s;
string *q = p; // q points to the first string

while (cin >> s && q != p + n)
    *q++ = s; // assign a new value to *q
const size_t size = q - p; // remember how many strings we read

// use the array
delete[] p;
****************************************************************/

#include <iostream>
#include <memory>
#include <string>

int main(){
    std::cout << "How many words : " << std::endl;
    std::string::size_type n;

    // allocates memory for constructing n string objects
    std::allocator<std::string> stralloc;
    std::cin >> n;
    std::string *strptr = stralloc.allocate(n);

    std::string word;
    std::string *iter = strptr;
    while(std::cin >> word && iter != strptr + n){  //  loop ends either by eof or running out of memory
        std::construct_at(iter++, word);   //  each string object is constructed seperately at memory pointed by iter
    }

    decltype(n) total = iter - strptr;
    std::cout << "\nTotal no of words entered : " << total << "\nlist of words : " << std::endl;
    while(iter != strptr){
        std::cout << *--iter << " ";
        std::destroy_at(iter);  //  destroys the object at memory pointed by iter
    }

    stralloc.deallocate(strptr, n); //  deallocates the memory previously allocated by allocate

    return 0;
}