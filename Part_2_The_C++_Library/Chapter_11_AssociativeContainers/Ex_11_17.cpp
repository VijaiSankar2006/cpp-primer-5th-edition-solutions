/************************************************************************************************************************************************************
 * @file Ex_11_17.cpp
 * @brief Exercise 11.17: Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. 
 * Indicate whether each call is legal:
 *      copy(v.begin(), v.end(), inserter(c, c.end()));
 *      copy(v.begin(), v.end(), back_inserter(c));
 *      copy(c.begin(), c.end(), inserter(v, v.end()));
 *      copy(c.begin(), c.end(), back_inserter(v));
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
/**
c : multiset of strings 
v : vector of strings 
copy(v.begin(), v.end(), inserter(c, c.end()));   //  legal
    copies all the elements from the vector,v and writes to the multiset,c using insert_iterator returned from inserter(),
    inserter(c, c.end()), takes a reference to the multiset,c and the c.end() as the iter as position before which each element 
    needs to be inserted.
    But c is ordered multiset, as the position based insert operations are not supported, the insert_iterator returned by 
    inserter() calls insert member functin of c. every element added will be stored only in ordered fashion using element's '<' operator

copy(v.begin(), v.end(), back_inserter(c));  // illegal
    same as the previous, back_iserter(c) takes a reference to c and returns a insert_iterator which tries to call push_back() 
    to add elements.
        As c is a multiset, c has no member name push_back

copy(c.begin(), c.end(), inserter(v, v.end())); // legal
    copies all the elements from c and writes to v using the insert_iterator returned from inserter(v, v.end()) which calls
    insert member of v which inserts each element before v.end().

copy(c.begin(), c.end(), back_inserter(v));     // legal
    the insert_iterator returned from back_inserter(v) will call push_back() of v to add elements
*/

#include <set>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main()
{
    std::multiset<std::string> s { "1", "3","2","6","5" };
    std::vector<std::string> svec { "2", "4", "5" };
    std::copy(s.begin(), s.end(), std::back_inserter(svec));

    for (auto str : svec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    

}

