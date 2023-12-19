/*  Exercise 6.48: Explain what this loop does and whether it is a good use of assert: string s;
    while (cin >> s && s != sought) { } // empty body
    assert(cin);*/

    /*  the program repeatedly prompts a string untill it matches with 'sought', on matching the loop ends
     *  then the state of cin is checked by passing it to assert if it is
     *  invalid - assert terminates the program and displays the error msg
     *  valid   - does nothing
     *  this is to check whether execution came out of loop because of 
     *      - input string matched with the 'sought' string
     *      - eof
     *  in case of eof, assert ends the program
     * 
     *  as this is part of the logic of the program, the state should be checked via assert, it should be dealt with if-clause
     *  */

#include <iostream>
#include <cassert>
#include <string>

int main(){
    std::string sought{"vijai"};
    std::string s;
    std::cout << "Enter your name : \n";

    while(std::cin >> s && s != sought){}

    assert(std::cin);
    std::cout << "thank you for participation" << std::endl;

    return 0; 
}