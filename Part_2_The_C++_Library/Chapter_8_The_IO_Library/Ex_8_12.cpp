/************************************************************************************************************************************************************
 * @file Ex_8_12.cpp
 * @brief Exercise 8.12: Why didn’t we use in-class initializers in PersonInfo?
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 *************************************************************************************************************************************************************/

/**
 * struct PersonInfo {
    string name;
    vector<string> phones;
};
*/

/**
 *  # PersonInfo is designed as an aggregate class as we are going to store data read from the cin, it doesn't
 *    need any in-class initialisers as there is no point for the objects to hold something by default 
*/