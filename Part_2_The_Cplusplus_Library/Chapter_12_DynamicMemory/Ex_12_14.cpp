/************************************************************************************************************************************************************
 * @file Ex_12_14.cpp
 * @brief Exercise 12.14: Write your own version of a function that uses a shared_ptr to manage a connection.
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

void close_connection(Connection *c){
    disconnect(*c);
}

int main(){
    Destination d;
    Connection new_connect = connect(&d)
    std::shared_ptr<Connection> *c_ptr(&new_connect, close_connection);

    return 0;
}