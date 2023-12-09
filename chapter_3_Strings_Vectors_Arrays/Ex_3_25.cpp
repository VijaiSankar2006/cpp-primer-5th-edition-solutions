/*  Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts */

#include <iostream>
#include <vector>

int main(){
    std::vector<int> grades(11,0);
    std::cout << "Enter the grades of students : \n";
    int n;
    auto beg = grades.begin();
    while( std::cin >> n ){
        if( n >= 0 && n <= 100 ){   // checks whether the grade is correct
            ++*(beg + n/10);        // the iterator is moved to the respective element, then we dereference the value and we increment it   
        }                           // n = 41, beg + 41/10 = beg + 4 = 5 cluster that has counter for 40 - 49 grades
    }

    std::cout << "\nsummary of grades are : \n";
    for( auto beg = grades.begin(); beg != grades.end(); ++beg ){
        std::cout << *beg << " ";
    }
    std::cout << std::endl;

    return 0;
}