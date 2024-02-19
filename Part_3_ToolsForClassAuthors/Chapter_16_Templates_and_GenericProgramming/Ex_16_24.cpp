/************************************************************************************************************************************************************
 * @file Ex_16_24.cpp
 * @brief Exercise 16.24: Add a constructor that takes two iterators to your Blob template.
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include "BlobTemplate.cpp"
#include "BlobPtrTemplate.cpp"
#include <list>

template <typename T>
void print(Blob<T> &b) {
    for( auto iter = b.begin(); iter != b.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<std::string> svec{"alpha","beta","gamma"};
    std::list<std::string> slst{"delta","echo","friday"};
    Blob<std::string> b1(svec.begin(), svec.end());
    Blob<std::string> b2(slst.begin(), slst.end());
    int arr[] = {2,4,6,8,9,7,5,3,1};
    Blob<int> b3(std::begin(arr), std::end(arr));

    print(b1);
    print(b2);
    print(b3);
}