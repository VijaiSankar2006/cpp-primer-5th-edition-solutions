/*  Exercise 6.56: Call each element in the vector and print their result. */

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
    std::cout << "Enter two numbers : ";
    int num1, num2;
    std::cin >> num1 >> num2;

    for(std::vector<fpToOp>::size_type i = 0; i < fpvec.size(); ++i){
        std::cout << operation[i] << " of " << num1 << " " << num2 << " = "
                  << fpvec[i](num1, num2) << std::endl;       //  subscript operator fetches the function pointer at 
                                                              //  the specified index
        }

    return 0;
} 