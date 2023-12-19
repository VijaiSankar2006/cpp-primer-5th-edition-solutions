/*  Exercise 6.55: Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these
 *  functions in your vector from the previous exercise.  */

    #include <iostream>
    #include <vector>

    int addInt(int num1, int num2){
        return num1 + num2;
    }

    int subInt(int num1, int num2){
        return num1 - num2;
    }

    int mulInt(int num1, int num2){
        return num1 * num2;
    }

    int divInt(int num1, int num2){
        return num1/num2;
    }

    using fpToOp = int (*) (int, int );   // fpToOp is a pointer to function which takes two ints and return a int type

    int main(){
        std::vector<std::string> operation{"sum", "difference", "product", "division"};
        std::vector<fpToOp> fpvec{addInt, subInt, mulInt, divInt}; // fpvec is a vector of type fpToOp
        for( auto p : fpvec){
            std::cout << p <<  std::endl;   // pointer is converted to bool
        }

        return 0;
    } 