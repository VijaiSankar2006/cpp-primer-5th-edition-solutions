/************************************************************************************************************************************************************
 * @file Ex_16_27.cpp
 * @brief Exercise 16.27: For each labeled statement explain what, if any, instantiations happen. If a template is 
 * instantiated, explain why; if not, explain why not.
 * 
 * template <typename T> class Stack { };
 * void f1(Stack<char>); // (a)
 * 
 * class Exercise {
 *      Stack<double> &rsd; // (b)
 *      Stack<int> si; // (c)
 * };
 * 
 * int main() {
 *      Stack<char> *sc; // (d)
 *      f1(*sc); // (e)
 *      int iObj = sizeof(Stack< string >); // (f)
 * }
 * 
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * template <typename T> class Stack { };  declarations doesn't require instantiation
 * void f1(Stack<char>); // (a)   //  declarations doesn't require instantiation
 * 
 * class Exercise {
 *      Stack<double> &rsd; // (b)   //  instantiations are not required for references and pointers as no memory is alloted for the object the reference refers
 *      Stack<int> si; // (c)        //  instantiates class Stack<int> 
 * };
 * 
 * int main() {
 *      Stack<char> *sc; // (d)      //  instantiations are not required for references and pointers
 *      f1(*sc); // (e)              //  instantiates Stack<char>
 *      int iObj = sizeof(Stack< string >); // (f)  //  instantiates class Stack<string>
 * }
 * 
 * 
 * //  reference for explantion https://stackoverflow.com/q/21598635  
 *************************************************************************************************************************************************************/
#include <iostream>
using namespace std;

template <typename T> class Stack { 
    typename T::this_doesnt_exist staticassert;   // as no type consists of a type named "this_doesn't exist", trying to create a object of it results in to compile time error
};

void f1(Stack<char>); // (a)  no compile error as no instantiation happens
class Exercise {
    Stack<double> &rsd; // (b)  no compile error as no instantiation happens, but compiler error generated as there is no constructor to initialise rsd
  //  Stack<int> si; // (c)  compile time error as Stack<int> is instantiated
};

int main() {
    Stack<char> *sc; // (d) no compiler error as no instantiation happens
  //  f1(*sc); // (e)  compiler error as instantiation happpens Stack<char>
  //  int iObj = sizeof(Stack< string >); // (f)  does't compile as instantiation happens Stack<string>
}
