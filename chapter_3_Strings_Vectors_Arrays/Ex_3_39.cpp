/*  Exercise 3.39: Write a program to compare two strings. Now write a program to compare the values of two C-style 
    character strings.*/

#include <iostream>
#include <string>
#include <cstring>

int main(){
    std::string str1{"tello"}, str2{"hello world"};
    const char ch1[] = "tello";
    const char ch2[] = "hello world";

    if( str1 == str2 ){
        std::cout << "both strings are equal";
    }else if(str1 < str2 ){
        std::cout << "str1 is lesser than str2";
    }else{
        std::cout << "str1 is greater than str2";
    }

    auto n = strcmp(ch1, ch2);
    if( !n ){
        std::cout << "both const char are equal";
    }else if( n < 0){
        std::cout << "ch1 is lesser than ch2";
    }else{
        std::cout << "ch1 is greater than ch2";
    }

    return 0;

}