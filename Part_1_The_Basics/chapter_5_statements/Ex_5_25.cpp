/*  Exercise 5.25: Revise your program from the previous exercise to use a try block to catch the exception. The catch
 *  clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.*/

#include <iostream>
#include <stdexcept>
int main(){
    std::cout << "Enter two integers : ";
    int num1, num2;
    std::cin >> num1 >> num2;

    // code to handle division by zeor error
    // user will be prompted repeatedly untill a non-zero number is entered 
    do{
        try{
            if(!num2){
                throw std::domain_error("division by zero");
            }else{
                break;
            }
        }catch (std::domain_error err){
            std::cout<< err.what() << "\nEnter a non-zero second number : ";
        }  
        std::cin >> num2;  
    }while(1);
    
    std::cout << num1 << " / "<< num2 << " " << num1/num2 << std::endl;

    return 0;
}