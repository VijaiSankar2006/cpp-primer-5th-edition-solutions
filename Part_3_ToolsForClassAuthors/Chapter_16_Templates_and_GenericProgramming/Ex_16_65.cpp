/************************************************************************************************************************************************************
 * @file Ex_16_65.cpp
 * @brief Exercise 16.65: In § 16.3 (p. 698) we defined overloaded two versions of debug_rep one had a const char* and
 * the other a char* parameter. Rewrite these functions as specializations.
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <sstream>

std::string debug_rep(const std::string &s);

template <typename T>
std::string debug_rep(const T &val) {
    std::ostringstream ret;  
    ret << "debug_rep(const T &val) : \n";
    ret << val;

    return ret.str();
} 

template <>
std::string debug_rep<char *>(char *const &val) {
    std::string str(val);
    return "debug_rep<char *>\n" + debug_rep(&str);
}

template <>
std::string debug_rep<const char *>(const char * const &val) {
    const std::string str(val);
    return "debug_rep<const char *>" + debug_rep(&str);
}

template <typename T> 
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "debug_rep(T *p) \n";
    if(p) {
        ret << p << " " << debug_rep(*p);
    } else {
        ret << "null pointer" << " ";
    }

    return ret.str();
} 


std::string debug_rep(const std::string &s) {
    return "debug_rep(const std::string &s) \"" + s + '"';
}

int main() {
    int num = 10;
    double d = 8.9;
    std::string str1 = "hello";
    const char *cptr = "world";
    char carr[] = {'a','l','p','h','a'};

    std::cout << debug_rep(num) << std::endl;
    std::cout << debug_rep(d) << std::endl;
    std::cout << debug_rep(str1) << std::endl;
    std::cout << debug_rep("string literal") << std::endl;
    std::cout << debug_rep(cptr) << std::endl;
    std::cout << debug_rep(carr) << std::endl;

    return 0;
}

