/************************************************************************************************************************************************************
 * @file Ex_16_26.cpp
 * @brief Exercise 16.26: Assuming NoDefault is a class that does not have a default constructor, can we explicitly 
 * instantiate vector<NoDefault>? If not, why not?
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * yes, we can explicitly instantiate vector<NoDefault> as it just instantiates an object of empty vector<NoDefault>, (ie)
 * the vector is just empty, no NoDefault object has been constructed yet.
 * 
 *************************************************************************************************************************************************************/
#include <iostream>
#include <vector>

class NoDefault {
    public :
        NoDefault(int n_) : n(n_) {}
        void print() {
            std::cout << n << std::endl;
        }
    private :
        int n;
};

int main() {
    std::vector<NoDefault> nvec;
    nvec.push_back(NoDefault(45));
    nvec[0].print();
}