/************************************************************************************************************************************************************
 * @file Ex_16_56.cpp
 * @brief Exercise 16.56: Write and test a variadic version of errorMsg.
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 **********************************************************************************************************************************************************/

#include <iostream>
#include "Ex_16_48_Debug_rep.cpp"
#include "Ex_16_53_VariadicTemplatePrint.cpp"

template <typename... Args>
void errorMsg(std::ostream &os, const Args&... rest) {  //  expands the template parameter pack in to comma seperated list of types in the pattern const type &
    os << "errorMsg : " << std::endl;
    print(os, debug_rep(rest)...);
}

int main() {
    int i = 56;
    double d = 4.5;
    float f = 56.1234;
    std::string s1 = "Hello", s2 = "world";
    const char *ch = "this works";
    errorMsg(std::cerr, i, d, f, s1, ch);


}
