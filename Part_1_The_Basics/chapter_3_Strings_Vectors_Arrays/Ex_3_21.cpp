/*  Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.   
 *  ############################################################################   */

//  ----------------------------------------------------------------------------------------------------------------------
/*  Exercise 3.16: Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your 
answers to that exercise were correct. If not, restudy§ 3.3.1 (p. 97) until you understand why you were wrong.  */
/*
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
int main(){
    vector<int> v1; 
    vector<int> v2(10);
    vector<int> v3(10, 42); 
    vector<int> v4{10};
    vector<int> v5{10, 42}; 
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    std::cout << "v1 : [size = "<< v1.size() << " ";
    for(auto beg = v1.cbegin(); beg != v1.cend(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "v2 : [size = "<< v2.size() << " ";
    for(auto beg = v2.cbegin(); beg != v2.cend(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "v3 : [size = "<< v3.size() << " ";
    for(auto beg = v3.cbegin(); beg != v3.cend(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "v4 : [size = "<< v4.size() << " ";
    for(auto beg = v4.cbegin(); beg != v4.cend(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "v5 : [size = "<< v5.size() << " ";
    for(auto beg = v5.cbegin(); beg != v5.cend(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "v6 : [size = "<< v6.size() << " ";
    for(auto beg = v6.cbegin(); beg != v6.cend(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "v7 : [size = "<< v7.size() << " ";
    for(auto beg = v7.cbegin(); beg != v7.cend(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << "]" << std::endl;
    
}
*/
//  -------------------------------------------------------------------------------------------------------------------

/*  Exercise 3.17: Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process
    the vector and change each word to uppercase.Print the transformed elements, eight words to a line. */
/*
#include <iostream>
#include <vector>
#include <string>

int main(){
    std::cout << "Enter the list of words : \n";
    std::string word;
    std::vector<std::string> strvec;
    while( std::cin >> word ){
        strvec.push_back(word);
    }

    for( auto beg = strvec.begin(); beg != strvec.end(); ++beg ){
        for( auto it = beg->begin(); it != beg->end(); ++it ){
            *it = toupper(*it);
        }
    }

    std::cout << std::endl;
    for( auto beg = strvec.begin(); beg != strvec.end(); ++beg){
        std::cout << *beg << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/
//  ----------------------------------------------------------------------------------------------------------------------
/*  Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your 
    program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last,
    and so on.  */

    #include <iostream>
    #include <vector>
    
    int main(){
        std::cout << "Enter a set of integers : \n";
        std::vector<int> ivec;
        int num;
        while( std::cin >> num ){
            ivec.push_back(num);
        }

        std::cout << std::endl;
        for( auto first = ivec.cbegin(), next = first + 1; next != ivec.cend(); ++first, ++next){
            std::cout << *first + *next << " ";
        }
        std::cout << std::endl;

        for( auto first = ivec.cbegin(), last = ivec.cend() - 1; first <= last; ++first, --last){
            std::cout << *first + *last << " ";
        }
        std::cout << std::endl;

        return 0;
    }
