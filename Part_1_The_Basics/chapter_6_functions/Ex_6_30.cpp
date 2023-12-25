/*  Exercise 6.30: Compile the version of str_subrange as presented on page 223 to see what your compiler does with the
 *  indicated errors */

#include <iostream>
using std::string;

bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2; 

    auto size = (str1.size() < str2.size())? str1.size(): str2.size();
    for (decltype(size) i = 0; i != size; ++i){
        if (str1[i] != str2[i])
            return 0;           //  compiler detected the error, return with no value
    }
    std::cout << "past all the return statements in the function" << std::endl;
}

int main(){
    std::string str1("hello"), str2("helloworld");
    std::cout << "before calling str_subrange" << std::endl;
    std::cout << str_subrange(str1,str2) << std::endl;              //  got an output of 64 when there is no return statement, compiler only game warning
    std::cout << "This program's result is undefined" << std::endl;
    return 0;
}