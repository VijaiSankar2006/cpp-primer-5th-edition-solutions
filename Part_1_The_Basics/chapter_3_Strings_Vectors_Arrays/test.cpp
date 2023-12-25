#include <iostream>
#include <string>
#include <cstring>

int main(){
    char ch[] = {'h','e','l','l','o','w','o'};
    char ch2[]= {"hello world"};
    std::string str(std::begin(ch), std::end(ch));
    std::cout << str << std::endl;
    std::cout << strcmp(ch,ch2) << std::endl;
}