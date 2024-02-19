/************************************************************************************************************************************************************
 * @file Ex_16_52.cpp
 * @brief Exercise 16.52: Write a program to check your answer to the previous question.
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include<iostream>

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest) {
    std::cout << t << " " << sizeof...(Args) << " " << sizeof...(rest) << std::endl;
}

int main() {

    int i = 0; double d = 3.14; std::string s1 = "how now brown cow", s2 = "Hello world";
    foo(i, s1, 42, d, s2); // three parameters in the pack
    std::cout << "===================================" << std::endl;
    foo(s1, s2, 42, "hi"); // two parameters in the pack
    std::cout << "===================================" << std::endl;
    foo(d, s1, s2); // one parameter in the pack
    std::cout << "=====================================" << std::endl;
    foo("hi"); // empty pack

    return 0;
}

/************************************************************************************************************************************************************
 * sizeof...(template_parameter_pack) and size...of(function_parameter_pack) will always remains the same. It's a misunderstanding
 * that template parameter pack will consists of different types, whether the types are same or different it allways 
 * contains all the types in the arguments of the call.
 * ex:- foo(d, s1, s2)
 *  T is deduced as double(1st argument), 
 *  s1, s2,  types[std::string, std::string] of the remaining arguments forms the template parameter pack
 *  function parameter pack will contain  s1, s2
 * 
 *************************************************************************************************************************************************************/