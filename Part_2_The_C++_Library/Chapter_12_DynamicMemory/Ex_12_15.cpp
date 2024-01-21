/************************************************************************************************************************************************************
 * @file Ex_12_15.cpp
 * @brief Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place of the end_connection function.
 * 
 * @date 2024-01-16
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

#include <iostream>
#include <memory>

struct Connection;
struct Destination;

Connection connect(destination *d_param);

int main(){
    Destination d;
    Connection new_connect = connect(&d)
    std::shared_ptr<Connection> *c_ptr(&new_connect, [](Connection *c){disconnect(*c)};);

    return 0;
}

