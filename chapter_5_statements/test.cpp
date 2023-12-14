#include <iostream>
#include <stdexcept>
int main(){
    bool first = true;

    first :
    first = !first;
    std::cout << "one" << std::endl;
    std::cout << "2" << std::endl;
    std::cout << "3" << std::endl;
    std::cout << "4" << std::endl;
    std::cout << "5" << std::endl;
    half :
    std::cout << "6" << std::endl;
    std::cout << "7" << std::endl;
    std::cout << "8" << std::endl;
    if(!first){
        first
        goto half ;

    std::cout << x << " " << y <<std::endl;
    return 0;
}