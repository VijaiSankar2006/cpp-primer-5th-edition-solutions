/************************************************************************************************************************************************************
 * @file EX_16_3.cpp
 * @brief Exercise 16.3: Call your compare function on two Sales_data objects to see how your compiler handles errors 
 * during instantiation.
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>
#include "Sales_data_1.cpp"

template <typename T> inline
int compare(const T &v1, const T &v2) {
    //std::cout << "compare(" << v1 << ", " << v2 << ")" << std::endl;
    if (std::less<T>()(v1,v2)) return -1;
    if (std::less<T>()(v2,v1)) return 1;
    return 0;
}

int main(){
    std::cout << compare(Sales_data("c++ primer"), Sales_data("c++ primer")) << std::endl;
    return 0;
}

/************************************************************************************************************************************************************
 * @error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
 * 
 *************************************************************************************************************************************************************/
