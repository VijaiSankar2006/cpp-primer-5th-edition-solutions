#include <iostream>
#include <string>

int main(){
    std::cout << "Enter a sentence : ";
    char ch;
    size_t aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, others = 0;

    while( std::cin >> ch){
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

    std::cout << "others = "<< others << std::endl;
    std::cout << "a : " << aCnt << std::endl;
    std::cout << "e : " << eCnt << std::endl;
    std::cout << "i : " << iCnt << std::endl;
    std::cout << "o : " << oCnt << std::endl;
    std::cout << "u : " << uCnt << std::endl;

    return 0;
}