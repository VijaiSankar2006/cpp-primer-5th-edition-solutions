/************************************************************************************************************************************************************
 * @file Ex_9_43.cpp
 * @brief Exercise 9.43: Write a function that takes three strings, s, oldVal, and newVal.Using iterators, and the insert and
 *        erase functions replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace
 *        common abbreviations, such as “tho” by ”though” and ”thru” by “through”.
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <string>

void replaceStr(std::string &s, const std::string &oldval, const std::string &newval){
    for( auto beg = s.begin(); beg != s.end(); ){           //  beg iterates through s
        if( beg + oldval.size() <= s.end()){                //  if no of characters remaining in s < size of oldval then stop processing s
            std::string seq(beg, beg + oldval.size());          //  assigns first oldval.size() of chars from position iter to a new string    
            if(seq == oldval){         //  if the sequence is same as oldval
                beg = s.erase(beg, beg + oldval.size()); //  erases oldval          
                beg = s.insert(beg,newval.cbegin(), newval.cend()); // inserts newval
                beg = beg + newval.size();      //  moves beg to the character after newval 
            }else{
                ++beg;              // else increment beg by one character
            }
        }else{
            return;             //  returns if remaining characters in s is lessthan oldval
        }    
    }

}

int main(){
    std::string s1("beginthoend tho");
    std::string s2("thruonetwothru thrued threethru");
    replaceStr(s1, "tho","though");
    std::cout << s1 << std::endl;
    replaceStr(s2, "thru", "through");
    std::cout << s2 << std::endl;
    return 0;
}

