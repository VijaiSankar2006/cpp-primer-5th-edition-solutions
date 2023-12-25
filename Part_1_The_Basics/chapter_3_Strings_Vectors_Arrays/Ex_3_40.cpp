/*  Exercise 3.40: Write a program to define two character arrays initialized from string literals. Now define a third 
    character array to hold the concatenation of the two arrays.Use strcpy and strcat to copy the two arrays into the 
    third   */

#include <iostream>
#include <cstring>

int main(){
    const char ch1[] = {"Hello"}, ch2[] = {"world"};
    const auto size(strlen(ch1) + strlen(ch2));
    char result[size + 2];  //   +1 for null character and +1 for space

    strcpy(result, ch1);
    strcat(result," ");
    strcat(result, ch2); 
    std::cout << result << std::endl;
}