/*  Exercise 3.16: Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your 
 *  answers to that exercise were correct. If not, restudy§ 3.3.1 (p. 97) until you understand why you were wrong   
 *  -------------------------------------------------------------------------------------------------------------------- */

/*  Exercise 3.13: How many elements are there in each of the following vectors? What are the values of the elements?
    (a) vector<int> v1; (b) vector<int> v2(10);
    (c) vector<int> v3(10, 42); (d) vector<int> v4{10};
    (e) vector<int> v5{10, 42}; (f) vector<string> v6{10};
    (g) vector<string> v7{10, "hi"};    */

#include <iostream>
#include <vector>
#include <string>

using std::vector;
int main(){
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<std::string> v6{10};
    vector<std::string> v7{10,"hi"};

    //  empty vector
    std::cout << "vector<int> v1 [size : " << v1.size() << "]" << std::endl;
    
    //  has ten elements with value 0
    std::cout << "vector<int> v2(10) [size : " << v2.size() << "] [values : ";
    for(auto n : v2){
        std::cout << n << " ";
    }
    std::cout << "]" << std::endl;

    //  has 10 elements with value 42
    std::cout << "vector<int> v3(10,42) [size : " << v3.size() << "] [values : ";
    for(auto n : v3 ){
        std::cout << n << " ";
    }
    std::cout << "]" << std::endl;

    //  has one element with a value 10
    std::cout << "vector<int> v4{10} [size : " << v4.size() << "] [values : ";
    for( auto n : v4){
        std::cout << n << " ";
    } 
    std::cout << "]" << std::endl;
    
    //  has two elements with values 10,42 respectively
    std::cout << "vector<int> v5{10,42} [size : " << v5.size() << "] [values : ";
    for( auto n : v5){
        std::cout << n << " ";
    }
    std::cout << "]" << std::endl;

    //  has 10 empty strings
    std::cout << "vector<string> v6{10}  [size : " << v6.size() << "] [values : ";
    for( auto str : v6 ){
        std::cout << str << " ";
    }
    std::cout << "]" << std::endl;

    //  has 10 elements of value "hi"
    std::cout << "vector<string> v7{10,\"hi\"}  [size : " << v7.size() << " ]  [values : ";
    for( auto str : v7){
        std::cout << str << " ";
    }  
    std::cout << "]" << std::endl;

    return 0;
}