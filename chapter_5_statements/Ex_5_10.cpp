/*  Exercise 5.10: There is one problem with our vowel-counting program as we’ve implemented it: It doesn’t count capital 
 *  letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, 
 *  your program should count both ’a’ and ’A’ as part of aCnt, and so forth */

#include <iostream>
int main(){
     std::cout << "Enter a sentence : ";
    char ch;
    size_t aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, others = 0;

    while( std::cin >> ch){
        ch = tolower(ch);
        if( ch == 'a'){
            ++aCnt;
        }else if(ch == 'e'){
            ++eCnt;
        }else if(ch == 'i'){
            ++iCnt;
        }else if(ch == 'o'){
            ++oCnt;
        }else if(ch == 'u'){
            ++uCnt;
        }else{
            ++others;
        }
    }

    std::cout << "\nothers = "<< others << std::endl;
    std::cout << "a : " << aCnt << std::endl;
    std::cout << "e : " << eCnt << std::endl;
    std::cout << "i : " << iCnt << std::endl;
    std::cout << "o : " << oCnt << std::endl;
    std::cout << "u : " << uCnt << std::endl;

    return 0;
}