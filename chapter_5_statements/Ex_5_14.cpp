/*  Exercise 5.14: Write a program to read strings from standard input looking for duplicated words. The program should
 *  find places in the input where one word is followed immediately by itself. Keep track of the largest number of times
 *  a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message
 *  saying that no word was repeated. For example, if the input is how now now now brown cow cow the output should indicate
 *  that the word now occurred three times.*/

#include <iostream>
#include <string>

int main(){
    std::string word, currDup, maxDup;
    size_t currDupCnt = 0, maxDupCnt = 0;

    std::cout << "Enter the sentence : \n";
    std::cin >> maxDup;
    std::string prevWord = maxDup;
    ++maxDupCnt;
    ++currDupCnt;
    while(std::cin >> word){
        if( prevWord == word ){
            ++currDupCnt;
        }else{
            if( maxDupCnt < currDupCnt ){
                maxDupCnt = currDupCnt;
                maxDup = prevWord;
            }
            prevWord = word;
            currDupCnt = 1;
        } 

    }

    std::cout << maxDup << " occurs " << maxDupCnt << std::endl;
    return 0;
}