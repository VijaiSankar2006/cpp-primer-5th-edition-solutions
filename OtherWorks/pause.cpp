/************************************************************************************************************************************************************
 * @file pause.cpp
 * @brief defintion of pause function
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/
#include <iostream> 
#include <thread>
#include <chrono>

void pause(size_t sec = 0){
    if(sec) {
        std::chrono::seconds time(sec);
        std::this_thread::sleep_for(time);
        return;
    }

    std::string str;
    getline(std::cin, str);
    return;
}