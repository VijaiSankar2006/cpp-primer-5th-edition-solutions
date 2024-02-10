#include <iostream>
#include <chrono>
#include <vector>

/**
 * @brief program to test using std::chrono to measure time consumed for statements, expressions.
 *  
 */

int main(){
    auto t0 = std::chrono::high_resolution_clock::now();
    std::string str1("alpha"), str2("beta"), str3("gamma");
    
    std::vector<std::string> svec{str1, str2, str3};
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "the elapsed time : " << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() << std::endl;

    return 0;
}