/*  Exercise 5.11: Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines
 *  read. */

#include <iostream>
int main(){
     std::cout << "Enter a sentence : ";
    char ch;
    size_t aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, others = 0, newlnCnt = 0, spCnt = 0, tabCnt = 0;
    std::string line;
    while( getline(std::cin, line) ){
        ++newlnCnt;
        auto beg = line.begin();
        while( beg != line.end()){            
            ch = *beg++;
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
            }else if(ch == ' '){
                ++spCnt;
            }else if(ch == '\t'){
                ++tabCnt;
            }else{
                ++others;
            }
        }    
    }

    std::cout << "\nothers = "<< others << std::endl;
    std::cout << "a : " << aCnt << std::endl;
    std::cout << "e : " << eCnt << std::endl;
    std::cout << "i : " << iCnt << std::endl;
    std::cout << "o : " << oCnt << std::endl;
    std::cout << "u : " << uCnt << std::endl;
    std::cout << "spaces : " << spCnt << std::endl;
    std::cout << "tabs : " << tabCnt << std::endl;
    std::cout << "new line : " << newlnCnt << std::endl;
    return 0;
}