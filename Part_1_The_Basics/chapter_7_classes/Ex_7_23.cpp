/*  Exercise 7.23: Write your own version of the Screen class. */

#include <iostream>
#include <string>
//  definition of class
class Screen{
    public : 
        typedef std::string::size_type pos;   // to hide type of contents

        Screen() = default;     //  default constructor 

        // takes height and width of screen and initilises the contents with ' '
        Screen(const pos h_p, const pos w_p) : height(h_p), width(w_p), contents(std::string(h_p * w_p, ' ')) {}

        // takes height, width, and character to intialises contents
        Screen(const pos h_p, const pos w_p, const char ch) : height(h_p), width(w_p), contents(std::string(h_p * w_p + w_p, ch)) {}

        //  get() returns the character at current cursor position if contents is not empty or else returns -1
        char get() const {
            return (contents.empty()) ? -1 : contents[cursor] ;
        }

        //  get(r,c) returns the character at the position specified by row and coloumn, if position doesn't exist it returns -1
        char get(const pos r, const pos c) const ;

        //  moves the cursor to a position specified by row and coloumn, if position doesn't exist returns character at the end of screen
        Screen & move(const pos r, const pos c);
        

    private :
        pos height = 0;
        pos width = 0;
        pos cursor = 0;
        std::string contents;
};

//  validity of the position is checked based on, height implifies rows, so height >= r or if height is greater than specified coloumn should be lesser than or equal to width
inline char Screen::get(const pos r, const pos c) const {
    if( contents.size() < r * c){
        return -1;
    }else{
        return contents[r * width + c];
    }
}

inline Screen & Screen::move(const pos r, const pos c) {
    if( contents.size() < r * c){
        cursor = contents.size() - 1;     
    }else{
        cursor = r * width + c;
    }
    return *this;
}

